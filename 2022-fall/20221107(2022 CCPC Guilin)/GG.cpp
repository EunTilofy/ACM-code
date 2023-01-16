#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int val[N];
vector<int> G[N];
int f[N];

int ans = 0;
int g[N];
void predfs(int u, int fa) {
	int pos = 0;
	for(int v : G[u]) {
		if(v == fa) continue;
		predfs(v, u);
		f[u] = max(f[v], f[u]);
		g[u] = max(g[u], pos + f[v]);
		pos = max(pos, f[v]);
	}
	g[u] += val[u];
	for(int v : G[u]) if(v != fa) g[u] = max(g[u], g[v]);
	f[u] += val[u];
}

bool cmp(int x, int y) {return x > y;}
void dfs(int u, int fa, int vv, int dv, int len) {
	vector<int> p;
	multiset<int> s;
	for(int v : G[u]) {
		if(v == fa) continue;
		s.insert(f[v]);
		p.push_back(f[v]);
	}
	for(int v : G[u]) {
		if(v == fa) continue;
		s.erase(s.find(f[v]));
		int pos = 0;
		if(s.size() >= 2) {
			multiset<int> :: iterator it;
			it = s.end(), --it, pos = *it;
			--it, pos += *it;
		} else if(s.size()) pos = *s.rbegin();
		int tmp = max(dv, pos + val[u]);
//		cerr << v << " " << g[v] << " " << tmp <<  " " << pos << "\n";
		ans = max(ans, g[v] + tmp);
//		cerr << v << " " << g[v] << " " << pos << " " << g[v] + pos + val[u] << "\n";
		int cur = max(vv + val[u] + (s.size() ? *s.rbegin() : 0), len);
		ans = max(ans, cur + g[v]);
		dfs(v, u, max(vv, s.size() ? *s.rbegin() : 0) + val[u], tmp, cur);
		s.insert(f[v]);
	}
	p.push_back(vv);
	sort(p.begin(), p.end(), cmp);
	int cur = 0;
	for(int i = 0; i < min(4, (int)p.size()); ++i) {
		cur += p[i];
		if(i < 3) ans = max(ans, cur + val[u]);
	}
	ans = max(ans, cur);
}

void Dfs(int u, int fa, int vv) {
//	cerr << u << " " << fa << " " << vv << "\n";
	ans = max(ans, g[u] + vv);
	multiset<int> s;
	for(int v : G[u]) {
		if(v == fa) continue;
		s.insert(g[v]);
	}
	for(int v : G[u]) {
		if(v == fa) continue;
		s.erase(s.find(g[v]));
		Dfs(v, u, max(vv, s.size() ? *s.rbegin() : 0));
		s.insert(g[v]);
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> val[i];
	if(n == 1) {
		cout << "0" << "\n";
		return 0;
	}
	for(int i = 1, x, y; i < n; ++i) {
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int gen = 1;
	predfs(gen, 0);
	dfs(gen, 0, 0, 0, 0);
	Dfs(gen, 0, 0);
	cout << ans << "\n";
	return 0;
}
/*
7
1 2 3 4 5 6 7 
1 2
1 5
2 3
2 4
5 7
5 6
*/