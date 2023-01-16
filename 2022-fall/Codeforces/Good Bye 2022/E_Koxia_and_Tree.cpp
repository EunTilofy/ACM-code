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
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;

vector<pair<int,int>> G[MN];
int f[MN], g[MN], ff[MN], gg[MN];
const int inv2 = (mod+1)/2;
    
int n, m, ans, num[MN];

void dfs(int x, int f) {
    for(auto _ : G[x]) {
        int y = _.fi;
        int id = _.se;
        if(y == f) continue;
        dfs(y, x);
        num[x] += num[y];
        ans = Add(ans, Mul(num[y], m - num[y]));
        if(y > x) {
            ans = Add(ans, Mul((mod-num[y]+m-num[y]-1)%mod, ff[id]));
            ans = Add(ans, Mul((mod+num[y]-m+num[y]-1)%mod, gg[id]));
        }
        else {
            ans = Add(ans, Mul((mod-num[y]+m-num[y]-1)%mod, gg[id]));
            ans = Add(ans, Mul((mod+num[y]-m+num[y]-1)%mod, ff[id]));
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) g[i] = 1;
    for(int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        g[x] = 0; f[x] = 1;
        num[x] = 1;
    }
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back({y,i}), G[y].push_back({x,i});
        if(x > y) swap(x, y);
        ff[i] = Mul(inv2, Mul(f[x], g[y]));
        gg[i] = Mul(inv2, Mul(f[y], g[x]));
        int fx, gx, fy, gy;
        fx = Add(Mul(f[x], f[y]), Add(ff[i], gg[i]));
        fy = fx;
        // fx = Add(gg[i], Mul(f[x], Add(1, mod - ff[i])));
        // fy = Add(ff[i], Mul(f[y], Add(1, mod - gg[i])));
        gx = Add(1, mod - fx);
        gy = Add(1, mod - fy);
        f[x] = fx, f[y] = fy;
        g[x] = gx, g[y] = gy;
        // cerr << i << " " << x << " " << y << " " << ff[i] << " " << gg[i] << endl;
    }
    dfs(1, 0);
    cout << Mul(ans, Mul(Mul(qpow(m, mod - 2), qpow(m-1, mod-2)), 2)) << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T = 1;
	// cin>>T;
	while(T--) solve();
}