#include <bits/stdc++.h>
using namespace std;

double C(int x, int y) {
	if(x < y) return 0;
	double ans = 1.0;
	for(int i = x - y + 1; i <= x; ++i) ans *= 1.0 * i / (x - i + 1);
//	cout << "XXX" << x << " " << y << " " << ans << endl;
	return ans;
}

double f[110][110];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	if(!n) return puts("0") * 0;
	double ans = 0.0;
	for(int i = 0; i <= n + m; ++i) {
		for(int x = 0; x <= min(i, n); ++x) {
			int y = i - x;
			if(!x) f[x][y] = 0;
			else if(!y) f[x][y] = x;
			else {
				//x, y
				double pr = 1.0 * x / (x + y);
				double ph = 1.0 * y / (x + y);
				double pos = pr * (1 + f[x - 1][y]) + ph * (f[x][y - 1] - 1);
				f[x][y] = max(0.0, pos);
			}
		}
	}
	printf("%.15f\n", f[n][m]);
	return 0;
}