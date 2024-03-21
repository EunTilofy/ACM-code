#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int MN = 1e5 + 5;
int n;
ll a[MN], pr[MN], sf[MN];

#define ll long long
struct node2 {
    ll sm;
    ll pr;
    ll _pr;
    ll tag;
}t2[MN << 2];

struct node3 {
    ll sm;
    ll sf;
    ll _sf;
    ll tag;
}t3[MN << 2];

struct node1 {
    ll sm;
    int mx;
    int mxid;
}t1[MN << 2];

void up1(int k, int l, int r) {
    t1[k].sm = t1[k<<1].sm + t1[k<<1|1].sm;
    if(t1[k<<1].mx > t1[k<<1|1].mx) {
        t1[k].mx = t1[k<<1].mx;
        t1[k].mxid = t1[k<<1].mxid;
    }
    else {
        t1[k].mx = t1[k<<1|1].mx;
        t1[k].mxid = t1[k<<1|1].mxid;
    }
}

void up2(int k, int l, int r) {
    t2[k]._pr = min(t2[k<<1]._pr, t2[k<<1|1]._pr);
    t2[k].pr = max(t2[k<<1].pr, t2[k<<1|1].pr);
    t2[k].sm = t2[k<<1].sm + t2[k<<1|1].sm;
}

void up3(int k, int l, int r) {
    t3[k]._sf = min(t3[k<<1]._sf, t3[k<<1|1]._sf);
    t3[k].sf = max(t3[k<<1].sf, t3[k<<1|1].sf);
    t3[k].sm = t3[k<<1].sm + t3[k<<1|1].sm;
}

void down2(int k, int l, int r) {
    if(!t2[k].tag || l >= r) return ;
    t2[k<<1].tag = max(t2[k<<1].tag, t2[k].tag);
    t2[k<<1|1].tag = max(t2[k<<1|1].tag, t2[k].tag);
    t2[k<<1]._pr = t2[k<<1].pr = max(t2[k<<1].pr, t2[k<<1].tag);
    t2[k<<1|1]._pr = t2[k<<1|1].pr = max(t2[k<<1|1].pr, t2[k<<1|1].tag);
    int mid = (l + r) >> 1;
    t2[k<<1].sm = (mid - l + 1) * t2[k<<1].pr;
    t2[k<<1|1].sm = (r - mid) * t2[k<<1|1].pr;
    t2[k].tag = 0;
}

void down3(int k, int l, int r) {
    if(!t3[k].tag || l >= r) return ;
    t3[k<<1].tag = max(t3[k<<1].tag, t3[k].tag);
    t3[k<<1|1].tag = max(t3[k<<1|1].tag, t3[k].tag);
    t3[k<<1]._sf = t3[k<<1].sf = max(t3[k<<1].sf, t3[k<<1].tag);
    t3[k<<1|1]._sf = t3[k<<1|1].sf = max(t3[k<<1|1].sf, t3[k<<1|1].tag);
    int mid = (l + r) >> 1;
    t3[k<<1].sm = (mid - l + 1) * t3[k<<1].sf;
    t3[k<<1|1].sm = (r - mid) * t3[k<<1|1].sf;
    t3[k].tag = 0;
}

