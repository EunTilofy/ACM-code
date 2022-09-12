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
#define P 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 2e6 + 5;
int a[MN], b[MN], c[MN];
struct graph {
    int n, m, s;
    std::vector<int> f, step, dfn, low, st, col;
    std::vector<bool> in, vis;
    std::vector<std::vector<int> > G, G2;
    std::vector<std::vector<int> > node;
    int BL, top, dind;
    bool ANS_win;
    int STEP;
    void tj(int x) {
        low[x] = dfn[x] = ++dind; in[st[top++] = x] = 1;
        reg int i;
        REP(i, 0, G[x].size()) 
            if(!dfn[G[x][i]]) tj(G[x][i]), low[x] = min(low[x], low[G[x][i]]);
            else if(in[G[x][i]]) low[x] = min(low[x], dfn[G[x][i]]);
        if(dfn[x] == low[x])
            for(++BL; st[top]^x; in[st[--top]] = 0) col[st[top - 1]] = BL;
    }
    std::set<pii> mp;
    void dfs(int x) {
        vis[x] = 1;
        REP(i, 0, G2[x].size()) if(!vis[G2[x][i]]) dfs(G2[x][i]);
        if(node[x].size() == 1) {
            //xxx
        }
        else {
            //xxx
        }
    }
    void init() {
        G.clear();f.clear();step.clear();
        n = read();m = read();s = read();
        f.resize(n + 1); step.resize(n + 1); G.resize(n + 1);
        dfn.resize(n + 1); st.resize(n + 1); col.resize(n + 1);
        in.resize(n + 1);
        REP(i, 0, m) {
            int x = read(); int y = read();
            G[x].pb(y);
        }
        REP(i, 1, n + 1) if(!dfn[i]) tj(i); 
        node.resize(BL + 1);
        REP(i, 1, n + 1) node[col[i]].pb(i);
        mp.clear();G2.clear();G2.resize(BL + 1);
        REP(i, 1, n + 1) REP(j, 0, G[i].size()) {
            int x = col[i];
            int y = col[j];
            if(!mp.count(mkp(x, y))) {
                mp.insert(mkp(x, y));
                G2[x].pb(y);
            }
        }
        vis.resize(BL + 1);
        dfs(col[s]);
    }
}gr[MN]; int num;
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    num = read();
    REP(i, 1, num + 1) gr[i].init();

    return 0;
}