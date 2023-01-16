#include "bits/stdc++.h"
using namespace std;
#define int long long
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

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    long long _;
    int ans = 1;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        //a[i]  a[j]
        int _ = a[j] - a[i];
        for(int x = 1; x * x <= _; ++x) if(_ % x == 0) {
            int y = _ / x;
            int uj = (x + y) / 2;
            int ui = y - uj;
            int c = 1ll *ui *ui - a[i];
            // cout << c << " " << ui << " " << uj << endl;

            if(c >= 0 && uj * uj - c == a[j]) {
                int xx = 0;
                for(int k = 1; k <= n; ++k) {
                    ll nm = a[k] + c;
                    ll snm = (ll)sqrt(nm);
                    if(snm*snm==nm || (snm + 1)*(snm + 1) == nm) ++xx;
                }
                ans = max(ans, xx);
            }
        }
    }
    cout << ans << endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}