#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
// int a[MN], b[MN], c[MN];
vector<pair<int, pii>> edge;
set<int> G[MN];
int fa[MN];
int getf(int x) {
    return fa[x] == x ? x : fa[x] = getf(fa[x]);
}

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        cin >> m;
        if(i < j) {
            edge.pb({-m, {i, j}});
        }
    }
    for(int i = 1; i <= n; ++i) fa[i] = i;
    sort(all(edge));
    long long ans = 0;
    for(auto o : edge) {
        int x = o.se.fi, y = o.se.se, w = -o.fi;
        if(getf(x) != getf(y)) {
            ans += w;
            fa[getf(x)] = getf(y);
            G[x].insert(-y);
            G[y].insert(-x);
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= n; ++i) fa[i] = i;
    for(int i = n; i > 1; --i) {
        int ii = getf(i);
        int jj = -*(G[ii].upper_bound(-i));
        cout << i << " " << jj << endl;
        jj = getf(jj);
        if(G[jj].size() > G[ii].size()) swap(ii, jj);
        fa[jj] = ii;
        for(auto y : G[jj]) G[ii].insert(y);
        G[jj].clear();
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	// int T;
	// cin>>T;
	// while(T--)
        solve();
}