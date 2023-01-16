#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long gcd(long long x,long long y) {
	return y?gcd(y,x%y):x;
}
const int N = 2e6 + 10;
int qz[N];
int mx;

ll solve(ll l) {
	ll L = (l - 1) / mx;
	int posl = (l - 1) % mx + 1;
	return L * qz[mx] + qz[posl];
}

int main() {
	int x, n;
	cin >> x >> n;
	mx = 0;
	for(int i = 1; ; ++i) {
		if((1 << i) >= x) {mx = 1 << i; break;}
	}
	for(int i = 1; i <= mx; ++i) {
		qz[i] = qz[i - 1] + (gcd((1ll * i * x) ^ x, x) == 1);
	}
	for(int o = 1; o <= n; ++o) {
		ll l, r;
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << "\n";
	}
	return 0;
}