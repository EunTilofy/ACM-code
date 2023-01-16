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
	for(int n = 1; n <= 100; ++n) {
		vector<int> f(n + 1);
		for(int j = 1; j <= n; ++j) f[j] = j * 2 + 1;
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			int pos = 1;
			for(int j = 1; j <= n; ++j) {
				if(i == j) continue;
				Mul(pos, mul(add(f[i] + 1, -mul(f[i], f[j])), q_pow(add(f[i], -f[j]), mod - 2)));	
			}
			Add(ans, pos);
		}
		cout << "n = " << n << " " << ans << "\n";
	}
	return 0;
}