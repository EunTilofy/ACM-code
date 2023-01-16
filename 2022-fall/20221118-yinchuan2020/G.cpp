#include <bits/stdc++.h>
//#define int long long
#define ll long long
using namespace std;

int main() {
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
	for(int o = 0; o <= q; ++o) {
		int pos = (py[o] + now) % n;
		set<int> s;
		set<int> :: iterator it, ti;
		ll sum = 0, ans = 0;
//		cerr << "pos = " << pos << " ";
		for(int i = 0; i < n; ++i) {
			int id = p[(i + pos) % n], val = h[id];
			it = s.lower_bound(id);
//			cerr << "val = " << val << "\n";
			if(it == s.end()) {
				if(s.size()) {
					int x = *s.rbegin(); x = h[x];
					ans += 1ll * (x - val) * (x - val);
				}
			} else if(it != s.begin()){
				ti = it; --it;
				int bf = *ti, ed = *it;
				bf = h[bf], ed = h[ed];
				ans -= 1ll * (bf - ed) * (bf - ed);
				ans += 1ll * (bf - val) * (bf - val);
				ans += 1ll * (ed - val) * (ed - val);
			} else {
				int bf = *it;
				bf = h[bf];
				ans += 1ll * (bf - val) * (bf - val);
			}
			sum += ans;
			s.insert(id);
		}
		cout << sum << "\n";
		now = (sum + pos) % n;
	}
	return 0;
}