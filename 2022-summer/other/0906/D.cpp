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
#define inf 0x3f3f3f3f
#define infL 0x3f3f3f3f3f3f3f3f
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
int a[MN], b[MN], c[MN], n, m;
std::vector<pii> G[MN];
std::pair<int, int> ed[MN];

bool vis[MN];
bool Find[MN];
int fa[MN];
void dfs(int x, int f) {
    vis[x] = 1;
    fa[x] = f;
    REP(i, 0, G[x].size()) {
        int y = G[x][i].fi;
        if(y == f) continue;
        if(vis[y]) Find[G[x][i].se] = 1;
        else dfs(y, x);
    }
}

typedef std::mt19937  Random_mt19937;

signed main() {
    Random_mt19937  rnd(time(0));
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        n = read(), m = read();
        REP(i, 1, n + 1) G[i].clear();
        REP(i, 1, m + 1) {
            int x = read();
            int y = read();
            G[x].pb(mkp(y, i));
            G[y].pb(mkp(x, i));
            ed[i] = mkp(x, y);
        }
        // if(m == n - 1) {
        //     REP(i, 1, m + 1) printf("0");
        //     puts("");
        // }
        // if(m == n) {
        
        while(1) {
            REP(i, 1, n + 1) vis[i] = 0;
            REP(i, 1, m + 1) Find[i] = 0;
            dfs(1 + rnd() % n, 0);
            if(m == n + 2) {
                int all = 0;
                std::vector<int> nm;nm.clear();
                REP(i, 1, m + 1) {
                    if(Find[i]) {
                        all ^= ed[i].fi;
                        all ^= ed[i].se;
                        nm.pb(ed[i].fi);
                        nm.pb(ed[i].se);
                    }
                }
                if(all != 0) break;
                std::sort(nm.begin(), nm.end());
                if(nm[0] == nm[1] && nm[2] == nm[3] && nm[4] == nm[5]);
                else break;
            }
            else break;
        }

            REP(i, 1, m + 1) printf(Find[i] ? "0" : "1");
            puts("");
        // }
        // if(m == n + 1) {

        // }
        // if(m == n + 2) {

        // }
    }
    return 0;
}