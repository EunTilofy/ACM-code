#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

const int N = 1010;
int tr[N][N], a[N], all[N];

int add(int x, int y) {return (1ll * x + y) % mod;}
void Add(int &x, int y) {x = add(x, y);}

void upd(int o, int x, int k) {
	for(; x < N; x += x & (-x)) 
		Add(tr[o][x], k);
}

int get(int o, int x) {
	int ans = 0;
	for(; x; x -= x & (-x)) Add(ans, tr[o][x]);
	return ans;
}

void solve(int cas) {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), all[i] = a[i];
	sort(all + 1, all + 1 + n);
	int tot = unique(all + 1, all + 1 + n) - all - 1;
	for(int i = 1; i <= n; ++i) {
		a[i] = lower_bound(all + 1, all + 1 + tot, a[i]) - all;
	}
	upd(0, 1, 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = min(m, i) - 1; j >= 0; --j) {
			int pos = get(j, a[i]);
//			printf("i = %d, j = %d, pos = %d, a[i] = %d\n", i, j, pos, a[i]);
			upd(j + 1, a[i] + 1, pos);
		}
	}
	printf("Case #%d: %d\n", cas, get(m, tot + 1));
	for(int i = 0; i <= n + 1; ++i)
		for(int j = 0; j < N; ++j) tr[i][j] = 0;
}

int main() {
	int T;
	scanf("%d",&T);
	for(int o = 1; o <= T; ++o) {
		solve(o);
	}
	return 0;
}