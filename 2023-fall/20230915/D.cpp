#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MN = 2e5+5;
int n, m, K, C, D;
long long a[MN], v1[MN], n1, v2[MN], n2;

struct tree{
    int tot,rt[MN],L,R;
    int t[MN*20],ls[MN*20],rs[MN*20];
    tree():tot(0),L(1){
        memset(t, 0, sizeof t);
    }
    void build(int &o, int l, int r, int v, int add) {
        if(!o) o=++tot;
        else {
            ++tot;
            t[tot]=t[o];ls[tot]=ls[o];rs[tot]=rs[o];o=tot;
        }
        if(l==r){t[tot]+=add;return;}
        else{
            int mid=(l+r)>>1;
            if(v<=mid)build(ls[o],l,mid,v,add);
            else build(rs[o],mid+1,r,v,add);
            t[o]=t[ls[o]]+t[rs[o]];
        }
    }
    int que(int rt1, int rt2, int l, int r, int a, int b) {
        if(l == a && r == b) {
            return t[rt2] - t[rt1];
        }
        else {
            int mid=(l+r)>>1;
            if(b<=mid){
                return que(ls[rt1],ls[rt2],l,mid,a,b);
            }
            else if(a>mid){
                return que(rs[rt1],rs[rt2],mid+1,r,a,b);
            }
            return que(ls[rt1],ls[rt2],l,mid,a,mid)+que(rs[rt1],rs[rt2],mid+1,r,mid+1,b);
        }
    }
    int get(int l, int r, int v) {
        return que(rt[l-1], rt[r], L, R, v, R);
    }
}t1,t2;
int Val(long long *aa, int n, long long val) {
    if(aa[n]<val) return n+1;
    return lower_bound(aa+1,aa+n+1,val)-aa;
}
void init() {
    sort(v1+1, v1+n+1);
    n1=unique(v1+1, v1+n+1)-v1-1;
    sort(v2+1, v2+n+1);
    n2=unique(v2+1, v2+n+1)-v2-1;
    t1.R=n1+1;
    t2.R=n2+1;
    for(int i=1;i<=n;++i){
        t1.rt[i]=t1.rt[i-1];
        t1.build(t1.rt[i],t1.L,t1.R,Val(v1,n1,a[i]),1);
        t2.rt[i]=t2.rt[i-1];
        t2.build(t2.rt[i],t2.L,t2.R,Val(v2,n2,a[i]+(ll)D*i),1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> K >> m >> C >> D;
    for(int i = 1; i <= n; ++i) cin >> a[i], v1[i] = a[i], v2[i]=a[i]+(ll)D*i;

    init();
    long long Ans = 0;
    for(int i = 1; i + m - 1 <= n; ++i) {
        int L = i, R = i + m - 1;
        long long ans = 0;
        long long l = 1, r = 200010000000000LL;
        while(l <= r) {
            long long mid = (l + r) >> 1;
            int vv1 = Val(v1,n1,mid);
            int vv2 = Val(v2,n2,mid+(ll)D*i-C);
            if(t1.get(1,L-1,vv1)+t1.get(R+1,n,vv1)+t2.get(L,R,vv2)>=K) ans=mid,l=mid+1;
            else r=mid-1;
        }
        Ans = max(Ans, ans);
    }
    cout << Ans << "\n";
}