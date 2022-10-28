#include<bits/stdc++.h>
using namespace std;
double n, p1, p2, v1, v2;

bool check(double x) {
	double len1 = x * v1, len2 = x * v2;
	int f = (len1 >= n - p1) && (len2 >= p2);
	if(f) return true;
	double l1 = len1 - 2.0 * p1, l2 = (len1 - p1) / 2.0;
	double r1 = len2 - 2.0 * (n - p2), r2 = (len2 - (n - p2)) / 2.0;

	double l = max(l1, l2), r = max(r1, r2);
	if(l >= 0 && r >= 0) return l + r >= p2 - p1;
	if(l < 0) {
		if(len1 >= p1) return r >= p2 - p1;
		return r >= p2;
	}
	if(len2 >= n - p2) return l >= p2 - p1;
	return l >= n - p1;
}
void solve() {
	
	cin >> n >> p1 >> v1 >> p2 >> v2;
	if(p1 > p2) swap(p1, p2), swap(v1, v2);
	double l = 0, r = 2.0 * n / v1, ans = -1.0;
	for(int o = 1; o <= 1000; ++o) {
		double mid = (l + r) / 2.0;
		if(check(mid)) r = mid, ans = mid;
		else l = mid;
	}
	cout << fixed << setprecision(12) << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		solve();
	}
	return 0;
}