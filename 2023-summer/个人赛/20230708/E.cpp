#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, MN = 50005;

int f[10][10];
int fac[MN], inv[MN];
int Mul(int x, int y) {
	return (1ll * x * y) % mod;
}

int Add(int x, int y) {
	return (x + y) % mod;
}

int fpow(int x, long long y) {
	int r = 1;
	for(; y; y>>=1, x = Mul(x, x)) if(y & 1) r = Mul(r, x);
	return r;
}

int C(int x, int y){
	return Mul(fac[x], Mul(inv[y], inv[x - y]));
}

int get(int n, int m) {
	int num = fpow(2, n);
	num = Add(num, mod - 1);
	return fpow(num, m);
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	// if(n<=10 && m <=10) cout << f[n][m] << endl;

	int ans = get(n, m);

	for(int k = 1; k <= n; ++k) {
		if(k & 1) ans = Add(ans, mod - Mul(get(n - k, m), C(n, k)));
		else ans = Add(ans, Mul(get(n - k, m), C(n, k)));
	}

	cout << ans << endl;

	return ;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for(int i = 2; i <= 50000; ++i) fac[i] = Mul(fac[i - 1], i);
	for(int i = 2; i <= 50000; ++i) inv[i] = Mul(inv[mod % i], (mod - mod/i));
	for(int i = 2; i <= 50000; ++i) inv[i] = Mul(inv[i - 1], inv[i]);
	int T;
	cin >> T;
	while(T--) solve();
}