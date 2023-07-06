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
#define mod 1000000007
#define dbg1(x) cerr << #x << '=' << (x) << ' '
#define dbg2(x) cerr << #x << '=' << (x) << '\n'
#define dbg3(x) cerr << #x << '\n'
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e6 + 5;
int a[MN], b[MN], inv[MN];
int fac[MN], finv[MN], C[MN], C2[MN];

void solve(){
	int n;
    cin >> n;
    for(int i = 0; i <= n; ++i) cin >> a[i];
    for(int i = 0; i <= n; ++i) cin >> b[i], b[i] = Add(b[i], mod - a[i]);
    inv[0] = inv[1] = 1;
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i = 2; i <= n; ++i) inv[i] = Mul(inv[mod%i], (mod-mod/i));
    for(int i = 2; i <= n; ++i) fac[i] = Mul(fac[i-1], i);
    for(int i = 2; i <= n; ++i) finv[i] = Mul(finv[i-1], inv[i]);
    C[0] = C[n] = 1;
    C2[0] = C2[n - 1] = 1;
    for(int i = 1; i < n; ++i) C[i] = Mul(fac[n], Mul(finv[i], finv[n-i]));
    for(int i = 1; i < n - 1; ++i)
        C2[i] = Mul(fac[n - 1], Mul(finv[i], finv[n - 1 - i]));
    for(int i = n - 1; ~i; --i) {
        if((n-i)&1) {
            a[n] = Add(a[n], mod - Mul(C[i], a[i]));
        }
        else {
            a[n] = Add(a[n], Mul(C[i], a[i]));
        }
    }
    // a[n] = Mul(a[n], finv[n]);
    for(int i = n - 2; ~i; --i) {
        if((n-1-i)&1) {
            b[n - 1] = Add(b[n - 1], mod - Mul(C2[i], b[i]));
        }
        else {
            b[n - 1] = Add(b[n - 1], Mul(C2[i], b[i]));
        }
    }
    // b[n - 1] = Mul(b[n - 1], finv[n]);
    cout << Mul(b[n - 1], qpow(a[n], mod - 2)) << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	solve();
}