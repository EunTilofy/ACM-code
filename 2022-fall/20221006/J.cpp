#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int nm[N];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 1, x; i <= n; ++i) {
		scanf("%d", &x);
		nm[x]++;
	}
	ll ans = 0;
	for(int i = k + 1; i < N; ++i) {
		if(!nm[i]) continue;
		for(int j = k; j < N; j += i) {
			ans += 1ll * nm[i] * nm[j];
		}
	}
	printf("%lld\n", ans);
	return 0;
}