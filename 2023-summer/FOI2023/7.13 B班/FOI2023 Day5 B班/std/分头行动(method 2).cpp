#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int N = 5e5 + 3;
int n, d, x, y, m1, m2;
vector<int> e[N];
inline void adde(int x, int y) {
    e[x].push_back(y);
}
int dfn[N], id = 0, fa[N][19], dep[N];

void dfs(int u, int f){ // dfs，初始化倍增数组
	dfn[u] = ++id;
	fa[u][0] = f;
	for(int i = 1; i < 19; ++i) fa[u][i] = fa[fa[u][i-1]][i-1];
	for(int v : e[u]) if(v!=f) 
        dep[v] = dep[u] + 1, dfs(v, u);
}

int lca(int x,int y){
	if(dep[x] < dep[y]) swap(x,y);
	int t = dep[x] - dep[y];
	for(int i = 18; ~i; --i)
        if(t>>i&1) x=fa[x][i];
	if(x == y) return x;
	for(int i = 18; ~i; --i)
        if(fa[x][i]^fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

inline int up(int x, int k){ // k级祖先
	for(int i = 18; ~i; --i)
        if(k>>i&1) x = fa[x][i];
	return x;
}

vector<pii> a;
inline bool cmp(pii x,pii y) {
    return dfn[x.first] < dfn[y.first];
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
    
    cin >> n >> m1 >> m2 >> d;

    for(int i = 0; i < m1; ++i) cin >> x, a.push_back({x, 0});
    for(int i = 0; i < m2; ++i) cin >> x, a.push_back({x, 1});

    for(int i = 1; i < n; ++i) cin >> x >> y, adde(x, y), adde(y, x);

    dfs(1, 0);
    sort(a.begin(), a.end(), cmp);
    int now[2] = {1, 1};

	long long ans=0;
    for(int i = 0; i < m1 + m2; ++i) {
        int u = now[a[i].second], v = now[a[i].second^1], t = a[i].first;

        int p = lca(u, t), q = lca(v, t);
        int d1 = dep[u] + dep[t] - 2 * dep[p];
        int d2 = dep[v] + dep[t] - 2 * dep[q];

        u = t, ans += d1;

        if(d2 > d){
			ans += d2 - d;
			if(q == v) v = up(t, d);
			else if(q == t) v = up(v, d2 - d);
			else{
				if(dep[t] - dep[q] >= d) v = up(t, d);
				else v = up(v, d2 - d);
			}
		}
		now[a[i].second] = u;
		now[a[i].second ^ 1] = v;
    }

	ans += dep[now[0]] + dep[now[1]];
	cout << ans <<'\n';
    return 0;
}