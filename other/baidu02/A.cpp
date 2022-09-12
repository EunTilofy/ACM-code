#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e5 + 5;
int a[MN], n, m, x;
struct node {
    int a[21];
    int sum, num;
}t[MN<<2];
bool cmp(int x, int y){return x > y;}
node merge(node u, node v) {
    node ret;
    // dbg1(u.num); dbg2(v.num);
    REP(i, 1, u.num + 1) ret.a[i] = u.a[i];
    // dbg3(!!!);
    REP(i, 1, v.num + 1) ret.a[i + u.num] = v.a[i];
    ret.num = u.num + v.num;
    std::sort(ret.a + 1, ret.a + ret.num + 1, cmp);
    ret.num = min(ret.num, m);
    ret.sum = 0;
    REP(i, 1, ret.num + 1) ret.sum += ret.a[i];
    return ret;
}
void build(int k, int l, int r) {
    if(l == r) {
        t[k].sum = t[k].a[1] = a[l];
        t[k].num = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(k<<1, l, mid); build(k<<1|1, mid + 1, r);
    // dbg1(l); dbg2(r);
    t[k] = merge(t[k<<1], t[k<<1|1]);
    // dbg2(t[k].num);
}
node get(int k, int l, int r, int a, int b) {
    if(l == a && r == b) return t[k];
    int mid = (l + r) >> 1;
    if(b <= mid) return get(k<<1,l,mid,a,b);
    if(a > mid) return get(k<<1|1,mid+1,r,a,b);
    return merge(get(k<<1,l,mid,a,mid),get(k<<1|1,mid+1,r,mid+1,b));
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    n = read();int q = read();
    m = read();x = read();
    REP(i, 1, n + 1) {
        a[i] = read();
    }
    build(1, 1, n);
    while(q--) {
        int l = read();
        int r = read();
        puts(get(1, 1, n, l, r).sum >= x ? "Y" : "N");
    }
    return 0;
}
