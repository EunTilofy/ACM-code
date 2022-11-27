#include<bits/stdc++.h>
using namespace std;
const int p = 37, mod = 998244353;
map<int, int> mp[2];

int Min(int x, int y) {
	if(x == -1) return y;
	else if(y == -1) return x;
	return min(x, y);
}
const int N = 5010;
int f[N][2];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	vector<int> cnt(2);
	for(int o = 0; o < 2; ++o) {
		cin >> cnt[o];
//		cerr << cnt[0] << "\n";
		for(int i = 0; i < cnt[o]; ++i) {
			string s;
			cin >> s;
			int pos = 0;
			for(auto ch : s) {
				pos = (1ll * pos * p % mod + (ch - 'a' + 1)) % mod;
			}
//			cerr << pos << "\n";
			mp[o][pos] = 1;
		}
	}
	string s;
	cin >> s;
	int n = s.size();
	s = '0' + s;
//	cerr << s << "\n";
	memset(f, -1, sizeof f);
	f[0][1] = f[0][0] = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 2; ++j) {
			if(f[i][j] == -1) continue;
			int pos = 0;
			for(int k = i + 1; k <= n; ++k) {
				pos = (1ll * pos * p % mod + (s[k] - 'a' + 1)) % mod;
//				if(i == 0 && k == 6) cerr << "pos = " << pos << "\n";
				if(mp[1 ^ j][pos]) {
					f[k][1 ^ j] = Min(f[k][1 ^ j], f[i][j] + 1);
//					cerr << k << " " << (1 ^ j) << " " << f[k][1 ^ j] << "\n";
				}
			}
		}
	}
//	cerr << f[n][0] << " " << f[n][1] << "\n";
	cout << Min(f[n][0], f[n][1]) << "\n";
	return 0;
}