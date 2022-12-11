#include<bits/stdc++.h>
using namespace std;
const int mod = 998244853;
const int N = 3e5 + 10;
map<int, int> mp[N], sz[N];
int add(int x, int y) {
	return (x + y) % mod;
}
void Add(int &x, int y) {
	x = add(x, y);
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cerr << mul(50, q_pow(3, mod - 2)) << "\n";
//	cerr << mul(115, q_pow(6, mod - 2)) << "\n";
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1, x, y, z; i <= m; ++i) {
		cin >> x >> y >> z;
		if(x > y) swap(x, y);
		mp[x][y] += z, sz[x][y]++;
	}
	vector<int> p(k);
	for(int i = 0; i < k; ++i) cin >> p[i];
	int ans = 0;
	for(int i = 1; i < k; ++i) {
		int x = p[i - 1], y = p[i];
		if(x > y) swap(x, y);
		if(!mp[x].count(y)) {
			cout << "Stupid Msacywy!\n";
			return 0;
		}
		int pos = mul(mp[x][y], q_pow(sz[x][y], mod - 2));
		Mul(ans, 10);
		Add(ans, pos);
//		cerr << mp[x][y] << " " << sz[x][y] << "\n";
//		cerr << pos << " " << mul(ans, 10) << "\n";
	}
	cout << ans << "\n";
	return 0;
}