#include<bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.);

signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;	
	cin >> n >> m;
	double ans = 0.0;
	for(int i = 1; i <= 2 * n; ++i) ans = ans + i * (2 * n - i + 1);
	ans = ans * m;
	if(m == 1) {
		ans -= n * (n + 1) * m;
		cout << fixed << setprecision(12) << ans << "\n";
		return 0;	
	}
	// cout << fixed << setprecision(12) << ans << "\n";
	for(int i = 1; i <= n; ++i) 
		for(int j = i + 1; j <= n; ++j) {
			ans = ans + (j - i) * (2 * m) * (2 * m - 2);
		}
	// cout << fixed << setprecision(12) << ans << "\n";
	double ans2 = 0.0;
	for(int i = 1; i <= n; ++i) {
		double tmp = 0.0;
		for(int k = 1; k < m; ++k) {
			if(k * Pi / m > 2.0) {
				tmp = tmp + 2 * i * m * 2 * (2 * (n - i + 1) - 1);
				// cout << 2 * i * m * 2 * (2 * (n - i + 1) - 1) << endl;
			}
			// else tmp = tmp + k * Pi * i * (n - i + 1) * 2;
			else {
				// ans2 += 2 * k * i * (2 * (n - i + 1) - 1);
				tmp += 2 * k * i * (2 * (n - i + 1) - 1) * Pi;
			}
		}
		ans = ans + tmp;
		// cout << fixed << setprecision(12) << tmp << endl;
	}
	// cout << fixed << setprecision(12) <<ans2 << "\n";
	// for(int k = 1; k < m; ++k) {
	// 	if(k * Pi / m > 2.0) {

	// 	}
	// 	else {
	// 		for(int i = 1; i <= n; ++i) ans += k * i * 2 * (2 - (n - i + 1) - 1) * Pi;
	// 	}
	// }
	cout << fixed << setprecision(12) << ans << "\n";
	return 0;
}