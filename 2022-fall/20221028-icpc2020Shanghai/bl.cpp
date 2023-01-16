#include<bits/stdc++.h>
using namespace std;
double n, p1, p2, v1, v2;

const int N = 11;
int f[N][N];

int vs[N], a[N];
void dfs(int nw, int n) {
	if(nw > n) {
		for(int k = 1; k <= n; ++k) {
			int flg = 1;
			for(int i = k + 1; i <= n; ++i) {
				int mn = 11111;
				for(int j = i - k; j <= i - 1; ++j) mn = min(mn, a[j]);
				if(a[i] <= mn) {flg = 0; break;}
			}
			f[n][k] += flg;
		}
		return;
	} 
	for(int i = 1; i <= n; ++i) {
		if(!vs[i]) {
			vs[i] = 1;
			a[nw] = i;
			dfs(nw + 1, n);
			vs[i] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	for(int i = 1; i <= 10; ++i) {
		dfs(1, i);
	}
	for(int i = 1; i <= 10; ++i) {
		for(int j = 1; j <= i; ++j)
			cout << f[i][j] << " ";
		cout << "\n";
	}
	return 0;
}

/*
1
1 2
1 4 6
1 10 18 24
1 26 66 96 120
1 76 276 456 600 720
1 232 1212 2472 3480 4320 5040
1 764 5916 14736 22800 29520 35280 40320
1 2620 31068 92304 164880 225360 277200 322560 362880
1 9496 171576 632736 1285920 1890720 2409120 2862720 3265920 3628800
*/