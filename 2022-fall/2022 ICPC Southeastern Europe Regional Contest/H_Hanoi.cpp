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
vector<pii> ans;
vector<int> a[4];
void mv(int x, int y) {
    a[y].pb(a[x].back()); a[x].pop_back();
    ans.pb({x, y});
}
void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[1].pb(x);
    }
    while(a[1].size()) {
        if(a[3].size() == 0 || a[1].back() < a[3].back()) {
            mv(1, 3);
            continue;
        } else {
            mv(1, 2);
            while(a[3].size() && a[3].back() < a[2].back()) mv(3, 1);
            mv(2, 3);
        }
    }
    cout << ans.size() << endl;
    for(auto o : ans) cout << o.fi << " " << o.se << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	// int T;
	// cin>>T;
	// while(T--)
        solve();
}