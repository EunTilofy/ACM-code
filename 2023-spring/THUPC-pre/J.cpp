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
int inv[MN];
const int inv2 = ((mod+1)/2);
int a[MN], b[MN];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    inv[0] = inv[1] = 1;
    for(int i = 2;  i <= n+4; ++i) inv[i] = Mul(inv[mod%i], (mod-mod/i));
    // if(n == 1) {
    //     cout << "665496236 332748118\n332748118 665496236"<<endl;
    // } else {
        a[0] = 1;
        int u = 0, d = 1;
        for(int i = 1; i <= n; ++i) {
            // u + i * x = d * i / 2
            a[i] = Mul(Add(Mul(Mul(i, d), inv2), (mod-u)%mod), inv[i]);
            u = Add(u, Mul(i, a[i]));
            d = Add(d, a[i]);
        }
        int sm = 0;
        int all = 0, aal = 0; b[0] = 1;
        for(int i = 1; i <= n; ++i) {
            b[i] = Add(Mul(2, Mul(sm, inv[i])), Mul(2, b[i-1]));
            sm = Add(sm, b[i-1]);
        }
        for(int i = 0; i <= n; ++i) all = Add(all, a[i]), aal = Add(aal, b[i]);
        all = qpow(all, mod-2); aal = qpow(aal, mod-2);
        for(int i = 0; i <= n; ++i) a[i] = Mul(a[i], all), b[i] = Mul(b[i], aal);
        
        // all = 0;for(int i = 0; i <= n; ++i) all = Add(all, a[i]); cout << all << endl;
        // aal = 0;for(int i = 0; i <= n; ++i) aal = Add(aal, b[i]); cout << aal << endl;

        // for(int i = 0; i <= n; ++i) {
        //     int sum = 0;
        //     for(int j = 0; j < i; ++j) {
        //         sum = Add(sum, Mul(i, b[j]));
        //     }
        //     for(int j = i + 1; j <= n; ++j) {
        //         sum = Add(sum, Mul(Mul(j, inv2), b[j]));
        //     }
        //     cout << "s" << sum << endl;
        // }

        for(int i = 0; i <= n; ++i) cout << a[i] << " "; cout << endl;
        for(int i = 0; i <= n; ++i) cout << b[i] << " "; cout << endl;
        // }
    return 0;
}