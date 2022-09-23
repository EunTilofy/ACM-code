#include <bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x <<"="<<(x)<<" "
#define dbg2(x) cerr<<#x <<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x <<"\n"
using namespace std;
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
	return x * f;
}

const int N = 1e6 + 10;
int n, q, qz[N], nm[N];
struct node {
	int l, r;
} a[N];
char s[N];

int cal(int x) {
	return (x & 1) ? x / 2 + 2: x / 2;
}

void init() {
	for(int i = 1; i <= n; ++i)
		nm[i] = nm[i - 1] + (s[i] == '1');
	for(int i = 1; i <= n; ++i) {
		int j = i;
		for(; j <= n && s[j] == s[i]; ++j) ;
		j--;
		for(int k = i; k <= j; ++k) {
			a[k] = (node) {i, j};
			if(s[k] == '1') qz[k] = qz[i - 1] + cal(k - i + 1);
			else qz[k] = qz[i - 1];
		}	
		i = j;
	}
}

int solve(int l, int r) {
	if(s[l] == '0') {
		return qz[r] - qz[l - 1];
	} else {
		if(s[r] == '0') {
			int L = a[l].r + 1;	
			return qz[r] - qz[L - 1] + cal(a[l].r - l + 1);
		} else {
			int L = a[l].r + 1, R = a[r].l - 1;
			if(L > R) return cal(r - l + 1);
			int len = (r - l + 1) - (R - L + 1);
			return qz[R] - qz[L - 1] + cal(len);
		}
	}
}

int main() {
	n = read(), q = read();
	scanf("%s", s + 1);
	init();
	for(int o = 1, l, r; o <= q; ++o) {
		l = read(), r = read();
		int sum = r - l + 1 - (nm[r] - nm[l - 1]);
		printf("%d\n", max(0, sum - solve(l, r)) / 3);
	}	
	return 0;
}