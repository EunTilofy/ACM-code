#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110, M = 1 << 20, mod = 998244353;
int st[N], f[M], len[M];

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
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> lim(m + 1);
	for(int i = 1; i < M; ++i) len[i] = len[i - (i & (-i))] + 1;
//	for(int i = 1; i <= 10; ++i) cout << i << " " << len[i] << "\n";
	for(int i = 1; i <= m; ++i) cin >> lim[i];
	int r;
	cin >> r;
	for(int o = 0, x, y; o < r; ++o) {
		cin >> x >> y;
		st[y] |= (1 << (x - 1));
	}
	f[0] = 1;
	int cnt=0;
	int all = (1 << n) - 1;
	for(int i = 1; i <= m; ++i)
		if(lim[i]<n||st[i]) {
			for(int j = all; j >= 0; --j) if(f[j]) {
					int pos = (all ^ st[i]) & (all ^ j);
//			cerr << "pos = " << pos << "\n";
					for(int k = pos; k; k = (k - 1) & pos) {
						if(lim[i] >= len[k]) {
//					cerr << k << "\n";
							Add(f[j | k], f[j]);
						}
					}
				}
		} else cnt++;
//	cerr << cnt << "\n";
	int ans=0;
	for(int i=0; i<(1<<n); i++)Add(ans,mul(f[i],q_pow(cnt , len[all^i])));
	cout << ans << "\n";
	return 0;
}

/*
3 4
1 3 2 2
3
3 3
3 4
1 1
*/