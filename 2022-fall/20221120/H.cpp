#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
void Mul(int &x, int y) {
	x = mul(x, y);
}
int add(int x, int y) {
	return (x + y) % mod;
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
	ios::sync_with_stdio(0);
	cin.tie(0);
	int mx = 1005;
	vector<int> f(mx), ny(mx);
	for(int i = 1; i < mx; ++i) ny[i] = q_pow(i, mod - 2);
	f[1] = 0;
	for(int i = 1; i < mx; ++i) {
		for(int j = i + 1; j < mx; ++j) {
			Add(f[j], mul(ny[j - 1], add(1, f[i])));
//			if(j == 3) cerr << "!!"<< i << " " << f[j] << "\n";
		}
	}
	int T;
	cin >> T;
	for(int o = 1; o <= T; ++o) {
		int n, k;
		cin >> n >> k;
//		cerr << "!!! " << f[k + 1] << "\n";
		cout << mul(n, f[k + 1]) << "\n";
	}
	return 0;
}