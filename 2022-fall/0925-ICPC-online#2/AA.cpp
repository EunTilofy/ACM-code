#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n, k;scanf("%d%d", &n, &k);
	long long ans = 0;
	while(k != 2 && n) {
		ans += k, --n;
		for(int i = 2; ; ++i) {
			if(gcd(i, k) == 1) {
				k = i;
				break;
			}
		}
	}
	ans += n / 2 * 5 + (n & 1) * 2;
	printf("%lld\n", ans);
	return 0;
}