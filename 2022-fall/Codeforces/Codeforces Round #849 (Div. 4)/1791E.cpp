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

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    long long ans = 0;
    long long num = 0, mn = 10000000000ll, _ = 0, num0 = 0, mx = 10000000000ll;
    for(int i = 1; i <= n; ++i) {
        ans += a[i];
        if(a[i] < 0) num += -a[i], ++_, mn = min(mn, (ll)(-a[i]));
        if(a[i] >= 0) {
            ++num0;
            mx = min(mx, (ll)a[i]);
        }
    }
    // cout << ans << num << mn << endl;
    if(_%2 == 0) {
        cout << ans + num + num << endl;
    } else if(num0 > 0) {
        // cout << mn << " " << mx << endl;
        cout << ans + 2ll*(num-mn) + max(0ll, mn-mx)*2ll << endl;
    }   else {
        // cout << "ss" << endl;
        cout << ans + 2ll * (num - mn) << endl;
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}