void build(int k, int l, int r) {
    if(l == r) {
        t1[k].mxid = l;
        t1[k].mx = t1[k].sm = a[l];
        t2[k]._pr = t2[k].pr = t2[k].sm = pr[l];
        t2[k].tag = t3[k].tag = 0;
        t3[k]._sf = t3[k].sf = t3[k].sm = sf[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1, l, mid);
    build(k<<1|1, mid+1, r);
    up1(k, l, r); up2(k, l, r); up3(k, l, r); 
}

void C1(int k, int l, int r, int a, int v) {
    if(l == r) {
        t1[k].mx += v;
        t1[k].sm += v;
        return;
    }
    int mid = (l + r) >> 1;
    if(a <= mid) C1(k<<1,l,mid,a,v);
    else C1(k<<1|1,mid+1,r,a,v);
    up1(k,l,r);
}

ll q2(int k, int l, int r, int a, int b) {
    if(a > b) return 0;
    if(l == a && r == b) {
        return t2[k].sm;
    }
    down2(k, l, r);
    int mid = (l + r) >> 1;
    if(b <= mid) return q2(k<<1,l,mid,a,b);
    if(a > mid) return q2(k<<1|1,mid+1,r,a,b);
    return q2(k<<1,l,mid,a,mid)+q2(k<<1|1,mid+1,r,mid+1,b);
}
ll q3(int k, int l, int r, int a, int b) {
    if(a > b) return 0;
    if(l == a && r == b) {
        return t3[k].sm;
    }
    down3(k, l, r);
    int mid = (l + r) >> 1;
    if(b <= mid) return q3(k<<1,l,mid,a,b);
    if(a > mid) return q3(k<<1|1,mid+1,r,a,b);
    return q3(k<<1,l,mid,a,mid)+q3(k<<1|1,mid+1,r,mid+1,b);
}

void C2(int k, int l, int r, int a, int b, int v) {
    if(l == a && r == b) {
        if(t2[k].pr < v) {
            t2[k]._pr =t2[k].pr = t2[k].tag = v;
            t2[k].sm = (r - l + 1) * t2[k].pr;
        } else if(t2[k]._pr <= v) {
            int mid = (l + r) >> 1;
            C2(k<<1, l, mid, a, mid, v);
            C2(k<<1|1, mid+1, r, mid+1, b, v);
            up2(k, l, r);
        }
        return;
    }
    down2(k, l, r);
    int mid = (l + r) >> 1;
    if(b <= mid) C2(k<<1,l,mid,a,b,v);
    else if(a > mid) C2(k<<1|1,mid+1,r,a,b,v);
    else C2(k<<1,l,mid,a,mid,v), C2(k<<1|1,mid+1,r,mid+1,b,v);
    up2(k, l, r);
}
void C3(int k, int l, int r, int a, int b, int v) {
    if(l == a && r == b) {
        if(t3[k].sf < v) {
            t3[k]._sf = t3[k].sf = t3[k].tag = v;
            t3[k].sm = (r - l + 1) * t3[k].sf;
        } else if(t3[k]._sf <= v) {
            int mid = (l + r) >> 1;
            C3(k<<1, l, mid, a, mid, v);
            C3(k<<1|1, mid+1, r, mid+1, b, v);
            up3(k, l, r);
        }
        return;
    }
    down2(k, l, r);
    int mid = (l + r) >> 1;
    if(b <= mid) C3(k<<1,l,mid,a,b,v);
    else if(a > mid) C3(k<<1|1,mid+1,r,a,b,v);
    else C3(k<<1,l,mid,a,mid,v), C3(k<<1|1,mid+1,r,mid+1,b,v);
    up3(k, l, r);
}

ll que() {
    int mxid = t1[1].mxid;
    // cerr << "q2 : " <<  q2(1, 1, n, 1, mxid) << "\n" << "q3 : " << q3(1, 1, n, mxid+1, n) << "\n";
    return -t1[1].sm + q2(1, 1, n, 1, mxid) + (mxid==n?0:q3(1, 1, n, mxid+1, n));
}

const int M=1e6;
void solve() {
    n=1e5;
    for(int i = 1; i <= n; ++i) a[i]=rand()%M;
    pr[0] = sf[n + 1] = 0;
    for(int i = 1; i <= n; ++i) pr[i] = max(pr[i-1], a[i]);
    for(int i = n; i; --i) sf[i] = max(sf[i+1], a[i]);
    build(1, 1, n);
    int q; q=1e5;
    while(q--) {
        int x, y;
        x=rand()%n+1;
        y=rand()%M;
         a[x] += y;
        // cerr << "C1\n";
        C1(1, 1, n, x, y);
        // cerr << "C1 :" << t1[1].mxid << " " << t1[1].sm << "\n";
        // cerr << "C2 : " << x << " " << n << " " << a[x] << "\n";
        C2(1, 1, n, x, n, a[x]);
        // cerr << "C3\n";
        C3(1, 1, n, 1, x, a[x]);
        cout << que() << "\n";
    }
}

signed main(){
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    
    T=10;
    while(T--) solve();
    return 0;
}


/*
2
6
1 2 3 4 5 6
2
1 2
3 3
5
100 10 1 10 100
1
3 100
*/