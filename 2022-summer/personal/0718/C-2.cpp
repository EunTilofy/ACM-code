#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, LOG = 26;

int add(int x, int y) {
	return (x + y) % mod;
}
void Add(int &x, int y) {
	x = (x + y) % mod;
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
void Mul(int &x, int y) {
	x = 1ll * x * y % mod;
}
int q_pow(int x, int y) {
	int ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) Mul(ans, x);
		Mul(x, x);
	}
	return ans;
}

int f[LOG + 1][10][10], su[LOG + 1][10][10];
int lf[LOG + 1][10][10], ls[LOG + 1][10][10], pr[LOG + 1];
void init() {
	pr[0] = 10;
	for(int i = 1; i <= LOG; ++i)
		pr[i] = mul(pr[i - 1], pr[i - 1]);
	for(int i = 1; i <= 9; ++i) {
		f[0][i][i] = lf[0][i][i] = 1;
		su[0][i][i] = ls[0][i][i] = i;
	}
	for(int o = 1; o <= LOG; ++o) {
		for(int i = 1; i <= 9; ++i) 
			for(int j = i; j <= 9; ++j) { 
				lf[o][i][j] = lf[o - 1][i][j];
				ls[o][i][j] = ls[o - 1][i][j];
				for(int k = i; k <= j; ++k)
					for(int t = k; t <= j; ++t) {
					Add(f[o][i][j], mul(f[o - 1][i][k], f[o - 1][t][j]));
					int pos = mul(f[o - 1][i][k], su[o - 1][t][j]);
					int tmp = mul(mul(su[o - 1][i][k], pr[o - 1]), f[o - 1][t][j]);
					Add(su[o][i][j], add(pos, tmp));
					Add(lf[o][i][j], mul(lf[o - 1][i][k], f[o - 1][t][j]));
					Add(ls[o][i][j], mul(pr[o - 1], mul(ls[o - 1][i][k], f[o - 1][t][j])));
					Add(ls[o][i][j], mul(lf[o - 1][i][k], su[o - 1][t][j]));
				}
			}
	}
}

int da[10][10], nm[10][10], da1[10][10], nm1[10][10], Ans = 0, nw = 1;
void upd(int o) {
	for(int i = 1; i <= 9; ++i) 
		for(int j = i; j <= 9; ++j) 
			for(int k = i; k <= j; ++k) 
				for(int t = k; t <= j; ++t) {
				Add(nm1[i][j], mul(nm[i][k], f[o][t][j]));
				int pos = mul(nm[i][k], su[o][t][j]);
				int tmp = mul(mul(da[i][k], pr[o]), f[o][t][j]);
				Add(da1[i][j], add(pos, tmp));
				Add(Ans, mul(nw, mul(ls[o][i][k], nm[t][j])));
				Add(Ans, mul(da[t][j], lf[o][i][k]));
			}
	for(int i = 1; i <= 9; ++i)
		for(int j = i; j <= 9; ++j) {
			da[i][j] = da1[i][j], nm[i][j] = nm1[i][j];
			da1[i][j] = nm1[i][j] = 0;
		}
}

int main() {
	init();
	int n, be;
	scanf("%d", &n);
	for(int i = LOG; i >= 0; --i) {
		if((n >> i) & 1) {
			be = i;
			Mul(nw, pr[i]);
			break;
		}
	}
	for(int i = 1; i <= 9; ++i)
		for(int j = i; j <= 9; ++j) {
			da[i][j] = su[be][i][j], nm[i][j] = f[be][i][j];
			Add(Ans, ls[be][i][j]);
		}
	for(int i = be - 1; i >= 0; --i) {
		if((n >> i) & 1) {
			upd(i);
			Mul(nw, pr[i]);
		}
	}
//	int sum = 0;
//	for(int i = 1; i <= 9; ++i)
//		for(int j = i; j <= 9; ++j) {
//			printf("lf[%d][%d] = %d %d, ls[%d][%d] = %d\n", i, j, nm[i][j], lf[2][i][j] - nm[i][j], i, j, ls[2][i][j] - da[i][j]);
////			Add(sum, ls[2][i][j] - da[i][j]);
////			printf("lf[%d][%d] = %d, ls[%d][%d] = %d\n", i, j, nm[i][j] + lf[1][i][j], i, j, da[i][j] + ls[1][i][j]);
//		}
//	printf("%d\n", sum);
	printf("%d\n", Ans);
	return 0;
}