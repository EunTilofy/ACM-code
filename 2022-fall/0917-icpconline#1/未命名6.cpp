#include<bits/stdc++.h>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	double ans = 0.0, cur = 1.0;
	for(int i = 1, a, b; i <= x; ++i) {
		cin >> a >> b;
		ans += cur * 1.0 * a / b * i;
		cur *= 1.0 - 1.0 * a / b;
	}
	printf("%.5f\n", ans);
}