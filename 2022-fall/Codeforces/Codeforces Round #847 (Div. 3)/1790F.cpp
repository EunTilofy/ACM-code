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
int a[MN], b[MN], c[MN];
vector<int> G[MN];
int ans;
bool vis[MN];

void dfs(int x, int d) {
    // cout << "dfs" << x << d << endl;
    vis[x] = 1;
    if(d >= ans || d >= b[x]) {
        vis[x] = 0;
        return ;
    }
    if(d > 0) {
        // cout <<endl<< "mk" << x << d << endl;
        b[x] = min(b[x], d);
    }
    for(auto y : G[x]) if(!vis[y]){
        dfs(y, d + 1);
    }
    vis[x] = 0;
}

void solve(){
	int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
        a[c[i]] = i;
    }
    for(int i = 1; i <= n; ++i) b[i] = n, G[i].clear();
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    ans = n;

    // for(int i = 1; i <= n; ++)
    // cout << "=----------" << c[1] << endl;

    dfs(c[1], 0);
    for(int i = 2; i <= n; ++i) {
        // cout << b[c[i]] << "sss" << endl;
        dfs(c[i], 0);
        ans = min(ans, b[c[i]]);
        cout << ans << " ";
    }
    cout << endl;
    return ;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}