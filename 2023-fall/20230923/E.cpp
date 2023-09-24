#include<bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int n, m;
int f[MN], g[MN];
vector<int> G[MN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 2; i <= n; ++i) {
        cin >> f[i];
    }
    g[1]=0;
    for(int i = 2; i <= n; ++i) g[i] = -1;
    queue<tuple<int,int,int>> q;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(auto x : G[1]) q.push({x, 1, 1});
    while(!q.empty()) {
        auto [x, y, step] = q.front();
        q.pop();
        // if(g[x]!=-1&&g[y]!=-1) continue;
        // int lca = LCA(x, y);
        while(g[x]==-1) {
            g[x]=step;
            for(auto z : G[x]) if(g[z]==-1) q.push({z, x, step+1});
            x=f[x];
        }
    }
    for(int i = 2; i <= n; ++i) cout << g[i] << " ";
    return 0;
}