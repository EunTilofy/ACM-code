#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N][N];

void solve() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= min(100, n); ++i) {
		for(int j = 1; j <= i; ++j)
			scanf("%d", &a[i][j]);
	}
	int q; scanf("%d", &q);
	for(int o = 1, x; o <= q; ++o) {
		scanf("%d", &x);
		int ans = 0;
		if(n <= 100) {
			for(int i = 1; i <= n; ++i) {
				ans = (1ll * ans * 10 % x + a[n][i]) % x;
			}
		} else {
			int pos = 1;
			for(int i = 1; i <= x - 1; ++i) {
				int l = (n - i) / (x - 1) * (x - 1) + i;
				l = n - l + 1;
//				printf("%d %d\n", l, x - 1);
				ans = (ans + 1ll * a[x - 1][l] * pos % x) % x;
				pos = 1ll * pos * 10 % x;
			}
		}
		printf("%d\n", ans);
	}
}

int main() {
	int T; scanf("%d", &T);
	for(int o = 1; o <= T; ++o) {
		solve();
	}
	return 0;
}