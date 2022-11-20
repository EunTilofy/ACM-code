#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 10;
int all[N];

ll solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int cnt = 0;
	for(int &x : a) {cin >> x; all[++cnt] = x;}
	vector<pair<int, int> > p(k);
	all[++cnt] = 0;
	for(auto &[x, y] : p) {
		cin >> x >> y;
		all[++cnt] = x;
		all[++cnt] = max(0, x - 1);
		all[++cnt] = x + 1;
	}
	sort(all + 1, all + 1 + cnt);
	int tot = unique(all + 1, all + 1 + cnt) - all - 1;
//	for(int i = 1; i <= tot; ++i)
//		cout << all[i] << " ";
//	cout <<"\n";
//	cout << lower_bound(all + 1, all + 1 + tot, 0) - all << "\n";
	vector<int> nm(tot + 1), lim(tot + 1, n);
	for(int x : a) {
		x = lower_bound(all + 1, all + 1 + tot, x) - all;
		nm[x]++;
	}
	for(auto [x, y] : p) {
		x = lower_bound(all + 1, all + 1 + tot, x) - all;
		lim[x] = y;
	}
//	for(int i = 1; i <= tot; ++i)
//		cerr << i << " " << all[i] << " " << lim[i] << "\n";
	ll ans = 0;
	for(int i = 1; i <= tot; ++i) {
		if(!lim[i]) continue;
		int j = i;
		for(; j + 1 <= tot && lim[j + 1]; ++j) ;
		int num = 0;
		ll pos = 0, tmp = 0;
		for(int k = i; k <= j; ++k) {
			num += nm[k];
			pos += 1ll * nm[k] * all[k];
		}
//		cerr << num << "\n";
		for(int k = i; k <= j; ++k) {
			tmp += min(num, lim[k]) * all[k];
			num -= min(num, lim[k]);
		}
//		cerr << pos << " " << tmp << "\n";
		ans += pos - tmp;
		i = j;
	}
//	cout << "ans = " << ans << "\n";
	return ans % 2 == 0;	
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		cout << (solve() ? "FuuFuu\n" : "Pico\n");
	}
	
	
	return 0;
}