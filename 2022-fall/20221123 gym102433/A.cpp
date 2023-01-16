#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int val[N];
vector<pair<int, int> > G[N];

ll f[N], sv[N], g[N], ans[N], sz[N];

void predfs(int u, int fa) {
	sz[u] = 1, sv[u] = val[u];
	for(auto[v, w] : G[u]) {
		if(v == fa) continue;
		predfs(v, u);
		f[u] += f[v] + 1ll * w * sv[v];
		g[u] += g[v] + 1ll * w * sz[v];
		sv[u] += sv[v];
		sz[u] += sz[v];
	}
}

void dfs(int u, int fa, ll cur, ll siv, ll tmp, ll siz) {
//	cerr << u << " " << fa << " " << cur << " " << siv << " " << tmp << " " << siz << "\n";
	ans[u] = f[u] + (g[u] + tmp) * val[u] + cur;
//	cerr << f[u] + cur << " " << g[u] * val[u] + tmp << "\n";
	ll Tot_cur = 0, Tot_siv = val[u], Tot_tmp = 0, Tot_siz = 1;
	for(auto[v, w] : G[u]) {
		if(v == fa) continue;
		Tot_siv += sv[v];
		Tot_siz += sz[v];
		Tot_cur += f[v] + 1ll * w * sv[v];
		Tot_tmp += g[v] + 1ll * w * sz[v];
	}
	for(auto[v, w] : G[u]) {
		if(v == fa) continue;
		ll _siv = siv + Tot_siv - sv[v];
		ll _siz = siz + Tot_siz - sz[v];
		
		ll _cur = cur + Tot_cur - f[v] - 1ll * w * sv[v] + _siv * w;
		ll _tmp = tmp + Tot_tmp - g[v] - 1ll * w * sz[v] + _siz * w;
		dfs(v, u, _cur, _siv, _tmp, _siz);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> val[i];
	for(int i = 1, x, y, w; i < n; ++i) {
		cin >> x >> y >> w;
		G[x].push_back({y, w});
		G[y].push_back({x, w});
	}
	int rt = 1;
	predfs(rt, 0);
//	for(int i = 1; i <= n; ++i) {
//		cerr << "i : " << i << " " << sz[i] << " "<< g[i] << " " << sv[i] << " " << f[i] << "\n";
//	}
	dfs(rt, 0, 0, 0, 0, 0);
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << "\n";
	return 0;
}

/*
5
2 5 3 4 1
1 2 2
2 4 5
4 3 3
5 2 6
130
159
191
163
171
*/