#include<bits/stdc++.h>
#define ll long long
#define int long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
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
#define S 0
#define T 805
#define O 803
const int N = 3e5 + 5;
const ll inf = 1000000000000000;
class Flow {
    bool vis[N], inq[N];
    ll dis[N]; queue<int> q;
    struct edge{int to, w, c, nex;}e[N * 10]; int cur[N], hr[N], en;
    bool spfa() {
        for(int i = S; i <= T; ++i) cur[i] = hr[i], inq[i] = 0, dis[i] = inf;
        for(dis[S] = 0, inq[S] = 1, q.push(S); !q.empty();) {
            int u = q.front(); q.pop(), inq[u] = 0;
            for(int i = hr[u]; i; i = e[i].nex) if(dis[e[i].to] > dis[u] + e[i].c && e[i].w) {
                dis[e[i].to] = dis[u] + e[i].c;
                if(!inq[e[i].to]) inq[e[i].to] = 1, q.push(e[i].to);
            }
        }
        return dis[T] < inf;
    }
    int dfs(int x, int f) {
        if(x == T || !f) return f;
        vis[x] = 1;
        int w, used = 0;
        for(int &i = cur[x]; i; i = e[i].nex) 
            if(dis[e[i].to] == dis[x] + e[i].c && e[i].w && !vis[e[i].to]) {
                w = dfs(e[i].to, min(f - used, e[i].w));
                e[i].w -= w; e[i ^ 1].w += w; used += w;
                if(used == f) break;
            }
        vis[x] = 0; return used;
    }
    public:
        void init() {
            en = 1;
            memset(hr, 0, sizeof hr);
        }
        void ins(int x, int y, int w, int c) {
            // dbg1(x); dbg1(y); dbg1(w); dbg2(c);
            e[++en] = (edge){y, w, c, hr[x]}; hr[x] = en;
            e[++en] = (edge){x, 0, -c, hr[y]}; hr[y] = en;
        }
        ll Ans() {
            ll r = 0; 
            while(spfa()) r += dfs(S, inf) * dis[T]; 
            return r;
        }
}fl;
const int MN = 205;
int av[MN], bv[MN], cv[MN];
int M;
int cal(int x, int y) {
    return 1ll * (x + y) * (x ^ y) % M;
}
signed main() {
    // freopen("B.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int cas = read();
    while(cas --) {
        int n = read(); int m = read();
        M = read();
        fl.init();
        REP(i, 1, n + 1) av[i] = read();
        REP(i, 1, n + 1) bv[i] = read();
        REP(i, 1, n + 1) cv[i] = read();
        fl.ins(S, O, m, 0);
        REP(i, 1, n + 1) fl.ins(O, i, 1, 0);
        REP(i, 1, n + 1) REP(j, 1, n + 1) {
            fl.ins(i, j + n, 1, -cal(cv[i], av[j]));
        }
        REP(i, 1, n + 1) fl.ins(i + n, i + n + n + n, 1, 0);
        REP(i, 1, n + 1) REP(j, 1, n + 1) {
            fl.ins(i + n + n + n, j + n + n, 1, -cal(av[i], bv[j]));
        }
        REP(i, 1, n + 1) fl.ins(i + n + n, T, 1, 0);
        printf("%lld\n", -fl.Ans());
    }
    return 0;
}