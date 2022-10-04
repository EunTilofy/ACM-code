#include<bits/stdc++.h>
#define ls x << 1
#define rs x << 1 | 1
#define REP(i,a,b) for(int i=(a);i<(b);++i)
#define DREP(i,a,b) for(int i=(a);i>(b);--i)
using namespace std;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
const int MN = 1e5 + 5, mod = 998244353;
int n, q;
char s[MN];
int a[MN], fac[MN], inv[MN];
int add(int x, int y) { return (x + y) % mod; }
void Add(int &x, int y) { x = add(x, y); }
int mul(int x, int y) { return 1ll * x * y % mod; }
void Mul(int &x, int y) { x = mul(x, y); }
int C(int x, int y) {
	if(x < y) return 0;
	return mul(fac[x], mul(inv[y], inv[x - y]));
}

struct tree {
	int v[MN];
	int lower(int x) { return x & (-x); }
	void upd(int x, int k) {
		for(; x < MN; x += lower(x))
			v[x] += k;
	}
	int ask(int x) {
		int ans = 0;
		for(; x; x -= lower(x))
			ans += v[x];
		return ans;
	}
} t;

struct node {
	void init() {
		memset(nm, 0, sizeof nm);
	}
	int nm[4][4];
} tr[MN << 2];
int lazy[MN << 2];

node merge(node A, node B, int x, int y) {
	node res; res.init();
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			res.nm[i][j] = add(A.nm[i][j], B.nm[i][j]);
	res.nm[x][y]++;
	return res;
}

void build(int x, int l, int r) {
	if(l == r) {
		tr[x].init();
		lazy[x] = 0;
		return ;
	}
	int mid = (l + r) >> 1;
	build(ls, l, mid), build(rs, mid + 1, r);
	tr[x] = merge(tr[ls], tr[rs], a[mid], a[mid + 1]);
}

node go(node A, int k) {
	node res; res.init();
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j) {
			int x = (i + k) % 4, y = (j + k) % 4;
			Add(res.nm[x][y], A.nm[i][j]);
		}
	return res;
}

void pushdown(int x) {
	if(lazy[x]) {
		lazy[ls] += lazy[x];
		tr[ls] = go(tr[ls], lazy[x]);
		lazy[rs] += lazy[x];
		tr[rs] = go(tr[rs], lazy[x]);
	}
	lazy[x] = 0;
}

int cal(int id) {
	int k = t.ask(id);
//	printf("id = %d, k = %d\n", id, k);
	return (a[id] + k) % 4;
}

void print(node res) {
	for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
			printf("[%d][%d] = %d\n", i, j, res.nm[i][j]);
}

void upd(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		lazy[x]++;
		tr[x] = go(tr[x], 1);
//		printf("!! l = %d, r = %d\n", l, r);
//		print(tr[x]);
		return ;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(R <= mid) upd(ls, l, mid, L, R);
	else if(L > mid) upd(rs, mid + 1, r, L, R);
	else upd(ls, l, mid, L, R), upd(rs, mid + 1, r, L, R);
	tr[x] = merge(tr[ls], tr[rs], cal(mid), cal(mid + 1));
//	printf("l = %d, r = %d %d %d\n", l, r, cal(mid), cal(mid + 1));
//	print(tr[x]);
}

node ask(int x, int l, int r, int L, int R) {
	if(L <= l && r <= R) {
		return tr[x];
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(R <= mid) return ask(ls, l, mid, L, R);
	else if(L > mid) return ask(rs, mid + 1, r, L, R);
	else return merge(ask(ls, l, mid, L, R), ask(rs, mid + 1, r, L, R), cal(mid), cal(mid + 1));
}

int main() {
	n = read(), q = read();
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i)
		a[i] = s[i] - 'A';
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	REP(i, 2, n + 1) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[mod % i], (mod-mod/i));
	}
	REP(i, 2, n + 1) inv[i] = mul(inv[i-1], inv[i]);
	build(1, 1, n);
	while(q--) {
		int op = read();
		if(op == 1) {
			int l = read();
			int r = read();
			t.upd(l, 1), t.upd(r + 1, -1);
			upd(1, 1, n, l, r);	
//			if(l == 2 && r == 3) printf("???cal = %d\n", cal(2));
		} else {
			int l = read(), r = read(), k = read();
			node res = ask(1, 1, n, l, r);
			int ans = 0;
			for(int i = 0; i < 4; ++i)
				for(int j = 0; j <= i; ++j) {
//					printf("[%d][%d] = %d\n", i, j, res.nm[i][j]);
					Add(ans, res.nm[i][j]);
				}
//			printf("ans = %d\n", ans);
			if(k - 1 - ans < 0 || r - l - ans < 0) puts("0");
			else printf("%d\n", C(r - l - ans, k - 1 - ans));
		}
	}
	return 0;
}