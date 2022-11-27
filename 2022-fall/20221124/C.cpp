#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> P;
int add(int x, int y, int m) {
	return (x + y) % m;
}
int phi(int n) {
	int t = 1;
	for(int i = 2; 1ll * i * i <= n; ++i)
		if(n % i == 0) for(n /= i, t *= i - 1; n % i == 0; n /= i, t *= i);
	if(n > 1) t *= n - 1;
	return t;
}
int pow(ll a, int b, int m) {
	ll t = 1;
	for(; b; b >>= 1, a = a * a % m)
		if(b & 1) t = t * a % m;
	return t;
}
int bsgs(int a, int r, int m) {
	if(r >= m) return -1;
	int i, g, x, c = 0, at = int(sqrt(m) + 2);
	for(i = 0, x = 1 % m; i < 50; ++i, x = 1ll * x * a % m) if(x == r) return i;
	for(g = x - 1; __gcd(int(1ll * x * a % m), m) != g; c++) g = __gcd(x = 1ll * x * a % m, m);
//	cerr << "!!!\n";
	if(r % g) return -1;
//	cerr << "???\n";
	if(x == r) return c;
	unordered_map<int, int> u;
	g = phi(m / g), u[x] = 0, g = pow(a, g - at % g, m);
	for(i = 1; i < at; ++i) {
		u.insert(P(x = 1ll * x * a % m, i));
		if(x == r) return c + i;
	}
	for(i = 1; i < at; ++i) {
		unordered_map<int, int> :: iterator t = u.find(r = 1ll * r * g % m);
		if(t != u.end()) return c + i * at + (t -> second);
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, m, x0, x;
	cin >> a >> b >> m >> x0 >> x;	
	if(!a) {
		if(x0 == x || b == x) cout << "YES\n";
		else cout << "NO\n";
		return 0;
	} else if(a == 1) {
		if(b || x0 == x)cout << "YES\n";
		else cout << "NO\n";
		return 0;
	} else {
		int pos = 1ll * b * pow(a - 1, m - 2, m) % m;
		int r = 1ll * add(x, pos, m) * pow(add(x0, pos, m), m - 2, m) % m;
		if(!add(x0, pos, m)) {
			if(add(x, pos, m)) cout << "NO\n";
			ekse cout  << "YES\n";
			return 0;
		}
	//	cerr << r << "\n";
//		cerr << pow(a, m - 3, m) << "\n";
		int ans = bsgs(a, r, m);
	//	cerr << ans << "\n";
		if(ans != -1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}