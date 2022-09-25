#include <bits/stdc++.h>
#define _FORTITY_SOURCE 0
#pragma GCC optimize(2)
#pragma GCC optimize(3)
//#pragma GCC optimize("Ofast, no-stack-protector")
//#pragma GCC target("sse, sse2, sse3, sse4, popcnt, abm, mmx, avx, tune = native")
bool cur1;
using namespace std;
const int N = 2e6 + 1, mod = 998244353;
int sz = 0;
struct node {
	int f[10];
	void init() {
		memset(f, 0, sizeof f);
	}
} tr[N * 4];
int ls[N * 4], rs[N * 4];
int hz[4][4];
char s[N];

int zh(char ch) {
	if(ch == 'I') return 0;
	if(ch == 'C') return 1;
	if(ch == 'P') return 2;
}

void Init() {
	int cnt = -1;
	for(int i = 0; i < 4; ++i)
		for(int j = i; j < 4; ++j) {
			hz[i][j] = ++cnt;
		}
}

int mul(int x, int y) {
	return 1ll * x * y % mod;
}

int add(int x, int y) {
	x += y;
	if(x > mod) x -= mod;
	return x;
}

void Add(int &x, int y) {
	x = add(x, y);
}

node merge(node A, node B) {
	node res; res.init();
	for(int i = 0; i < 4; ++i)
		for(int j = i; j < 4; ++j) {
			res.f[hz[i][j]] = 0;
			Add(res.f[hz[i][j]], add(A.f[hz[i][j]], B.f[hz[i][j]]));
			for(int k = i; k < j; ++k)
				Add(res.f[hz[i][j]], mul(A.f[hz[i][k]], B.f[hz[k + 1][j]]));
	}
	return res;			
}

void build(int x, int l, int r) {
//	printf("%d %d %d\n", x, l, r);
	if(l == r) {
		tr[x].init();
		int pos = zh(s[l]);
		tr[x].f[hz[pos][pos]] = 1;
		if(pos == 1) tr[x].f[hz[3][3]] = 1;
		return ;
	}
	int mid = (l + r) >> 1;
	ls[x] = ++sz, build(sz, l, mid);
	rs[x] = ++sz, build(sz, mid + 1, r);
	tr[x] = merge(tr[ls[x]], tr[rs[x]]);
//	printf("%d %d %d\n", x, l, r);
//	for(int i = 0; i < 4; ++i)
//		for(int j = i; j < 4; ++j)
//			printf("f[%d][%d] = %d\n", i, j, tr[x].f[hz[i][j]]);
}

node ask(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) return tr[x];
	int mid = (l + r) >> 1;
	if(R <= mid) return ask(ls[x], l, mid, L, R);
	else if(L > mid) return ask(rs[x], mid + 1, r, L, R);
	else return merge(ask(ls[x], l, mid, L, R), ask(rs[x], mid + 1, r, L, R));
}

int u[N];
bool cur2;
int main() {
	Init();
//	printf("%.10f",((&cur2)-(&cur1))/1024.0/1024);
	int n, q;
	scanf("%d%d%s", &n, &q, s + 1);
	int x, a, b, p;
	scanf("%d%d%d%d", &x, &a, &b, &p);
	int ans = 0;
	for(int o = 1; o <= q; ++o) {
		x = (1ll * a * x % p + b) % p;
		u[o] = x % n;
	}
	build(sz = 1, 1, n);
	for(int o = 1; o <= q; ++o) {
		x = (1ll * a * x % p + b) % p;
		int v = x % n;
		int l = min(u[o], v) + 1, r = max(u[o], v) + 1;
		int pos = ask(1, 1, n, l, r).f[hz[0][3]];
//		printf("%d %d %d\n", l, r, pos);
		Add(ans, pos);
	}
	printf("%d\n", ans);
	return 0;
}