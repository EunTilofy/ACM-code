#include <bits/stdc++.h>
bool cur1;
using namespace std;
const int N = 2e6 + 1, LOG = 22, mod = 998244353;
struct node {
	int f[10];
	void init() {
		memset(f, 0, sizeof f);
	}
} ;
node st[N * LOG];
int hz[4][4], n, q;
char s[N];

int zh(char ch) {
	if(ch == 'I') return 0;
	if(ch == 'C') return 1;
	if(ch == 'P') return 2;
}

int mul(int x, int y) {
	return 1ll * x * y % mod;
}

int add(int x, int y) {
	x += y;
	if(x >= mod) x -= mod;
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

void print(node A) {
	for(int i = 0; i < 3; ++i)
		for(int j = i; j < 3; ++j)
			printf("f[%d][%d] = %d\n", i, j, A.f[hz[i][j]]);
}
int len[N];
void Init() {
	int cnt = -1;
	for(int i = 0; i < 4; ++i)
		for(int j = i; j < 4; ++j) {
			hz[i][j] = ++cnt;
		}
	
	for(int o = 0; o <= LOG; ++o) {
		for(int i = 1; i + (1 << o) - 1 <= n; ++i) {
			++len[i];
		}
	}
	for(int i = 2; i <= n; ++i) len[i] += len[i - 1];
	for(int i = 1; i <= n; ++i) {
		node res; res.init();
		int id = zh(s[i]);
		res.f[hz[id][id]] = 1;
		if(id == 1) res.f[hz[3][3]] = 1;
		st[len[i - 1] + 1] = res;
	}
	for(int o = 1; o <= LOG; ++o) {
//		printf("??%d\n", o);
		for(int i = 1; i + (1 << o) - 1 <= n; ++i) {
			st[len[i - 1] + o + 1] = merge(st[i][o - 1], st[i + (1 << (o - 1))][o - 1]);
//			printf("??%d %d %d\n", i, i + (1 << o) - 1, o);
//			print(st[i][o]);
		}
	}
}

int u[N];
bool cur2;

int solve(int l, int r) {
	int dep = (r - l + 1), pos;
//	printf("%d %d\n", l, r);
	node res;
	res.init();
	for(int i = LOG; i >= 0; --i) {
		if(l + (1 << i) - 1 <= r) {
			res = merge(res, st[l][i]);
			l += (1 << i);
		} //else break;
	}
	return res.f[hz[0][3]];
}

int main() {
//	printf("%.10f",((&cur2)-(&cur1))/1024.0/1024);
	scanf("%d%d%s", &n, &q, s + 1);
	Init();
	int x, a, b, p;
	scanf("%d%d%d%d", &x, &a, &b, &p);
	int ans = 0;
	for(int o = 1; o <= q; ++o) {
		x = (1ll * a * x % p + b) % p;
		u[o] = x % n;
	}
	for(int o = 1; o <= q; ++o) {
		x = (1ll * a * x % p + b) % p;
		int v = x % n;
		int l = min(u[o], v) + 1, r = max(u[o], v) + 1;
		int pos = solve(l, r);
//		printf("%d %d %d\n", l, r, pos);
		Add(ans, pos);
	}
	printf("%d\n", ans);
	return 0;
}