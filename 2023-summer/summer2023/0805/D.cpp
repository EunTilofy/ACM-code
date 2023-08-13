#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5 + 5;

vector<int> G[MN];
vector<int> ans;
int fa[MN];
int getf(int x) {
    return fa[x] == x ? x : fa[x] = getf(fa[x]);
}
int UP;
int len[MN];
void dfs(int x, int f) {
    len[x] = 0;
    for(auto &y : G[x]) {
        if(y == f) continue;
        dfs(y, x);
        len[x] = max(len[x], len[y] + 1);
    }
    if(len[x] == UP) {
        ans.push_back(x);
        len[x] = 0;
    }
    if(f == 0 && len[x] > 0) ans.push_back(x);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) G[i].clear(), fa[i] = i;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        if(getf(x) != getf(y)) {
            G[x].push_back(y);
            G[y].push_back(x);
            fa[getf(x)] = getf(y);
        }
    }

    UP = (int)sqrt(n);
    while(1ll * UP * UP < n) ++UP;
    ans.clear();
    dfs(1, 0);
    if(ans.size() > UP) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << "\n";
    for(auto &x : ans) cout << x << " " ; 
    cout << "\n";
    for(int i = 1; i <= n; ++i) G[i].clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}