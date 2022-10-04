#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, qz[N][26];
char s[N];

void print(int x, int y, int z) {
	for(int i = 0; i < 5; ++i)
		printf("%c", x + 'a');
	for(int i = 0; i < 7; ++i)
		printf("%c", y + 'a');
	for(int i = 0; i < 5; ++i)
		printf("%c", z + 'a');
	puts("");
	exit(0);
}

int cal(int l, int r, int pos) {
	return qz[r][pos] - qz[l - 1][pos];
}

int find(int be, int pos, int len) {
	int l = be, r = n, ans = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(cal(be, mid, pos) >= len) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 26; ++j)
			qz[i][j] = qz[i - 1][j];
		int pos = s[i] - 'a';
		qz[i][pos]++;
	}
	for(int i = 0; i < 26; ++i) 
		for(int j = 0; j < 26; ++j)
			for(int k = 0; k < 26; ++k) {
				int now = 0;
				now = find(now + 1, i, 5);
				if(now == -1) continue;
				now = find(now + 1, j, 7);
				if(now == -1) continue;
				now = find(now + 1, k, 5);
				if(now == -1) continue;
				print(i, j, k);
		}
	puts("none");
	return 0;
}