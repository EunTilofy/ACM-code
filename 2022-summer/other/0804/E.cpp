#include<bits/stdc++.h>
#define ll long long
#define db double
#define LL __int128
#define DB __float128
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1<<19;
struct node{
    long long pre, suf, val, len, ans, l, r;
}t[MN<<2];
long long ans[1<<18];
void pushup(int k) {
    t[k].pre = max(t[t[k].l].pre, t[t[k].r].pre+t[t[k].l].val);
    t[k].suf = max(t[t[k].l].suf+t[t[k].r].val, t[t[k].r].suf);
    t[k].val = t[t[k].l].val+t[t[k].r].val;
    t[k].ans = max(t[t[k].l].ans, max(t[t[k].r].ans, t[t[k].l].suf+t[t[k].r].pre));
    t[k].ans = max(t[k].ans, max(t[k].suf, t[k].pre));
}
void build(int k, int l, int r) {
    if(l == r) {
        t[k].val = read();
        t[k].suf = t[k].pre = t[k].ans = max(0ll, t[k].val);
        t[k].len = 1;
        return;
    }
    int mid = (l + r) >>1;
    build(t[k].l = (k<<1),l,mid);
    build(t[k].r = (k<<1|1), mid+1, r);
    t[k].len = t[k<<1].len * 2;
    pushup(k);
}
void upd(int k, int l, int r, int m) {
    if(t[k].len == m*2) {
        // printf("!");
        // printf("%lld\n", t[k].ans);
        swap(t[k].l, t[k].r);
        pushup(k);
        return;
    }
    int mid = (l + r) >>1;
    upd(t[k].l, l, mid, m);
    upd(t[k].r, mid+1, r, m);
    pushup(k);
}
void iter(int k, int l, int r) {
    if(l == r) {printf("%lld ", t[k].val);return;}
    int mid = (l + r) >> 1;
    iter(t[k].l,l,mid);
    iter(t[k].r,mid+1,r);
}
int main() {
    int n = read();
    n = 1 << n;
    build(1, 1, n);
    int q = read();
    // printf("%lld\n", t[1].ans);
    while(q--) {
        int m = read();
        m = 1<<m;
        upd(1,1,n,m);
        printf("%lld\n", t[1].ans);
        // iter(1,1,n);puts("");
    }
    return 0;
}