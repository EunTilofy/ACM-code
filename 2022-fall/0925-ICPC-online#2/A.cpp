#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int mk[N], pr[N];

void init() {
	for(int i = 2; i < N; ++i) {
		if(!mk[i]) pr[++pr[0]] = i, mk[i] = i;
		for(int j = 1; j <= pr[0] && pr[j] * i < N; ++j) {
			mk[i * pr[j]] = pr[j];
			if(i % pr[j] == 0) break;
		}
	}
}

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	ll ans = k;
	int now = n, flg = 0;
	for(int i = 1; i <= pr[0]; ++i) {
		if(now % pr[i] != 0) {
			flg = pr[i];
			break;
		}
	}
	if(!flg) flg = now;
	if(n >= 2) ans += flg;
	if(n >= 3) {
		int pos;
		if(flg == 2) pos = 3;
		else pos = 2;
		ans += pos;
		ans += 1ll * (n - 3) / 2 * 5;
		if((n - 3) & 1) ans += pos;
	}
	printf("%lld\n", ans);
	return 0;
}