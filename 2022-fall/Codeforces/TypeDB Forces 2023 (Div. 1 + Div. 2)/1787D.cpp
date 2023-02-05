#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define int long long
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
int a[MN], b[MN], c[MN], n;
bool vis[MN];
vector<int> G[MN];
void dfs(int x) {
    vis[x] = 1;
    c[x] = 0;
    if(x+a[x]<1||x+a[x]>n) {
        c[x] = 1;
        return;
    }
    if(vis[x+a[x]]) {
        G[x+a[x]].pb(x);
        c[x] = c[x+a[x]];
        return;
    }
    G[x+a[x]].pb(x);
    dfs(x+a[x]);
    c[x] = c[x+a[x]];
}
void ddfs(int x) {
    b[x] = 1;
    for(auto y : G[x]) {
        ddfs(y);
        b[x] += b[y];
    }
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = c[i] = vis[i] = 0;
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i <= n; ++i) if(!vis[i]) dfs(i);
    int all = 0;
    for(int i = 1; i <= n; ++i) all+=c[i], b[i] = 0, vis[i] = 0;
    for(int i = 1; i <= n; ++i) if(i + a[i] < 1 || i + a[i] > n) {
        ddfs(i);
    }
    long long ans = 0ll, pas = 0;
    bool fl = 1;
    for(int i = 1; i >= 1 && i <= n; i += a[i]) {
        if(vis[i]) {
            fl = 0;
            break;
        }
        vis[i] = 1;
        pas ++;
        ans += n+1;
        ans += all - b[i];
    }
    if(fl) ans += 1ll * (n-pas) * (2*n+1);
    cout << ans << endl;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}