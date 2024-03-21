#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, LOG = 20;
vector<int> e[N];
int dp[N], n, m;
int g[N][LOG + 1], f[N], dep[N];

void dfs(int x, int fa) {
    f[x] = fa, dep[x] = dep[fa] + 1;
    g[x][0] = fa;
    for(int i = 1; i <= LOG; ++i) g[x][i] = g[g[x][i - 1]][i - 1];
    for(int y : e[x]) if(y != fa) {
        dfs(y, x);
    }
}

int GetLCA(int A, int B) {
    if(!A || !B) return 0;
    if(dep[A] <= dep[B]) swap(A, B);
    for(int i = LOG; i >= 0; --i) if(dep[g[A][i]] >= dep[B]) A = g[A][i];
    for(int i = LOG; i >= 0; --i) if(g[A][i] != g[B][i]) {
        A = g[A][i], B = g[B][i];
    } 
    return A == B ? A : g[A][0];
}

void Dfs(int x) {
    vector<int> q;
    for(int y : e[x]) if(y != f[x]) {
        Dfs(y);
        q.push_back(dp[y]);
    }
    if(q.size()) {
        int lca = q[0], flg = 1;
        for(int x : q) lca = GetLCA(lca, x);
        for(int x : q) if(lca != x) flg = 0;
        if(!flg && dep[lca] < dep[x]) dp[x] = 0;
        else dp[x] = lca;
    }
    else dp[x] = (x == m ? 1 : x + 1);
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        f[i] = dep[i] = dp[i] = 0;
        for(int j = 0; j <= LOG; ++j) g[i][j] = 0;
        e[i].clear();
    }
    for(int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        e[x].push_back(y), e[y].push_back(x);
    }
    dfs(n, 0);
    Dfs(n);
    if(dp[n]) cout << "Doddle\n";
    else cout << "Tie\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for(int o = 1; o <= T; ++o)
        solve();
    return 0;
}