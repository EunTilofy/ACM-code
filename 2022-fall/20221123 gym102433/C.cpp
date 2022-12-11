#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int> > G(n + 1);
	for(int i = 1, x, y; i <= m; ++i) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int inf = 1e9;
	vector<int> dis(n + 1, inf);
	dis[1] = 0;
	priority_queue<pair<int, int> > q;
	q.push({0, 1});
	while(q.size()) {
		auto [len, u] = q.top(); q.pop();
		len = -len;
		if(dis[u] != len) continue;
		for(auto v : G[u]) {
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push({-dis[v], v});
			}
		}
	}
	cout << dis[n] - 1 << "\n";
	return 0;
}