#include<bits/stdc++.h>
using namespace std;

void solve() {
	double x, y, p;
	cin >> x >> y >> p;
	double ans = 0.0, tmp = 1.0 / p;
	for(int i = 0; ; ++i) {
		double pos = min(y, x - y * i);
		if(pos <= 0) break;
		ans += 1.0 * pos / y * tmp;
		// cerr << i << " " << ans << "\n";
		tmp *= (1.0 - 1.0 / p);
	}
	// cerr << ans << "\n";
	cout << fixed << setprecision(15) << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		solve();
	}
	return 0;
}