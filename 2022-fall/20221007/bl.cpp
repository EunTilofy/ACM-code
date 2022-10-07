#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int vs[N], a[N];

int n, A, b;
void dfs(int dep) {
	if(dep > n) {
		int flg = 1;
		for(int i = 1; i <= n; ++i) {
			if(abs(a[i] - i) < A || abs(a[i] - i) > b) flg = 0;
		}
		if(flg) {for(int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");}
		return ;
	}	
	for(int i = 1; i <= n; ++i) {
		if(!vs[i]) {
			vs[i] = 1;
			a[dep] = i;
			dfs(dep + 1);
			vs[i] = 0;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &A, &b);
	dfs(1);
	return 0;
}