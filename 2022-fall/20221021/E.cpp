#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e4 + 10;
vector<pair<int, ll> > G[N];
vector<ll> cir;
int vs[N];
ll f[N];

void dfs(int x, int fa) {
	vs[x] = 1;
	for(auto [y, w] : G[x]) {
		if(y == fa) continue;
		if(vs[y]) {
//			cout << y << " " << x << " " << f[y] << " " << f[y] << w << endl;
			cir.push_back(f[y] ^ f[x] ^ w);
		} else {
			f[y] = f[x] ^ w;
			dfs(y, x);
		}
	}
}

ll solve() {
	int n, m;
	cin >> n >> m;
	cir.clear();
	for(int i = 1; i <= n; ++i) {
		G[i].clear();
		f[i] = vs[i] = 0;
	}
	for(int i = 1; i <= m; ++i) {
		int x, y;
		ll w;
		cin >> x >> y >> w;
		G[x].push_back({y, w});
		G[y].push_back({x, w});
	}
	dfs(1, 0);
	vector<ll> qx(61);
	for(auto w : cir) {
//		cout << "w = " << w << endl;
		for(int i = 60; i >= 0; --i) {
			if((w >> i) & 1) {
				if(!qx[i]) {qx[i] = w; break;}
				else w ^= qx[i];
			}
		}
	}
	ll ans = 0;
	for(int i = 60; i >= 0; --i) {
		if((ans >> i) & 1) continue;
		ans ^= qx[i];
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		ll ans = solve();
		cout << "Case #" << o << ": " << ans << "\n";
	}
	return 0;
}