#include<bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<pair<ll, pair<int, int>> > q;
const int N = 510;
ll dis[N][N];
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>> > G(n + 1);
	for(int i = 1, x, y, z; i <= m; ++i) {
		cin >> x >> y >>z;
		G[x].push_back({y, z});
		G[y].push_back({x, z});
	}
	ll inf = 1e18;
	for(int i = 1; i <= n; ++i) for(int j = 0; j <= n; ++j) dis[i][j] = inf;
	dis[1][0] = 0, q.push(make_pair(0, make_pair(1, 0)));
	while(q.size()) {
		pair<ll, pair<int, int>> cur = q.top(); q.pop();
		ll w = cur.first;
		int u = (cur.second).first, len = (cur.second).second;
		w = -w;
		if(dis[u][len] != w) continue;
		for(auto[v, z] : G[u]) {
			ll pos = w + z;
			if(dis[v][len + 1] > pos) {
				dis[v][len + 1] = pos;
				q.push(make_pair(-pos, make_pair(v, len + 1)));
			}
		}
	}
	int Q;
	cin >> Q;
	for(int o = 1; o <= Q; ++o) {
		int T; cin >> T;
		ll ans = inf, qz = 0;
		for(int i = 1, x; i < n; ++i) {
			cin >> x; 
			qz += x;
			ans = min(ans, dis[T][i] + qz);
		}
		cout << ans << "\n";
	}
	return 0;
}