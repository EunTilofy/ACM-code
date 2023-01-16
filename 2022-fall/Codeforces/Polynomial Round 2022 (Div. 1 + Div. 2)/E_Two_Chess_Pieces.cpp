#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
const int MN = 2e5 + 5;
#define int long long
vector<int> G[MN];
int c[MN], d[MN], fc[MN], fd[MN], n, D, dep[MN];
int fa[MN][20];
void pre_dfs(int x, int y) {
    dep[x] = dep[y] + 1;
    fa[x][0] = y;
    for(int i = 1; i < 20; ++i) if(fa[x][i-1]) {
        fa[x][i] = fa[fa[x][i-1]][i-1];
    }
    for(auto v : G[x]) if(v != y) {
        pre_dfs(v, x);
    }
}
void dfs(int x, int y) {
    fc[x] = c[x];
    fd[x] = d[x]; 
    for(auto v : G[x]) if(v != y) {
        dfs(v, x);
        fc[x] += fc[v];
        fd[x] += fd[v];
    }
}
int getf(int x, int y){
    for(int i = 19; ~i; --i) if(y>>i&1) {
        x = fa[x][i];
    }
    return x;
}
int ans = 0;
void Dfs(int x, int y) {
    for(auto v : G[x]) if(v != y) {
        if(fc[v] && fd[v]) {
            ans += 4;
            Dfs(v, x);
        }
        else if(fc[v] || fd[v]) {
            ans += 2;
            Dfs(v, x);
        }
    }
}
void solve(){
	int m1, m2;
    cin >> n; cin >> D;
    int x, y;
    for(int i = 1; i < n; ++i) {
        cin >> x >> y;
        G[x].pb(y); G[y].pb(x);
    }
    pre_dfs(1, 0);
    cin >> m1;
    for(int i = 1; i <= m1; ++i) {
        cin >> x, c[x] = 1;
        int _ = getf(x, D);
        if(_) d[_] = 1;
    }
    cin >> m2;
    for(int i = 1; i <= m2; ++i) {
        cin >> x, d[x] = 1;
        int _ = getf(x, D);
        if(_) c[_] = 1;
    }
    dfs(1, 0);
    Dfs(1, 0);
    cout << ans << endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	solve();
    return 0;
}