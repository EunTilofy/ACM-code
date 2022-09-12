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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 501;
int o, n, m, k, q, x, y;
int t[MN][MN], f[MN][MN][MN];
int g[MN][MN][MN];
signed main() {
    n = read(), m = read(); k = read(); q = read();
    REP(i, 1, n + 1) REP(j, 1, m + 1) t[i][j] = 2000000000;
    REP(_, 0, q) {
        x = read(); y = read();
        t[x][y] = min(t[x][y], read());
    }
    o = min(n, m);
    REP(i, 1, n + 1) {
        REP(j, 1, m + 1) f[i][j][j] = t[i][j];
        REP(len, 1, o) REP(j, 1, m - len + 1) {
            f[i][j][j + len] = max(f[i][j][j + len - 1], f[i][j + 1][j + len]); 
        }
    }
    REP(j, 1, m + 1) {
        REP(i, 1, n + 1) g[j][i][i] = t[i][j];
        REP(len, 1, o) REP(i, 1, n - len + 1) g[j][i][i + len] = max(g[j][i][i + len - 1], g[j][i + 1][i + len]); 
    }
    int ans = 2000000000;
    REP(S, k, o + 1) {
        REP(i, 1, n - S + 2) REP(j, 1, m - S + 2) { 
            ans = min(ans, max(max(f[i][j][j + S - 1], f[i + S - 1][j][j + S - 1]),
            max(g[j][i][i + S - 1], g[j + S - 1][i][i + S - 1])));
        }
    }
    if(ans > 1000000000) puts("-1");
    else printf("%d\n", ans);
    return 0;
}