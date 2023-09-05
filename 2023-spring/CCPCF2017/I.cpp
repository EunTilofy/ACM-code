
#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int N = 2e5 + 10;
int ans = 0, col[N], mk[N], f[N], vs[N];
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
multiset<int> a[N];
void Dfs(int x, int fa) {
	for(auto[y, id] : G[x]) if(y != fa && !mk[id]) {
		Dfs(y, x);
		auto it = a[y].lower_bound(col[id]);
		++it;
		if(it != a[y].end() && (*it) == col[id]) ;
		else ++ans;
	}
}

bool check(int x, int y) {
	return a[x].find(y) != a[x].end();
} 

void solve(int o) {
	ans = 0;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		G[i].clear(), mp[i].clear(), a[i].clear();
		vs[i] = 0, f[i] = 0, col[i] = 0, mk[i] = 0;
	}
	for(int i = 1, x, y, c; i <= n; ++i) {
		cin >> x >> y >> c;
		mp[x][y] = mp[y][x] = i, col[i] = c;
		G[x].push_back({y, i});
		G[y].push_back({x, i});
	}
	multiset<int> s;
	pa.clear(), ph.clear(); 
	flg = 0, dfs(1, 0);
	for(int i = 1; i <= n; ++i) {
		if(mk[i]) s.insert(col[i]);
		for(auto [y, id] : G[i]) a[i].insert(col[id]);
	}
	for(int x : pa) {
		Dfs(x, 0);
	}
	int id = -1, sz = pa.size();
	if(m > 5) cout << ans << "aa";
	int F = (*s.begin()) == (*s.rbegin());
	for(int i = 0; i < sz; ++i) {
		int j = i;
		for(; j + 1 < sz && col[ph[j + 1]] == col[ph[j]]; ++j);
		i = j;
		++ans;
	}
	
	if(col[ph[0]] == col[ph[sz - 1]] && !F) --ans; 
	for(int i = 0; i < sz; ++i) {
		int fr = (i - 1 + sz) % sz, nx = (i + 1) % sz;
		int li = mp[pa[fr]][pa[i]], ri = mp[pa[i]][pa[nx]];
		if(col[li] != col[ri]) {
			auto it = a[pa[i]].lower_bound(col[li]);
			++it;
			if(it!=a[pa[i]].end() && (*it) == col[li]) --ans;
			it = a[pa[i]].lower_bound(col[ri]);
			++it;
			if(it!=a[pa[i]].end() && (*it) == col[ri]) --ans;
		} else {
			auto it = a[pa[i]].lower_bound(col[li]);
			++it;
			if(it!=a[pa[i]].end()) {
				++it;
				if(it!=a[pa[i]].end() && (*it) == col[li]) --ans;
			}
		}
	}
	if(m > 5) cout << ans;
	cout << "Case #"<<o<<": \n";
	for(int o = 1, x, y, c; o <= m; ++o) {
		cin >> x >> y >> c;
		
		int id = mp[x][y];
		if(col[id] != c) {
			if(mk[id]) {
				if((*s.begin()) == (*s.rbegin())) {
					s.erase(s.find(col[id]));
					a[x].erase(a[x].find(col[id])), a[y].erase(a[y].find(col[id]));
					
					col[id] = c, s.insert(col[id]);
					int f1 = check(x, col[id]), f2 = check(y, col[id]);
					if(f1 && f2) ans--;
					else if(!f1 && !f2) ans++;
					
					a[x].insert(col[id]), a[y].insert(col[id]);
				} else {
					ans--, s.erase(s.find(col[id]));
					a[x].erase(a[x].find(col[id])), a[y].erase(a[y].find(col[id]));
					{
						int f1 = check(x, col[id]), f2 = check(y, col[id]);
						ans += f1 + f2;
					}
					col[id] = c, s.insert(col[id]);
					if((*s.begin()) != (*s.rbegin())) {
						int f1 = check(x, col[id]), f2 = check(y, col[id]);
						if(f1 && f2) ans--;
						if(!f1 && !f2) ans++;
					} 
					a[x].insert(col[id]), a[y].insert(col[id]);
				}
			} else {
				a[x].erase(a[x].find(col[id])), a[y].erase(a[y].find(col[id]));
				{
					int f1 = check(x, col[id]), f2 = check(y, col[id]);
					if(f1 && f2) ans++;
					if(!f1 && !f2) ans--;				 
				}
				col[id] = c;
				{
					int f1 = check(x, col[id]), f2 = check(y, col[id]);
					if(f1 && f2) ans--;
					if(!f1 && !f2) ans++;				 
				}
				a[x].insert(col[id]), a[y].insert(col[id]);
			}
		}
		cout << ans << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
		
		solve(o);
	}
    return 0;
}
