#include<bits/stdc++.h>
using namespace std;
#define y1 y111111111
#define int long long
int exgcd(int a, int b, int &x, int &y) {
	if(!b) return x = 1, y = 0, a;
	int d = exgcd(b, a % b, x, y) , t = x;
	return x = y, y = t - a/b*y, d;
}
signed main() {
	int T;
	scanf("%lld", &T);
	for(int o = 1; o <= T; ++o) {
		int x1, y1, x2, y2;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		if(x1 - x2 == y1 - y2) {
			printf("%lld %lld\n", x1 + 1, y1);
			continue;
		}
		if(x1 == x2) {
			printf("%lld %lld\n", x1 + 1, y1);
			continue;
		}
		if(y1 == y2) {
			printf("%lld %lld\n", x1, y1 + 1);
			continue;
		}
		int dx = abs(x1 - x2);
		int dy = abs(y1 - y2);
		int g = __gcd(dx, dy);
		dx /= g;
		dy /= g;
		int a, b;
		exgcd(dx, dy, a, b);
		a = abs(a) * ((y2 - y1)/abs(y2 - y1));
		b = abs(b) * ((x2 - x1)/abs(x2 - x1));
		printf("%lld %lld\n", x1 + b, y1 + a);
	}
	return 0;
}