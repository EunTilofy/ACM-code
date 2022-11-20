#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> h(n), p(n), py;
	for(int &x : h) cin >> x;
	for(int &x : p) {cin >> x; x--;}
	py.push_back(0);
	for(int i = 1, x; i <= q; ++i) {
		cin >> x;
		py.push_back(x);
	}
	int now = 0;
	ll cur = 0;
	for(int i = 1; i < n; ++i) {
		cur += 1ll * (h[i] - h[i - 1]) * (h[i] - h[i - 1]);
	}
//	cerr << cur << "\n";
	for(int o = 0; o <= q; ++o) {
		int pos = (py[o] + now) % n;
		vector<int> fr(n + 1), nx(n + 1);
		for(int i = 0; i <= n; ++i) {
			fr[i] = i - 1;
			nx[i] = i + 1;
		}
		ll sum = 0, ans = cur;
		for(int i = n - 1; i >= 1; --i) {
			sum += ans;
			int id = p[(i + pos) % n], val = h[id];
			int bf = fr[id], ed = nx[id];
//			cerr << id << " " << val << " " << bf << " " << ed << "\n";
			if(bf == -1) {
				ed = h[ed];
				ans -= 1ll * (ed - val) * (ed - val);
			} else if(ed != n) {
				bf = h[bf], ed = h[ed];
				ans += 1ll * (bf - ed) * (bf - ed);
				ans -= 1ll * (bf - val) * (bf - val);
				ans -= 1ll * (ed - val) * (ed - val);
			} else {
				bf = h[bf];
				ans -= 1ll * (bf - val) * (bf - val);
			}
			if(nx[id] != n) fr[nx[id]] = fr[id];
			if(fr[id] != -1) nx[fr[id]] = nx[id];
		}
		cout << sum << "\n";
		now = (sum + pos) % n;
	}
	return 0;
}