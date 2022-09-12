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
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN], d[MN], n, m;
struct edge{
    int x, y;
    long long w;
    bool operator < (const edge&o) const{
        return w < o.w;
    }
}e[9000005], t[MN]; int tt, ttt;
ll sqr(int x) {return 1ll * x * x;}
int f[MN];
int getf(int x) {return x == f[x] ? x : f[x] = getf(f[x]);}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    n = read();
    m = read();
    REP(i, 0, n - m) d[i + 1] = read();
    REP(i, 1, n + 1) a[i] = read(), b[i] = read(), c[i] = read();
    REP(i, 1, n + 1) REP(j, i + 1, n + 1) {
        ++tt;
        e[tt].x = i; e[tt].y = j;
        e[tt].w = sqr(a[i] - a[j]) + sqr(b[i] - b[j]) + sqr(c[i] - c[j]);
    }
    std::sort(e + 1, e + tt + 1);
    REP(i, 1, n + 1) f[i] = i;
    REP(i, 1, tt + 1) {
        if(ttt == n - 1) break;
        int x = e[i].x, y = e[i].y;
        if(getf(x) != getf(y)) {
            x = getf(x); y = getf(y);
            f[x] = y;
            t[++ttt] = e[i];
        }
    }
    long long ans = 0;
    // REP(i, 1, n - k)
    return 0;
}