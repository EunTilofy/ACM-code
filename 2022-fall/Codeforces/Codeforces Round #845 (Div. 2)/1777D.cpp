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
#define mod 1000000007
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN];
vector<int> G[MN];
int ans = 0;
void dfs(int x, int f) {
    b[x] = 1;
    for(auto y : G[x]) if(y != f) {
        dfs(y, x);
        b[x] = max(b[x], b[y] + 1);
    }
    ans += b[x]; ans %= mod;
}

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1;i <= n; ++i) G[i].clear();
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    ans = 0;
    dfs(1, 0);
    for(int i = 1; i < n; ++i) ans = 1ll * ans * 2 % mod;
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}