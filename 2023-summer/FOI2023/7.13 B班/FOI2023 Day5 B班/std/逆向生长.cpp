#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MN = 2e5 + 5, K = 19;
int n, q, x, y, opt, A, B, ans, f[MN];

int F(int x) {
	return x^(A*ans+B)^ans;
}

int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}

vector<int> e[MN][K];
int fa[MN][K];

int dep(int x) {
	int res = 0;
	for(int i = 18; ~i; --i) if(fa[x][i]) {
		x = fa[x][i];
		res |= 1 << i;
	}
	return res;
}

int lca(int x, int y) {
	int dx = dep(x), dy = dep(y);
	if(dx < dy) swap(x, y), swap(dx, dy);
	int t = dx - dy;

	for(int i = 18; ~i; --i) if(t>>i&1) x = fa[x][i];
	if(x == y) return x;
	for(int i = 18; ~i; --i) if(fa[x][i] != fa[y][i])
		x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

void dfs(int x, int y, int i) {
	for(auto son : e[y][i]) {
		fa[son][i + 1] = x;
		e[x][i + 1].push_back(son);
		dfs(x, son, i + 1);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);

	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> x, f[x] = x;

	cin >> q >> A >> B;

	while(q--) {
		cin >> opt;
		if(opt == 1) {
            int s;
			cin >> x >> s;
			x = F(x); f[x] = x;
			while(s --) {
				cin >> y, y = F(y), f[y] = x;
                fa[y][0] = x;
				e[x][0].push_back(y);
				dfs(x, y, 0);
			}
		}
        else {
				cin >> x >> y;
				x = F(x), y = F(y);
				if(find(x) != find(y)) ans = 0, cout << "0\n";
				else{
					ans = lca(x, y);
					cout << ans << '\n';
				}
			}
	}
	return 0;
}