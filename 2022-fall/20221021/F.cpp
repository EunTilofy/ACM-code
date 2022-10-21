#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
const ll inf = 1e18;

vector<int> G[N];

ll solve() {
	int n, m;
	cin >> n >> m;
//	cout << "!!!\n";
	vector<int> a(n), b(n), c(n), w(m);
	for(int &x : a) {cin >> x; x--; }
	for(int &x : b) {cin >> x; x--; }
	for(int &x : c) cin >> x;
	for(int &x : w) cin >> x;
	
//	cout << "???\n";
	for(int i = 0; i < m; ++i) G[i].clear();
	
	for(int i = 0; i < n; ++i) {
		G[b[i]].push_back(i);
	}
	
	vector<ll> f(m);	
	for(ll &x : f) x = inf;
	priority_queue<pair<ll, int> > q;
	for(int i = 0; i < m; ++i) {
		if(w[i] == 0) {
			f[i] = 0;
			q.push({0, i});
		}
	}
	while(q.size()) {
		auto [val, x] = q.top(); q.pop();
//		if(w[x] == 2) continue;
		val = -val;
		if(val != f[x]) continue;
//		cout << val << " " << x << endl;
		for(auto id : G[x]) {
			int y = a[id], v = c[id];
			if(f[y] > val + v) {
				f[y] = val + v;
				q.push({-f[y], y});
			}
		}
	}
	int flg = 0;
	ll ans = 0;
	for(int i = 0; i < m; ++i) {
		if(w[i] == 2) {
			ans += f[i];
			if(f[i] == inf) flg = 1;
		}
	}
	if(flg) return -1;
	else return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
//		cout << "!!!!\n";
		ll ans = solve();
		cout << "Case #" << o << ": " << ans << "\n";
	}
	return 0;
}