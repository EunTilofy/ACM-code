#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

const int M = 1e3 + 10;
int a[M * M][4], ans[M][M];

void dfs(int x, int y, int nw) {
	if(ans[x][y]) return ;
//	cerr << x << " " << y << " " << nw << "\n";
	ans[x][y] = nw;
	for(int i = 0; i < 4; ++i) {
		if(a[nw][i] == -1) continue;
		int xx = x + dx[i], yy = y + dy[i];
		dfs(xx, yy, a[nw][i]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m, be = -1;
	cin >> m;
	for(int i = 1; i <= m * m; ++i) {
		int pos = 0;
		for(int j = 0, val; j < 4; ++j) {
			cin >> a[i][j];
			if(a[i][j] != -1) pos |= (1 << j);
		}
		if(pos == 10) be = i;
	}
	if(m == 1) cout << "1\n";
	else {
		dfs(1, 1, be);
		for(int i = 1; i <= m; ++i) {
			for(int j = 1; j <= m; ++j) {
				cout << ans[i][j];
				if(j != m) cout << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}