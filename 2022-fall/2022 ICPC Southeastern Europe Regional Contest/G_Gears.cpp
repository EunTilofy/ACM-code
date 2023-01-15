#include"bits/stdc++.h"
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
const int MN = 5e5 + 5;
int a[MN], b[MN], c[MN], d[MN], e[MN], f[MN];

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i]; sort(b+1, b+n+1);
    for(int i = 2; i <= n; ++i) c[i] = a[i] - a[i - 1];
    for(int i = 2; i <= n; ++i) d[i] = d[i-2] - c[i-1] + c[i];

    // for(int i = 1; i <= n; ++i) cout << d[i] << " "; cout << endl;

    int pos[2] = {2, 1};
    for(int i = 3; i <= n; ++i) if(d[i] < d[pos[i&1]]) pos[i&1] = i;

    // cout << pos[0] << " " << pos[1] << endl;

    e[pos[0]] = b[1];
    for(int i = pos[0] + 1; i <= n; ++i) e[i] = c[i] - e[i - 1];
    for(int i = pos[0]; i >= 2; --i) e[i - 1] = c[i] - e[i];
    for(int i = 1; i <= n; ++i) f[i] = e[i];
    sort(f+1, f+n+1);
    bool fl = 1;
    for(int i = 1; i <= n; ++i) fl &= f[i] == b[i];
    if(!fl) {
        e[pos[1]] = b[1];
        for(int i = pos[1] + 1; i <= n; ++i) e[i] = c[i] - e[i - 1];
        for(int i = pos[1]; i >= 2; --i) e[i - 1] = c[i] - e[i];
    }
    for(int i = 1; i <= n; ++i) cout << e[i] << " ";
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	// int T;
	// cin>>T;
	// while(T--)
        solve();
}