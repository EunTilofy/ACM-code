#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
	double T, s, arg, theta;
} a[N];
bool cmp(node A, node B) {
	return A.arg < B.arg;
}
double getdis(double A, double B) {
	double pos = abs(A - B);
	return pos >= 180.0 ? -pos + 360.0 : pos;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].T >> a[i].s >> a[i].arg;
		a[i].theta = a[i].T / a[i].s;
	}
	sort(a + 1, a + 1 + n, cmp);
	double ans = 0.0;
	for(int j = 1; j <= n; ++j) {
		double pos = 0.0;
		for(int i = 1; i <= n; ++i) {
			pos += max(0.0, a[i].T - a[i].s * getdis(a[i].arg, a[j].arg));
		}
		ans = max(ans, pos);
	}
	cout << fixed << setprecision(12) << ans << "\n";
	return 0;
}