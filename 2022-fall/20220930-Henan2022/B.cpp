#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, mod = 998244353;
char s[N];
int pw[N];

int zh(char ch) {
	if(ch == 'a') return 1;
	if(ch == 'e') return 2;
	if(ch == 'h') return 3;
	return 4;
}

int add(int x, int y) {
	return (x + y) % mod;
}
void Add(int &x, int y) {
	x = add(x, y);
}
int mul(int x, int y) {
	return 1ll * x * y % mod;
}
void Mul(int &x, int y) {
	x = mul(x, y);
}

int a[N], be, len;

class SA {
	private :
		int p, q, sa[2][N], rk[2][N], nm[N];
	public:
		void build_sa() {
			int i, j, k, mx;
			for(i = 1; i <= len; ++i) nm[a[i]]++;
			for(i = 1; i <= 4; ++i) nm[i] += nm[i - 1];
			for(i = 1; i <= len; ++i) sa[1][nm[a[i]]--]=i;
			for(i = 1; i <= len; ++i)
				rk[1][sa[1][i]] = rk[1][sa[1][i - 1]] + (s[sa[1][i - 1]] != s[sa[1][i]]);
			mx = rk[1][sa[1][len]];
			for(p = 1, q = 0, k = 1; k <= len; k <<= 1, p ^= 1, q ^= 1) {
				if(mx == len) break;
				for(i = 1; i <= len; ++i) nm[rk[p][sa[p][i]]] = i;
				for(i = len; i; --i) if(sa[p][i] > k) {
					sa[q][nm[rk[p][sa[p][i] - k]]--] = sa[p][i] - k;
				}
				for(i = len - k + 1; i <= len; ++i) sa[q][nm[rk[p][i]]--] = i;
				for(i = 1; i <= len; ++i)
					rk[q][sa[q][i]] = rk[q][sa[q][i - 1]] + (rk[p][sa[q][i]] != rk[p][sa[q][i - 1]] || rk[p][sa[q][i] + k] != rk[p][sa[q][i - 1] + k]);
				mx = rk[q][sa[q][len]];
			}
//			for(int i = 1; i <= len; ++i) 
//				printf("%d %d\n", i, sa[p][i]);
			for(int i = len; i >= 1; --i) {
//				printf("%d %d\n", i, sa[p][i]);
				if(sa[p][i] <= len / 2) {
					be = sa[p][i];
					break;
				}
			}
		}
} sa;


int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	len = n << 1;
	pw[0] = 1;
	for(int i = 1; i <= n; ++i) {
		a[i] = zh(s[i]);
		pw[i] = mul(pw[i - 1], 31);
	}
	for(int i = 1; i <= n; ++i) a[i + n] = a[i];
	sa.build_sa();
	int ans = 0;
	printf("be = %d\n", be);
	for(int i = be; i < be + n; ++i) {
		Add(ans, mul(a[i], pw[n - (i - be) - 1]));
	}
	printf("%d\n", ans);
	return 0;
}