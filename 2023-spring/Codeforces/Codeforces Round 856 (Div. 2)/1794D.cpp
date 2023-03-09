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
const int MN = 1e6 + 5;
int a[MN];

int pr[MN], mk[MN],tot;
void init() {
    mk[1] = 1;
    for(int i = 2; i < MN; ++i) {
        if(!mk[i]) {pr[++tot] = i;}
        for(int j = 1; j <= tot && 1ll * pr[j] * i < MN; ++j) {
            mk[pr[j]*i] = 1;
            if(i % pr[j] == 0) break;
        }
    }
}
int f[4094][4093];
int inv[MN], fac[MN];
void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= 2 * n; ++i) {
        cin >> a[i];
    }
    sort(a+1,a+2*n+1);
    vector<pii> b, c;
    for(int i = 1; i <= 2*n; ++i) {
        int j = i;
        while(j < 2*n && a[j+1] == a[j]) ++j;
        b.push_back({a[i],  j - i + 1});
        i = j;
    }
    inv[0] = inv[1] = 1; fac[0] = 1;
    for(int i = 2; i <= 2*n; ++i) inv[i] = Mul(inv[mod%i], (mod-mod/i));
    for(int i = 1; i <= 2*n; ++i) fac[i] = Mul(fac[i-1], i), inv[i] = Mul(inv[i-1], inv[i]);
    int ans = fac[n];
    for(auto x : b) {
        if(!mk[x.first]) c.push_back(x);
        else {
            ans = Mul(ans, inv[x.se]);
        }
    }
    if(c.size() == 0) {
        cout << 0;
        return;
    }
    f[0][0] = inv[c[0].se];
    f[0][1] = inv[c[0].se - 1];
    for(int i = 1; i < c.size(); ++i) {
        for(int j = 0; j <= i+1; ++j) {
            f[i][j] = Mul(f[i-1][j], inv[c[i].se]);
            if(j) f[i][j] = Add(f[i][j], Mul(f[i-1][j-1], inv[c[i].se-1]));
        }
    }
    ans = Mul(ans, f[c.size()-1][n]);
    cout << ans << endl;
}

int main(){
    init();
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	T = 1;
	while(T--) 
		solve();
}