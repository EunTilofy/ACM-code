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
int a[MN], b[MN], c[MN];

void solve(){
	int l, r;
    cin >> l >> r;
    int nm = 1, lm = l, xx = 1;
    while(r/lm>=2) {
        ++nm;
        lm*=2;
        xx *= 2;
    }
    cout << nm << " ";
    int ans = 0;
    ans = Add(ans, (r/xx-l+1));
    if(xx > 1) {
        xx = xx/2*3;
        ans = Add(ans, Mul(max(r/xx-l+1, 0ll), nm-1));
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