#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll get(ll x, ll y, ll z) {
	z -= y;
	return x * (max(0ll, z / x) + 1) + y;
}

void solve() {
	ll a, b, c, x, y, z;
	cin >> a >> b >> c;
	if(a == b && b == c) {
		if(!a) {
			cout << "YES\n";
			cout << "1 1 1\n";
		} else cout << "NO\n";
		return ;
	} else {
		if(a > c) {
			x = a;
			z = get(x, c, b);
			y = get(z, b, a);
		} else if(b > a) {
			y = b;
			x = get(y, a, c);
			z = get(x, c, b);
		} else if(c > b) {
			z = c;
			y = get(z, b, a);
			x = get(y, a, c);
		}
		cout << "YES\n";
		cout << x << " " << y << " " << z << "\n";
		assert(x % y == a);
		assert(y % z == b);
		assert(z % x == c);
	}
}

int main() {
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		solve();
	}
	return 0;
}