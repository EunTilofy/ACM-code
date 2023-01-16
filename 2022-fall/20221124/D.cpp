#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define fi first
#define se second
#define int long long
typedef pair<int,int> pii;
vector<pii> G[MN];

int n, f[MN][3], g[MN], h[MN], hh[MN], fa[MN];
int sons[MN], idf[MN][3];

void dfs(int x, int F) {
	fa[x] = F;
	vector<pii> U;
	for(auto o : G[x]) {
		int y = o.fi;
		int w = o.se;
		if(y==F) continue;
		++sons[x];
		dfs(y, x);
		g[x] = max(g[x], g[y]);
		U.push_back({f[y][0] + w, y});	
	}
	std::sort(U.begin(), U.end());
	reverse(U.begin(), U.end());
	for(int i = 0; i < min(3ll, sons[x]); ++i) {
		f[x][i] = U[i].fi;
		idf[x][i] = U[i].se;
	}
	g[x] = max(g[x], f[x][0] + f[x][1]);
}
void Dfs(int x, int F, int num0, int num1) {
	h[x] = num0;
	hh[x] = num1;
	vector<pii> U;
	for(auto o : G[x]) {
		int y = o.fi;
		int w = o.se;
		if(y==F) continue;
		U.push_back({g[y], y});
	}
	std::sort(U.begin(), U.end());
	reverse(U.begin(), U.end());
	for(auto o : G[x]) {
		int y = o.fi;
		int w = o.se;
		if(y==F) continue;
		int lian = f[x][0];
		if(idf[x][0] == y) lian = f[x][1];
		int ccnt = 0, lians = 0;
		for(int i = 0; i < 3; ++i) if(idf[x][i] && idf[x][i] != y && ccnt < 2) {
			++ccnt;
			lians += f[x][i];
		}
		for(int i = 0; i < min(2ll, sons[x]); ++i) if(U[i].se != y) lians = max(lians, U[i].fi);
		lians = max(lians, h[x]+((idf[x][0]==y)?f[x][1]:f[x][0]));
		Dfs(y, x, max(lian + w, num0 + w), max(num1, lians));
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i < n; ++i) {
		int x, y, w;
		cin>>x>>y>>w;
		G[x].push_back({y,w});
		G[y].push_back({x,w});
	}
	
	int rt = 1;
	dfs(rt, 0);
	Dfs(rt, 0, 0, 0);
	
	int q;
	cin>>q;
	for(int i = 1; i <= q; ++i) {
		int x, y, w;
		cin>>x>>y;
		if(fa[y] == x) swap(x, y);
		cin>>w;
		cout<<max(w + f[x][0] + max(h[y], (idf[y][0] == x ? f[y][1] : f[y][0])), max(g[x], hh[x]))<<endl;
	}
	return 0;
}