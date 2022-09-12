#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10, LOG = 60;
ll a[N];
int n, f[N];
ll g[N], dp[N][LOG + 1];

void go() {
	for(int i = n - 1; i >= 1; --i) {
		for(int j = 1; j <= LOG; ++j) dp[i][j] = dp[i + 1][j];
		if(!g[i]) continue;
		int dep = log2(g[i] + 1);
		ll res = 1ll << (dep - 1);
		ll pos = g[i] - (1ll << dep) + 1;
		ll tmp = 0;
		if(pos) {
			dep++;
			if(pos <= res) {
				tmp = res + 1;
			} else tmp = pos + 1;
		} else pos = res;
//		printf("i = %d, dep = %d, pos = %lld, tmp = %lld\n", i, dep, pos, tmp);
		for(int j = 1; j <= dep; ++j) {
			for(int k = j; k <= LOG; ++k) {
				if(j != dep) {
					dp[i][j] = max(dp[i][j], dp[i + 1][k] + (1ll << (j - 1)));
					if(j == dep - 1 && k >= dep) 
						dp[i][j] = max(dp[i][j], dp[i + 1][k] + tmp);
				}
				else dp[i][j] = max(dp[i][j], dp[i + 1][k] + pos);
			}
//			if(j <= 3) printf("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i < n; ++i) {
		g[i] = a[i + 1] - a[i] - 1;
	}
	go();
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
//		printf("f[%d] = %d\n", i, f[i]);
		for(int j = 0; j <= LOG; ++j) {
			ans = max(ans, dp[i][j] + i);
//			if(dp[i][j] + f[i] == 10) 
//				printf("i = %d, j = %d, %lld\n", i, j, dp[i][j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}