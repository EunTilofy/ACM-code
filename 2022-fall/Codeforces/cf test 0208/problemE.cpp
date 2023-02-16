#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
const int MN = 2e5 + 110;
int a[MN], mx[MN<<2], mn[MN<<2],mk[MN<<2];
void pu(int k){mx[k]=max(mx[k<<1],mx[k<<1|1]);mn[k]=min(mn[k<<1],mn[k<<1|1]);mk[k]=-1;}
void build(int k, int l, int r) {
    if(l == r) {
        mx[k] = 0;
        mn[k] = 0;
        mk[k] = -1;
        return;
    }
    int mid = (l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    pu(k);
}
void pd(int k,int l, int r) {
    if(mk[k]!=-1&&l!=r) {
        mk[k<<1]=mk[k<<1|1]=mx[k<<1]=mn[k<<1]=mx[k<<1|1]=mn[k<<1|1]=mk[k];
        mk[k] = -1;
    }
}
int qmx(int k, int l, int r, int a, int b){
    if(l==a&&r==b){return mx[k];}
    pd(k,l,r); int mid=(l+r)>>1;
    if(b<=mid)return qmx(k<<1,l,mid,a,b);
    else if(a>mid) return qmx(k<<1|1,mid+1,r,a,b);
    return max(qmx(k<<1,l,mid,a,mid),qmx(k<<1|1,mid+1,r,mid+1,b)); 
}
int qmn(int k, int l, int r, int a, int b){
    if(l==a&&r==b){return mn[k];}
    pd(k,l,r); int mid=(l+r)>>1;
    if(b<=mid)return qmn(k<<1,l,mid,a,b);
    else if(a>mid) return qmn(k<<1|1,mid+1,r,a,b);
    return min(qmn(k<<1,l,mid,a,mid),qmn(k<<1|1,mid+1,r,mid+1,b)); 
}
void cover(int k, int l, int r, int a, int b, int val) {
    if(l==a&&r==b){mx[k]=mn[k]=mk[k]=val;return;}
    pd(k,l,r); int mid=(l+r)>>1;
    if(b<=mid) cover(k<<1,l,mid,a,b,val);
    else if(a>mid) cover(k<<1|1,mid+1,r,a,b,val);
    else cover(k<<1,l,mid,a,mid,val),cover(k<<1|1,mid+1,r,mid+1,b,val);
    pu(k);
}
void Add(int k, int l, int r, int a, int val) {
    if(l==r) {
        mn[k]=mx[k]=mn[k]+val;
        return;
    }
    int mid=(l+r)>>1;
    if(a<=mid) Add(k<<1,l,mid,a,val);
    else Add(k<<1|1,mid+1,r,a,val);
    pu(k);
}
void add(int pos, int N, int m) {
    int l = pos, r = N-1, fd = N;
    while(l<=r) {
        int mid = (l+r)>>1;
        if(qmn(1,1,N,pos,mid)>=m-1) l=mid+1;
        else fd=mid, r=mid-1;
    }
    if(fd>pos) cover(1,1,N,pos,fd-1,0);
    Add(1,1,N,fd,1);
}
void dec(int pos, int N, int m) {
    int l = pos, r = N-1, fd = N;
    while(l<=r) {
        int mid = (l+r)>>1;
        if(qmx(1,1,N,pos,mid)<=0) l=mid+1;
        else fd=mid, r=mid-1;
    }
    if(fd>pos) cover(1,1,N,pos,fd-1,m-1);
    Add(1,1,N,fd,-1);
}
int get(int N) {
    int l=2,r=N,fd=1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(qmx(1,1,N,mid,N)>0) fd=mid,l=mid+1;
        else r=mid-1;
    }
    return fd+(fd>1?qmx(1,1,N,1,fd-1)>0:0);
}
void solve(){
	int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];    
    }
    int N = n + 100;
    build(1, 1, N);
    for(int i = 1; i <= n; ++i) add(a[i],N,m);
    // cout << get(N) << endl;
    while(q--) {
        int pos;
        cin >> pos;
        dec(a[pos],N,m);
        cin >> a[pos];
        add(a[pos],N,m);
        cout << get(N) << endl;
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}