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
const int MN = 1e6 + 5;
int a[MN], b[MN], c[MN], n, m;
vector<pii> G[MN];
void dfs(int x) {
    REP(i, 0, G[x].size()) dfs(G[x][i].fi);
    if(G[x].size() == 0) return;
    int SUM = 0;
    c[x] = a[x];
    REP(i, 0, G[x].size()) {
        int y = G[x][i].fi, q = G[x][i].se;
        SUM = Add(SUM, q);
        c[x] = Add(c[x], q);
        c[x] = Add(c[x], Mul(c[y], q)); 
    }
    c[x] = Mul(c[x], qpow(SUM, mod - 2));
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    n = read();
    REP(i, 1, n + 1) a[i] = read();
    REP(i, 2, n + 1) {
        b[i] = read();
        G[b[i]].pb(mkp(i, read()));
    }
    dfs(1);
    printf("%d\n", c[1]);
    return 0;
}