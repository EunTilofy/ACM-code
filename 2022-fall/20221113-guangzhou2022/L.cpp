#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 998244353;
int jc[N], ny[N];

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
	if(x < y) return 0;
	return mul(jc[x], mul(ny[y], ny[x - y]));
}

int main() {
	jc[0] = ny[0] = 1;
	for(int i = 1; i < N; ++i) jc[i] = mul(jc[i - 1], i), ny[i] = q_pow(jc[i], mod - 2);
	int T;
	scanf("%d", &T);
	for(int o = 1; o <= T; ++o) {
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", mul(jc[n], C(n - 1, m - 1)));		
	}
	return 0;
}