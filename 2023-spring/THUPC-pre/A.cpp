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
int a[MN], siz[MN], dep[MN];
vector<int> G[MN];
void dfs(int x) {
    siz[x] = 1;
    for(auto y : G[x]) {
        dep[y] = dep[x]+1;
        dfs(y);
        siz[x] += siz[y];
    }
}
void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        G[x].pb(i);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        a[i] = -a[i]+siz[i]-1-dep[i];
        // cout << a[i] << " " << dep[i] << endl;
    }
    sort(a+1,a+n+1);
    long long ans = 0;
    for(int i = n; i >= 1; i -= 2) {    
        ans += a[i];
    }
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	solve();
}