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
int q_pow(int x, int y) {
	int ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) Mul(ans, x);
		Mul(x, x);
	}
	return ans;
}

int main() {
	int ans = 1;
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		if(n == 1) cout << "1\n";
		else if(n == 2) cout << "2\n";
		else if(n == 3) cout << "6\n";
		else {
			int ans = mul(6, q_pow(2, n - 3));
			cout << ans << "\n";
		}
	}
	return 0;
}