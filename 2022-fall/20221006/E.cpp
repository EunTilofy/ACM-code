#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
vector<int> G[N];
ll f[N][2], sum[N];

ll ans = 0;
void dfs(int x, int fa) {
	f[x][0] = 1;
	for(auto y : G[x]) {
		if(y == fa) continue;
		dfs(y, x);
		ans += sum[x] * (f[y][0] + f[y][1]) + sum[y] * (f[x][0] + f[x][1]);
		ans += f[y][0] * f[x][0];
		sum[x] += sum[y] + f[y][0];
		f[x][1] += f[y][0];
		f[x][0] += f[y][1];
	}
//	printf("x = %d, %lld %lld %lld\n", x, f[x][0], f[x][1], sum[x]);
//	ans += sum[x];
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1, x, y; i < n; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}