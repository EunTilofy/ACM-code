#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
long long sol(long long N) {
	long long l = 1, r;
	__int128 ans = 0;
	for(;l <= N; l = r + 1) {
		r = (N/(N/l));
		r = min(r, N);
//		printf("%d %d\n", l, r);
		__int128 ret1 = 1ll * (l + r);
		ret1 *= (r - l + 1ll);
		ret1 /= 2;
		__int128 ret2 = 1ll * (N / l + 1);
		ret2 *= (N / l);
		ret2 /= 2;
		ret1 = ret1 % mod * ret2 % mod;
 		ans = (ans + ret1) % mod;
//		printf("%d %d\n", ret1, ret2);
	}
	return ans % mod;
}
signed main() {
	long long L, R;
	scanf("%lld%lld", &L, &R);
	printf("%lld\n", (sol(R) - sol(L - 1) + mod) % mod);
	return 0;
}