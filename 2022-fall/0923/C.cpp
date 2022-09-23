#include<bits/stdc++.h>
using namespace std;
void solve() {
	long long n;
	scanf("%lld", &n);
	if(n % 3 == 0) {printf("%lld %lld %lld\n", n/3ll, n/3ll, n/3ll);}
	else if(n % 4 == 0) {printf("%lld %lld %lld\n", n/2ll, n/4ll, n/4ll);}
	else puts("IMPOSSIBLE");
}
int main() {
	int n;
	scanf("%d", &n);
	while(n--) solve();
}