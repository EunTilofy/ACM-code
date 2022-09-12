#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
int rdu[505];
const int N = 3505;
int S, T;
bool vis[N], inq[N];
long long dis[N];
std::queue<int> q;
struct edge{int to, w, c, nex;}e[N * 8];
int cur[N], hr[N], en = 1;
const int INF = 1e18;

bool spfa() {
    for(int i = S; i <= T; ++i) cur[i] = hr[i], inq[i] = 0, dis[i] =INF;
    for(dis[S] = 0, inq[S] = 1, q.push(S); !q.empty();) {
        int u = q.front(); q.pop(), inq[u] = 0;
        for(int i = hr[u]; i; i = e[i].nex) 
            if(dis[e[i].to] > dis[u] + e[i].c && e[i].w) {
                dis[e[i].to] = dis[u] + e[i].c;
                if(!inq[e[i].to]) inq[e[i].to] = 1, q.push(e[i].to);
            }
    }
    return dis[T] < INF;
}

int dfs(int x, int f) {
    if(x == T || !f) return f;
    vis[x] =1;
    int w, used = 0;
    for(int &i = cur[x]; i; i = e[i].nex) 
        if(dis[e[i].to] == dis[x] + e[i].c && e[i].w && !vis[e[i].to]) {
            w = dfs(e[i].to, min(f - used, e[i].w));
            e[i].w -= w;
            e[i ^ 1].w += w;
            used += w;
            if(used == f) break;
        }
    vis[x] = 0; return used;
}

void ins(int x, int y, int w, int c) {
    e[++en] = (edge){y, w, c, hr[x]}; hr[x] = en;
    e[++en] = (edge){x, 0, -c, hr[y]}; hr[y] = en;
}

long long Ans() {
    long long r = 0;
    while(spfa()) r += dfs(S, INF) * dis[T];
    return r;
}

signed main() {
    scanf("%lld%lld%lld", &n, &m, &k);
    S = 0, T = n + m + 1;
    for(int i = 1;  i <= m; ++i) {
        int u, v, x, y;
        scanf("%lld%lld%lld%lld", &u, &v, &x, &y);
        ins(n + i, u, 1, x);
        ins(v, n + i, 1, 0);
        ins(n + i, T, 1, y);
        ++rdu[v];
    }
    for(int i = 1; i <= n; ++i) {
        if(rdu[i] < k) ins(i, T, k - rdu[i], 0);
        else if(rdu[i] > k) ins(S, i, rdu[i] - k, 0);
    }
    printf("%lld\n", Ans());
    return 0;
}