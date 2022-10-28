#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(k), b(k);

	for(int &x : a) cin >> x;
	for(int &x : b) cin >> x;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int ans = n;
	
	vector<pair<int, int> > c(k); 
	for(int o = 0; o < k; ++o) {
		int pos1 = 0, pos2 = 0;
		for(int i = 0; i < k; ++i) {
			int id = (i + o) % k;
			c[i] = {(b[id] - a[i] + n) % n, (a[i] - b[id] + n) % n};
			pos1 = max(pos1, (b[id] - a[i] + n) % n);
			pos2 = max(pos2, (a[i] - b[id] + n) % n);
		}
		// cerr << o << "\n";
		sort(c.begin(), c.end());
		vector<int> hz(k + 1);
		for(int i = k - 1; i >= 0; --i) hz[i] = max(hz[i + 1], c[i].second);
		for(int i = 0; i < k; ++i) {
			int l = c[i].first, r = hz[i + 1];
			ans = min(ans, l + r + min(l, r));
		}
		ans = min(ans, min(pos1, pos2));
	}

	reverse(b.begin(), b.end());
	for(int o = 0; o < k; ++o) {
		int pos1 = 0, pos2 = 0;
		for(int i = 0; i < k; ++i) {
			int id = (i + o) % k;
			c[i] = {(b[id] - a[i] + n) % n, (a[i] - b[id] + n) % n};
			pos1 = max(pos1, (b[id] - a[i] + n) % n);
			pos2 = max(pos2, (a[i] - b[id] + n) % n);
		}
		// cerr << o << "\n";
		sort(c.begin(), c.end());
		vector<int> hz(k + 1);
		for(int i = k - 1; i >= 0; --i) hz[i] = max(hz[i + 1], c[i].second);
		for(int i = 0; i < k; ++i) {
			int l = c[i].first, r = hz[i + 1];
			ans = min(ans, l + r + min(l, r));
		}
		ans = min(ans, min(pos1, pos2));
	}

	cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int T;
	cin >> T;
	while(T--) solve();

	return 0;
}