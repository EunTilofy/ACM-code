#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 110, mod = 1e9+7;
int jc[N], ny[N];

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

int C(int x, int y) {
	if(x < 0 || y < 0) return 0;
	if(x < y) return 0;
	return mul(jc[x], mul(ny[y], ny[x - y]));
}

ll n, m;
int k;

int nm[60], ans = 0, mx = 52;
int f[60][60];

void solve() {
	memset(f, 0, sizeof f);
	f[mx + 1][k] = 1;
	for(int i = mx; i >= 0; --i) {
		int cur = (m >> i) & 1, x = nm[i];
		for(int j = 0; j <= k; ++j) {
			if(!cur) {
				Add(f[i][j], mul(f[i + 1][j], C(k - j, x)));
				if(k - x != x) Add(f[i][j], mul(f[i + 1][j], C(k - j, k - x)));
			} else {
				for(int t = 0; t <= j; ++t) {
					Add(f[i][t], mul(f[i + 1][j], mul(C(j, t), C(k - j, x - t))));
					if(k - x != x) Add(f[i][t], mul(f[i + 1][j], mul(C(j, t), C(k - j, k - x - t))));
				}
			}
		}
	}
	for(int i = 0; i <= k; ++i) {
//		cerr << i << " " << f[0][i] << "\n";
		Add(ans, f[0][i]);
	}
}

ll qz[60];
int cnt = 0;
void dfs(int dep, ll now) {
//	cerr << dep <<  " " << now << "\n";
	if(now + qz[dep] < n) return ;
	if(now > n) return ;
	if(now == n) {
//		for(int i = 0; i < 55; ++i)
//			cerr << nm[i] << " ";
//		cerr << "\n";
//		if(cnt > 10) exit(0);
		++cnt;
//		solve();
		return ;
	}
	if(dep < 0) return ;
	for(int i = 0; i <= k / 2; ++i) {
		nm[dep] = i;
		dfs(dep - 1, now + (1ll << dep) * i * (k - i));
		nm[dep] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	jc[0] = ny[0] = 1;
	for(int i = 1; i < N; ++i) jc[i] = mul(jc[i - 1], i), ny
	cin >> n >> m >> k;
//	cerr << "??\n";
	for(int i = 0; i <= k; ++i) {
//		cerr << i * (k - i) << "\n";
	}
	for(int i = 0; i <= mx; ++i) {
		if(i) qz[i] = qz[i - 1];
		qz[i] += (1ll << i) * (k / 2) * (k - k / 2);
//		cerr << i << " " << qz[i] << "\n";
	}
	dfs(mx, 0);
//	cerr << "cnt = " << cnt << "\n";
//	cout << ans << "\n";
	return 0;
}
/*
1000000000000000 1000000000000 18
*/