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
const int inv2 = (mod + 1)/2, inv3 = (mod + 1)/3, inv4 = (mod * 2 + 1) / 4;
int ans = 0, dd = 0;
vector<int> G[MN];
void dfs(int x) {
    if(b[x]) return;
    // cout << "xxx" << x << endl;
    b[x] = dd;
    for(auto y : G[x]) {
        // cout << "yyy" << y << endl;
        dfs(y);
    }
}
void solve(){
	int n, m;
	cin >> n ;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    bool fl = 0;
    // bool fl1 = 1;
    // for(int i = 1; i <= n; ++i) if(a[i] != i) fl1 = 0;
    // if(fl1) {
    //     cout << 1 << endl;
    //     return;
    // }
    // for(int i = 1; i <= n; ++i) {
    //     if(a[i] == i + 1 || a[i] == i - 1) fl = 1;
    // }
    ans = n + 1;
    // ans -= fl;
    for(int i = 1; i <= n; ++i) {
        G[a[i]].pb(i);
    }
    for(int i = 1; i <= n; ++i) {
        b[i] = 0;
    }
    // cout << "pre" << ans << endl;
    for(int i = 1; i <= n; ++i) {
        if(!b[i]) --ans, ++dd, dfs(i);
    }
    for(int i = 1; i < n; ++i) {
        if(b[i] == b[i + 1]) fl = 1;
    }
    ans -= fl * 2;
    for(int i = 1; i <= n; ++i) G[i].clear();
    cout << ans << endl;
    return ;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}