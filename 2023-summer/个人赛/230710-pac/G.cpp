#include<bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);
double sqr(double x){return x * x;}

void solve() {
	double x, y, r, X, Y, R, L;
	cin >> x >> y >> r >> X >> Y >> R >> L;
	
	double rr = sqrt(1.0*L*L + 1.0*r*r);
	double d = sqrt(1ll * (x - X) * (x - X) + 1.0 * (y - Y) * (y - Y));
	if (rr + R <= d) {
		cout << "0.000000000" << endl;
		return;
	}
	if(d < rr) {
		double _2 = asin((r+R)/d) - asin(r/rr);
		double h = sqrt(sqr(d)-sqr(R-r));
		double _x = (h - sqrt(sqr(h)-4*r*R))/2;
		double arc = _2;
		double ans = arc * r;
		cout << fixed << setprecision(9) << ans << endl;
		return;
	}

	double _x = sqrt(abs(sqr(R)-sqr((sqr(d)+sqr(R)-sqr(rr))/2/d)));

	double _1 = asin(_x/rr);
	double _2 = asin((r+R)/d) - asin(r/rr);
	double arc = _1 + _2;
	if(L<sqrt(sqr(d)-sqr(R+r))) arc = _1 + _1;

	double ans = arc * r;
	cout << fixed << setprecision(9) << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while(T--) solve();

	return 0;
}	