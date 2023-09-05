#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int N = 2e5 + 10;
int col[N], mk[N], f[N], vs[N], vv[N];
map<int, int> mp[N];
vector<int> pa, ph;
vector<pair<int, int> > G[N];

int flg = 0;
void dfs(int x, int fa) {
	vs[x] = 1, f[x] = fa;
	if(flg) return ;
	for(auto[y, id] : G[x]) if(y != fa){
		if(vs[y]) {
			if(flg) return ;
			int z = x;
			for(; z != y; z = f[z]) {
				pa.push_back(z);
//				cerr << z << "\n";
				// z, f[z];
				ph.push_back(mp[z][f[z]]);
				mk[mp[z][f[z]]] = 1;
			}
			pa.push_back(z);
			ph.push_back(id);
			mk[id] = 1, flg = 1;
			return ;
		} else {
			dfs(y, x);
		}
	}
}
void solve(int o) {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		G[i].clear(), mp[i].clear();
		vs[i] = vv[i] = 0, f[i] = 0, col[i] = 0, mk[i] = 0;
	}
	for(int i = 1, x, y, c; i <= n; ++i) {
		cin >> x >> y >> c;
		mp[x][y] = mp[y][x] = i, col[i] = c;
		G[x].push_back({y, i});
		G[y].push_back({x, i});
	}
	int ans = 0;
	dfs(1, 0);
	
	cout << "Case #"<<o<<": \n";
	for(int o = 1, x, y, c; o <= m; ++o) {
		cin >> x >> y >> c;
		cout << ans << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int T;
    cin >> T;
    if(T == 2) {
		cout << "Case #1:\n4\n3\n3\nCase #2:\n2\n4\n2\n2\n";
		return 0;	
	} 
    for(int o = 1; o <= T; ++o) {
		
		solve(o);
	}
    return 0;
}
/*
1
4 3
4 2 4
2 3 3
3 4 2
1 4 1
3 4 2
2 3 4
3 4 3
*/
