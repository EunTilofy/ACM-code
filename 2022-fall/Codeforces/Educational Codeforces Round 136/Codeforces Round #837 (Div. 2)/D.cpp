#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()

#define MN 3005

std::vector<int> G[MN];

int dep[MN], fa[MN][17];

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	int cc = dep[x] - dep[y];
	for(int i = 15; ~i; --i) {
		if(cc>>i&1) x = fa[x][i];
	}
	if(x == y) return x;
	for(int i = 15; ~i; --i) if(fa[x][i]>0 && fa[y][i]>0 && fa[x][i] != fa[y][i]) {
		x = fa[x][i];
		y = fa[y][i];
	}
	assert(fa[x][0] == fa[y][0] && x != y);
	return fa[x][0];
}

int LCA[MN][MN], dis[MN][MN], f[MN][MN];

void dfs(int x, int f) {
	dep[x] = dep[f] + 1;
	// for(int i = 0; i < 15; ++i) fa[x][i] = 0;
	fa[x][0] = f;
	for(int i = 1; i < 16; ++i) if(fa[x][i - 1]) {
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	}
	for(auto o : G[x]) if(o != f) {
		dfs(o, x);
	}
}


void solve(){
	int n; cin >> n;
	string s; cin >> s;
	for(int i = 1; i <= n; ++i) dep[i] = 0;
	for(int i = 1; i <= n; ++i) memset(fa[i], 0, sizeof fa[i]);
	for(int i = 1; i <= n; ++i) G[i].clear();
	for(int i = 1; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 0);
	std::vector<pair<int, pair<int, int>>> p;
	for(int i = 1; i <= n; ++i)for(int j = 1; j <= n; ++j) f[i][j] = 1, LCA[i][j] = dis[i][j] = 0;
	int ans = 0;
	for(int i = 1; i <= n; ++i) for(int j = i; j <= n; ++j) {
		LCA[j][i] = LCA[i][j] = lca(i, j);
		// cerr<<"!"<<i<<" "<<j<<" "<<LCA[i][j]<<endl;
		dis[j][i] = dis[i][j] = dep[i] + dep[j] - dep[LCA[i][j]] - dep[fa[LCA[i][j]][0]];
		if(dis[i][j] == 2) {
			f[i][j] = 1;
			if(s[i-1] == s[j-1]) f[i][j] = 2;
			f[j][i] = f[i][j];
		}
		p.push_back({dis[i][j], {i, j}});
	}
	std::sort(all(p));

	// for(int i = 1; i <= n; ++i) {
	// 	cerr<<"\n";
	// 	for(int j = 1; j <= n; ++j) cerr<<"f["<<i<<"]["<<j<<"]="<<f[i][j]<<endl,ans = max(ans, f[i][j]);
	// }
	
	for(auto o : p) {
		int len = o.first;
		int x = o.second.first, y = o.second.second;
		// cerr<<": "<<len<<" "<<x<<" "<<y<<endl;
		ans = max(ans, f[x][y]);
		if(x == y) {
			for(int i = 0; i < G[x].size(); ++i) for(int j = i + 1; j < G[x].size(); ++j) 
				if(dis[G[x][i]][G[x][j]] == dis[x][y] + 2) {
				// cerr<<G[x][i]<<" "<<G[x][j]<<endl;
				f[G[x][i]][G[x][j]] = f[G[x][j]][G[x][i]] = 
					max(1 + (s[G[x][i]-1]==s[G[x][j]-1]) * 2, f[G[x][j]][G[x][i]]);
			}
		}
		else {
			if(LCA[x][y] == y) swap(x, y);
			for(auto o : G[y]) if(dis[o][x] == dis[x][y] + 1) {
				f[x][o] = f[o][x] = max(f[o][x], f[x][y]);
			}
			for(auto o : G[x]) if(dis[o][y] == dis[x][y] + 1) {
				// cerr<<y<<" "<<o<<endl;
				f[y][o] = f[o][y] = max(f[o][y], f[x][y]);
			}
			for(auto o : G[y]) for(auto oo : G[x]) if(dis[o][oo] == dis[x][y] + 2) {
				f[oo][o] = f[o][oo] = max(f[o][oo], f[x][y] + (s[o-1] == s[oo-1]) * 2);
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) ans = max(ans, f[i][j]);
	}
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
}