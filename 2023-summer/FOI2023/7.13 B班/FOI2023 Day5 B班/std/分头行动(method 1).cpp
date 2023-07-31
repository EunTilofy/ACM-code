#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 3;
int n, d, m1, m2;
vector<int> e[N];

bool b[N], c[N]; // 两人必须要访问的点

inline void adde(int x, int y) {
    e[x].push_back(y);
}
int dfn[N], id = 0, fa[N][19], dep[N];

void dfs(int u, int f){ // dfs，初始化倍增数组
	dfn[u] = ++id;
	fa[u][0] = f;
	for(int i = 1; i < 19; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int v : e[u]) if(v!=f) {
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int up(int x, int k){ // k级祖先
	for(int i = 18; ~i; --i)
        if(k>>i&1) x = fa[x][i];
	return x;
}

int dfs2(int u, int f) {
    int ans = 0;
    for(int v : e[u]) if(v != f) {
        ans += dfs2(v, u);
        if(b[v]) ans += 2;
        if(c[v]) ans += 2;
        b[u] |= b[v];
        c[u] |= c[v];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m1 >> m2 >> d;

    int x, y;
    for(int i = 0; i < m1; ++i) cin >> x, b[x] = 1;
    for(int i = 0; i < m2; ++i) cin >> x, c[x] = 1;

    for(int i = 1; i < n; ++i) 
        cin >> x >> y, adde(x, y), adde(y, x);
    
    dfs(1, 0);
    
    for(int i = 1; i <= n; ++i) {
        if(b[i] == 1 && dep[i] >= d) c[up(i, d)] = 1;
        if(c[i] == 1 && dep[i] >= d) b[up(i, d)] = 1;
    }

    cout << dfs2(1, 0) << "\n";

    return 0;
}