#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int add(int x, int y) {
	return (x + y) % mod;
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
void Mul(int &x, int y) {
	x = mul(x, y);
}
int q_pow(int x, int y) {
	int ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) Mul(ans, x);
		Mul(x, x);
	}
	return ans;
}

int C(int x, int y) {
	int ans = 1;
	for(int i = 1; i <= x; ++i) Mul(ans, i);
	for(int i = 1; i <= y; ++i) Mul(ans, q_pow(i, mod - 2));
	for(int i = 1; i <= x - y; ++i) Mul(ans, q_pow(i, mod - 2));
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	cout << mul(q_pow(k, n), mul(q_pow(n + 1, mod - 2), C(2 * n, n))) << "\n";
	return 0;
}