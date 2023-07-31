#include<bits/stdc++.h>
using namespace std;

struct edge{
	int to, t, p, c;
};

const int MN = 100005;
vector<edge> G[MN];
double dis[MN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= m; ++i) {
		int u, v, t, p, c;
		cin >> u >> v >> t >> p >> c;

		G[u].push_back((edge){v, t, p, c});
	}

	priority_queue<pair<double, int>> q;
	q.push({0, 1});
	for(int i = 2; i <= n; ++i) {
		dis[i] = 1e14 + 5;
	}
	while(!q.empty()) {
		auto o = q.top(); q.pop();
		if(-o.first > dis[o.second]) continue;
		int x = o.second;
		double d = -o.first;
		for(auto &e : G[x]) {
			double exp = d + e.c;
			// cerr << (100 - e.p) << " " << e.t << " " << d+e.t << endl;
			if(e.p != 100) exp = min(exp, (100.0 / (100.0 - e.p)) * (d + e.t));
			if(exp < dis[e.to]) {
				dis[e.to] = exp;
				// cerr << "dis[" << e.to << "]" << " = " << dis[e.to] << endl;
				q.push({-dis[e.to], e.to});
			}
		}
	}


	if(dis[n] > 1e14) cout << "-1" << "\n";
	else cout << fixed << setprecision(10) << dis[n] << "\n";
}