#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #define int long long
#define db double
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define y1 y1111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x<<1) + (x<<3) + ch - '0'; ch = getchar();}
	return x * f;
}
const int N = 5010, MN = 3e5 + 5;
vector<int> g[N];
int n, m, k, T, dia = 0;
int d[N][N];
std::queue<int> q;
#define inf 0x3f3f3f3f
void bfs(int x) {
	d[x][x] = 0;
	q.push(x);
	while(!q.empty()) {
		int o = q.front(); q.pop();
		REP(i, 0, g[o].size()) {
			int y = g[o][i];
			if(d[x][y] == inf) d[x][y] = d[x][o] + 1, q.push(y);
		}
	}
}
signed main() {
	n = read(), m = read(), k = read();
	for(int i = 1, x, y; i <= m; ++i) {
		x = read(), y = read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	// if(k == 1) {
	// 	for(int i = 1; i <= n; ++i) {
	// 		if(g[i].size()) {
	// 			printf("2\n%d %d", i, g[i][0]);
	// 			return 0;
	// 		}
	// 	}
	// }
	for(int i = 1; i <= n; ++i) {
		memset(d[i], 0x3f, sizeof(d[i]));
		bfs(i);
	}
	bool fl = 1;
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) fl &= (d[i][j] <= n - k);
	if(fl == 1) {
		printf("%d\n", n);
		for(int i = 1; i <= n; ++i) printf("%d ", i);
	}
	else puts("0");
	return 0;
}