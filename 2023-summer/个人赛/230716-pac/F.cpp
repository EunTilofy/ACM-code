#include<bits/stdc++.h>
using namespace std;
const int MN = 3e5+5;

int n, m;
int a[MN], b[MN];
vector<int> G[MN];

set<pair<int, int>> S[MN];
int id[MN], siz[MN];

void dfs(int x, int f) {
	id[x] = x;
	siz[x] = 0;
	for(auto y : G[x]) if(y != f) {
		dfs(y, x);
		b[x] += b[y];
		if(siz[x] < siz[y]) {
			for(auto item : S[id[x]]) {
				S[id[y]].insert(item);
			}
			S[id[x]].clear();
			id[x] = id[y];
		} else {
			for(auto item : S[id[y]]) {
				S[id[x]].insert(item);
			}
			S[id[y]].clear();
		}
		siz[x] += siz[y];
	}
	if(siz[x] < b[x]) S[id[x]].insert({a[x],x}), ++siz[x];
	else {
		if(!S[id[x]].empty() && S[id[x]].begin()->first < a[x]) {
			S[id[x]].erase(*S[id[x]].begin());
			S[id[x]].insert({a[x], x});
		}
	}
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= m; ++i) {
		int x;
		cin >> x;
		++b[x];
	}
	for(int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	dfs(1,0);
	long long ans = 0;
	for(auto item : S[id[1]]) ans += item.first;
	cout << ans << endl;
	return 0;
}
