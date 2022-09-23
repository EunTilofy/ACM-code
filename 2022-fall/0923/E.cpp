#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	std::sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 2; i <= n; ++i) ans += a[i] == a[i - 1];
	return 0 * printf("%d\n", ans);
}