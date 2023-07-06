#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int N = 2e5 + 10;
int col[N], mk[N], f[N], vs[N], vv[N];
map<int, int> mp[N];
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
//				cerr << z << "\n";
				// z, f[z];
				mk[mp[z][f[z]]] = 1;
			}
			mk[id] = 1, flg = 1;
			return ;
		} else {
			dfs(y, x);
		}
	}
}

multiset<int> a[N];
bool check(int x, int y) {
	return a[x].find(y) != a[x].end();
} 

void solve(int o) {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		G[i].clear(), mp[i].clear(), a[i].clear();
		vs[i] = vv[i] = 0, f[i] = 0, col[i] = 0, mk[i] = 0;
	}
	for(int i = 1, x, y, c; i <= n; ++i) {
		cin >> x >> y >> c;
		mp[x][y] = mp[y][x] = i, col[i] = c;
		G[x].push_back({y, i});
		G[y].push_back({x, i});
	}
	flg = 0, dfs(1, 0);
	multiset<int> s;
	for(int i = 1; i <= n; ++i) {
		if(mk[i]) {
			s.insert(col[i]);
//			cerr << i << "\n";
		}
		for(auto [y, id] : G[i]) a[i].insert(col[id]);
	}
	
	for(int i = 1; i <= n; ++i) vs[i] = 0;
	int ans = 0;
	queue<int> q;
	for(int i = 1; i <= n; ++i) for(auto[y, id] : G[i]) if(!vs[id]){
		++ans, vs[id] = 1;
		int z = col[id];
		q.push(i), q.push(y);
		vv[y] = 1;
		while(q.size()) {
			int u = q.front(); q.pop();
			for(auto[v, _] : G[u]) if(col[_] == z && !vs[_]) {
				vs[_] = 1, q.push(v);
			} 
		}
	}
//	cerr <<"ans = " <<  ans << "\n";
	cout << "Case #"<<o<<": \n";
	for(int o = 1, x, y, c; o <= m; ++o) {
		cin >> x >> y >> c;
		int id = mp[x][y];
		if(col[id] != c) {
//			cerr<<"change\n";
			if(mk[id]) {
				if((*s.begin()) == (*s.rbegin())) {
//					cerr << "www\n";
					
					s.erase(s.find(col[id]));
					a[x].erase(a[x].find(col[id])), a[y].erase(a[y].find(col[id]));
					
					col[id] = c, s.insert(col[id]);
					int f1 = check(x, col[id]), f2 = check(y, col[id]);
//					cerr << f1 << " " << f2 << "\n";
					if(f1 && f2) ans--;
					else if(!f1 && !f2) ans++;
					
					a[x].insert(col[id]), a[y].insert(col[id]);
				} else {
//					cerr << "???\n";
					ans--, s.erase(s.find(col[id]));
					a[x].erase(a[x].find(col[id])), a[y].erase(a[y].find(col[id]));
					{
						int f1 = check(x, col[id]), f2 = check(y, col[id]);
//						cerr << f1 << " " << f2 << "\n";
						ans += f1 + f2;
					}
					col[id] = c, s.insert(col[id]);
					if((*s.begin()) != (*s.rbegin())) {
						int f1 = check(x, col[id]), f2 = check(y, col[id]);
//						cerr << "!!!\n" << f1 << " " << f2 << "\n";
						if(f1 && f2) ans--;
						if(!f1 && !f2) ans++;
					} 
					a[x].insert(col[id]), a[y].insert(col[id]);
				}
			} else {
				//x, y
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
				a[x].insert({col[id], id}), a[y].insert({col[id], id});
			}
		}
		cout << ans << "\n";
	}
}
int main() {
    int T;
    cin >> T;
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
*/s