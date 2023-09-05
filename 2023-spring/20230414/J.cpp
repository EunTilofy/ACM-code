#include<bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 4;
int n, m;
vector<int> G[MN];

bool fd0 = 0, fd1 = 0;
int got[MN];
int dfn[MN], low[MN], dind, dep[MN], deg[MN];
bool flag;
void tarjan(int x, int f) {
    // cout << x << " " << f << endl;
    dfn[x] = ++dind; low[x] = dfn[x];
    dep[x] = dep[f] + 1;
    for(auto y : G[x]) if(y != f) {
        if(!dfn[y]) {
            tarjan(y, x);
            low[x] = min(low[y], low[x]);
        } else {
            got[y] += 1;
            low[x] = min(low[x], dfn[y]);
            if((dep[x] - dep[y]) % 2 == 1) fd0 = 1;
        }
    }
    if(low[x] < dfn[x] && got[x] || got[x] > 1) fd0 = 1;
}

bool col[MN], vis[MN];
void dfs(int x, int f) {
    vis[x] = 1;
    for(auto y : G[x]) if(y != f) {
        if(vis[y]) {
            if(col[x] == col[y]) fd1=1;
        } else {
            col[y] = !col[x];
            dfs(y, x);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n >> m;
    if(n <= 3) {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        ++deg[y]; ++deg[x];
    }

    for(int u = 1; u <= n; ++u) {
        for(auto v : G[u]) {
            if(deg[u]>=2&&deg[v]>=2&&max(deg[u],deg[v])>=3) flag=1;
            if(deg[u]==2&&deg[v]==2) {
                int ou = G[u][0] == v ? G[u][1] : G[u][0];
                int ov = G[v][0] == u ? G[v][1] : G[v][0];
                if(ov != ou) flag = 1;
            }
        }
    }

    for(int i = 1; i <= n; ++i) if(!dfn[i] && deg[i]) tarjan(i, 0);
    for(int i = 1; i <= n; ++i) if(!vis[i]) col[i] = 1, dfs(i,0);

    // cout << fd1 << " " << fd0 << endl;

    if(fd1 && fd0) cout << "0";
    else if(!fd1 && fd0) cout << "1";
    else if(!fd1 && !fd0) {
        if(m <= 2) cout << 5 - m;
        else if(flag) cout << 2;
        else cout << 3;
    } else {
        if(flag) cout << 1;
        else cout << 2;
    }
} 