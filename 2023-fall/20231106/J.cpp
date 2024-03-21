#include<bits/stdc++.h>
using namespace std;
const int MN = 805;
const int S = 801, T = 802;
typedef long long ll;
const ll inf = 1e18;
// class Flow {
//     bool vis[MN], inq[MN];
//     ll dis[MN];
//     queue<int> q;
//     struct edge{int to, w, c, nex;}e[MN*MN*2+MN*5];
//     int cur[MN], hr[MN], en;
    
//     bool spfa() {
//         for (int i = 1; i <= T; ++i) cur[i] = hr[i], inq[i] = 0, dis[i] = -inf;
//         for(dis[S]=0, inq[S]=1, q.push(S); !q.empty(); ) {
//             int u = q.front(); q.pop(); inq[u] = 0;
//             for(int i = hr[u]; i; i = e[i].nex)
//                 if(dis[e[i].to]<dis[u]+e[i].c&&e[i].w) {
//                     dis[e[i].to] = dis[u] + e[i].c;
//                     if(!inq[e[i].to]) inq[e[i].to] = 1, q.push(e[i].to);
//                 }
//         }
//         return dis[T]>-inf;
//     }
//     ll dfs(int x, ll f) {
//         if(x == T || !f) return f; vis[x] = 1;
//         ll w, used = 0;
//         for(int &i=cur[x];i;i=e[i].nex)
//         if(dis[e[i].to]==dis[x]+e[i].c&&e[i].w&&!vis[e[i].to]) {
//             w=dfs(e[i].to, min(f-used, (ll)e[i].w));
//             e[i].w-=w; e[i^1].w+=w; used += w;
//             if(used == f) break;
//         }
//         vis[x] = 0; return used;
//     }
//     public:
//         Flow() {en = 1;}
//         void ins(int x, int y, int w, int c) {
//             e[++en] = (edge){y, w, c, hr[x]}; hr[x] = en;
//             e[++en] = (edge){x, 0, -c, hr[y]}; hr[y] = en;
//         }
//         ll Ans() {
//             ll r = 0;
//             while(spfa()) {
//                 // cerr << "!" << "\n";
//                 r += dfs(S, inf)*dis[T];
//             }
//             return r;
//         }
// }flow;

namespace KM {
    const int N = 405;
    const ll inf = 1e16;
    int lk[N], kl[N], pre[N], q[N], n, h, t;
    ll sl[N], e[N][N], lx[N], ly[N];
    bool edx[N], edy[N];
    bool ck(int v) {
        if(edy[v]=1,kl[v]) return edx[q[++t]=kl[v]]=1;
        while(v) swap(v, lk[kl[v]=pre[v]]);
        return 0;
    }
    void bfs(int u) {
        fill_n(sl+1, n, inf);
        memset(edx+1, 0, n*sizeof edx[0]);
        memset(edy+1, 0, n*sizeof edy[0]);
        q[h=t=1]=u; edx[u]=1;
        while(1) {
            while(h<=t) {
                int u=q[h++], v;
                ll d;
                for(v=1;v<=n;v++) if(!edy[v]&&sl[v]>=(d=lx[u]+ly[v]-e[u][v]))
                    if(pre[v]=u, d) sl[v]=d; else if(!ck(v)) return ;
            }
            int i;
            ll m=inf;
            for(i=1; i<=n; ++i) if(!edy[i]) m=min(m,sl[i]);
            for(i=1; i<=n; ++i) {
                if(edx[i]) lx[i]-=m;
                if(edy[i]) ly[i]+=m; else sl[i]-=m;
            }
            for(i=1;i<=n;++i) if(!edy[i]&&!sl[i]&&!ck(i)) return;
        }
    }
    template<typename TT> ll match(int N, const vector<tuple<int,int,TT>> &edges) {
        int i;n=N;
        memset(lk+1, 0, n*sizeof lk[0]);
        memset(kl+1, 0, n*sizeof kl[0]);
        memset(ly+1, 0, n*sizeof ly[0]);
        for(i=1;i<=n;++i) fill_n(e[i]+1, n, 0);
        for(auto [u,v,w]:edges) e[u][v]=max(e[u][v], (ll)w);
        for(i=1;i<=n;++i) lx[i]=*max_element(e[i]+1,e[i]+n+1);
        for(i=1;i<=n;++i) bfs(i);
        ll r=0;
        for(i=1;i<=n;++i) r+=e[i][lk[i]];
        return r;
    }
}

ll n, b[405], c[405];
pair<ll,ll> a[405];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].first;
    for(int i = 1; i <= n; ++i) cin >> a[i].second;
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; ++i) a[i].second += a[i-1].second;
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) cin >> c[i];
    vector<tuple<int,int,long long>> edges;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            int id = (lower_bound(a+1, a+n+1, make_pair(b[i]+c[j], 0ll)) - a);
            // cerr << i << " " << j << " " << a[id-1].second << "\n";
            if(id>=1) edges.push_back({i,j,a[id-1].second});
        }
    cout << KM::match<ll>(n, edges);
}