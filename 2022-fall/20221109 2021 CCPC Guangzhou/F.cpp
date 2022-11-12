#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int mk[15];
void dfs(int dep, int n, int qz) {
	if(dep > n) {
		++ans;
		return ;
	}
	for(int i = 1; i <= n; ++i) {
		if(!mk[i]) {
			if((qz + i) * 2 % dep) continue;
			mk[i] = 1;
			dfs(dep + 1, n, qz + i);
			mk[i] = 0;
		}
	}
}
const int mod = 998244353;
int mul(int x, int y) {
	return  1ll * x * y % mod;
}
void Mul(int &x, int y) {
	x = mul(x, y);
}
int add(int x, int y) {
	return ((x + y) % mod + mod) % mod;
}
void Add(int &x, int y) {
	x = add(x, y);
}
int q_pow(int x, int y) {
	int ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) Mul(ans, x);
		Mul(x, x);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> f(n + 3);
	f[1] = f[2] = 1;
	for(int i = 3; i <= n; ++i) {
		f[i] = add(f[i - 1], f[i - 2]);
	}
	cout << f[n] << "\n";
	return 0;
}