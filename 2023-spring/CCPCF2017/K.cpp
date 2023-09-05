#include<bits/stdc++.h>
using namespace std;


int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int f[110];
int vs[1010][1010], ans = 0;
int main() {
	int n;
	cin >> n;
	queue<pair<int, int> > q;
	q.push({500, 500});
	vs[500][500] = 1;
	while(q.size()) {
		ans++;
		auto[x, y] = q.front(); q.pop();
		f[vs[x][y] - 1] = ans;
		if(vs[x][y] == n + 1) continue;
		for(int o = 0; o < 8; ++o) {
			int xx = x + dx[o], yy = y + dy[o];
			if(!vs[xx][yy]) {
				vs[xx][yy] = vs[x][y] + 1;
				q.push({xx, yy});
			}
		}
	} 
	for(int i = 1; i <= n; ++i) {
		cout << "f" << i << " = " << f[i] << " "<< 14 * i * i - 6 * i + 5<< " " << f[i] - f[i - 1] << " " << (f[i + 1] - f[i] - (f[i] - f[i - 1])) << "\n";
	}
	return 0;
}
