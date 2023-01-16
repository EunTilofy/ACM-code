#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
vector<int> G[N];
int c[N], sz[N], son[N], dep[N];
int n, k;

map<int, int> mp[N];
multiset<pair<int, int>> S[N]; // dep color
int num;
int id[N];

void predfs(int u, int fa) {
	sz[u] = 1;
	dep[u] = dep[fa] + 1;
	for(int v : G[u]) {
		if(v == fa) continue;
		predfs(v, u);
		sz[u] += sz[v];
		if(sz[son[u]] < sz[v]) son[u] = v;
	}
	if(son[u]) id[u]=id[son[u]];
}

int ans[N];

void dfs(int u, int fa) {
	if(son[u]) {
		dfs(son[u], u);

		// cout<<"---------"<<endl;
		// cout<<son[u]<<endl;
		// for(auto o : S[id[u]]) {
		// 	cout<<o.first<<" "<<o.second<<endl;
		// }
		// cout<<"---------"<<endl;

		ans[u] = ans[son[u]];
		std::multiset<pair<int, int>> tmp;
		for(auto o : S[id[u]]) {
			int Dp = -o.first;
			int col = o.second;
			if(Dp - dep[u] > k) {
				// cerr<<Dp<<" "<<col<<endl;
				tmp.insert({-Dp, col});
				if(mp[id[u]][col] == 1) ans[u]--;
				mp[id[u]][col] -= 1;
			}
			else break;
		}
		for(auto o : tmp) S[id[u]].erase(S[id[u]].find(o));

		// cout<<"---------"<<endl;
		// cout<<son[u]<<endl;
		// for(auto o : S[id[u]]) {
		// 	cout<<o.first<<" "<<o.second<<endl;
		// }
		// cout<<"ans[u]"<<ans[u]<<endl;
		// cout<<"---------"<<endl;
	}
	for(int v : G[u]) if(v!=fa&&v!=son[u]) {
		dfs(v, u);
		std::multiset<pair<int, int>> tmp;
		for(auto o : S[id[v]]) {
			int Dp = -o.first;
			int col = o.second;
			if(Dp - dep[u] > k) {
				tmp.insert({-Dp, col});
				mp[id[v]][col] -= 1;
			}
			else break;
		}
		for(auto o : tmp) S[id[v]].erase(S[id[v]].find(o));

		// cout<<"---------"<<endl;
		// cout<<v<<endl;
		// for(auto o : S[id[v]]) {
		// 	cout<<o.first<<" "<<o.second<<endl;
		// }
		// cout<<"---------"<<endl;

		for(auto [x, y] : mp[id[v]]) {
			ans[u] += (mp[id[u]][x] == 0 && (y != 0));
			mp[id[u]][x] += y;
		} 
		for(auto o : S[id[v]]) S[id[u]].insert(o);
	}
	// cout<<"u"<<u<<"ans[u]"<<ans[u]<<endl;
	ans[u] += mp[id[u]][c[u]]==0;
	mp[id[u]][c[u]]++;
	S[id[u]].insert({-dep[u], c[u]});
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> c[i];
	for(int i = 1; i <= n; ++i) id[i] = i;
	for(int i = 1, x, y; i < n; ++i) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	predfs(1, 0);
	dfs(1, 0);
	int q;
	cin>>q;
	for(int i = 1; i <= q; ++i) {
		int x;
		cin>>x;
		cout<<ans[x]<<endl;
	}
	return 0;
}