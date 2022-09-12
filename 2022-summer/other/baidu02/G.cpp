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
const int MN = 200000 + 5;
int n, m, k;
int f[MN], g[MN];
struct node{ pii a;int id;}p[MN];
int ans;
int fac[MN], inv[MN];
bool cmp(node x, node y) {return x.a < y.a;}
int C(int x, int y) {return Mul(fac[x], Mul(inv[y], inv[x - y]));}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    n = read(); m = read(); k = read();
    REP(i, 1, k + 1) {
        p[i].a.fi = read(), p[i].a.se = read();
        p[i].id = i;
    }
    std::sort(p + 1, p + k + 1, cmp);
    fac[0] = inv[0] = inv[1] = 1;
    REP(i, 1, 200001) fac[i] = Mul(fac[i - 1], i);
    REP(i, 2, 200001) inv[i] = Mul((mod - mod / i), inv[mod % i]);
    REP(i, 1, 200001) inv[i] = Mul(inv[i - 1], inv[i]);
    REP(i, 1, k + 1) {
        f[p[i].id] = C(p[i].a.fi + p[i].a.se, p[i].a.fi);
    }
    REP(i, 1, k + 1) {
        REP(j, i + 1, k + 1) {
            if(p[j].a.fi >= p[i].a.fi && p[j].a.se >= p[i].a.se) {
                f[p[j].id] = Add(f[p[j].id], Mul(mod - f[p[i].id], C(p[j].a.fi - p[i].a.fi + p[j].a.se - p[i].a.se, p[j].a.fi - p[i].a.fi)));
            }
        }
    }

    REP(i, 1, k + 1) {
        p[i].a.fi = n - p[i].a.fi;
        p[i].a.se = m - p[i].a.se;
        g[p[i].id] = C(p[i].a.fi + p[i].a.se, p[i].a.fi);
    }
    std::sort(p + 1, p + k + 1, cmp);
    REP(i, 1, k + 1) {
        REP(j, i + 1, k + 1) {
            if(p[j].a.fi >= p[i].a.fi && p[j].a.se >= p[i].a.se) {
                g[p[j].id] = Add(g[p[j].id], Mul(mod - g[p[i].id], C(p[j].a.fi - p[i].a.fi + p[j].a.se - p[i].a.se, p[j].a.fi - p[i].a.fi)));
            }
        }
    }

    REP(i, 1, k + 1) REP(j, 1, k + 1) if(i != j) {
        ans = Add(ans, Mul(f[i], g[j]));
    }
    printf("%d\n", ans);
    return 0;
}