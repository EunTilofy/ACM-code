#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node {
	double T, s, arg, theta;
} a[N];
const double pi = acos(-1.0);
int n;
bool cmp(node A, node B) {
	return A.arg < B.arg;
}
double getdis(double A, double B) {
	double pos = abs(A - B);
	return pos >= 180.0 ? -pos + 360.0 : pos;
}
double get(int id) {
	double ans = 0.0;
	for(int i = 1; i <= n; ++i) {
		ans += max(0.0, a[i].T - a[i].s * getdis(a[i].arg, a[id].arg));
	}
	return ans;
}
double qzT[N], qza[N], qzs[N], qzt[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].T >> a[i].s >> a[i].arg;
		a[i].theta = a[i].T / a[i].s;
	}
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; ++i) {
		qzT[i] = qzT[i - 1] + a[i].T;
		qza[i] = qza[i - 1] + a[i].arg;
		qzs[i] = qzs[i - 1] + a[i].s;
		qzt[i] = qzt[i - 1] + a[i].s * a[i].arg;
	}
	double ans = 0.0;
	double pos = ans;
	int l = 0, r = n + 1;
	set<pair<double, int> > sl, tl, sr, tr;
	for(int i = 1; i <= n; ++i) {
		for(; r - 1 >= i && a[r - 1].arg - a[i].arg >= pi; --r) sr.insert({a[r - 1].arg + a[r - 1].theta, r - 1});
		for(; l + 1 <= i && a[i].arg - a[l + 1].arg >= pi; ++l) sl.insert({a[l + 1].arg + a[l - 1].theta, l + 1});
		//[1, l], [l + 1, i - 1], [i + 1, r - 1], [r, n]
//		cerr << l << " " << r << "\n";
		double pos = qzT[n];
		pos += qzt[i - 1] - qzs[i - 1] * a[i].arg + pi * qzs[l];
		pos += -(qzt[n] - qzt[i]) + a[i].arg * (qzs[n] - qzs[i]) + pi * (qzs[n] - qzs[r - 1]);
		//pos = qzT[n] - a[i].s;
		
		ans = max(ans, pos);
	}
	cout << fixed << setprecision(12) << ans << "\n";
	return 0;
}