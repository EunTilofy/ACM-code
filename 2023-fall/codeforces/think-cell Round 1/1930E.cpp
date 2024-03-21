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
#define dbg1(x) cerr << #x << '=' << (x) << ' '
#define dbg2(x) cerr << #x << '=' << (x) << '\n'
#define dbg3(x) cerr << #x << '\n'
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
const int MN = 1e6 + 5;
int a[MN], b[MN], fac[MN], inv[MN];
int C(int x, int y) {
    return Mul(fac[x], Mul(inv[y], inv[x-y]));
}

void solve(){
	int n, m;
    cin >> n;
    for(int k = 1; k <= (n-1)/2; ++k) {
        int ret = 1;
        for(int d = 1; 2*d*k <= n-1; ++d) {
            int _ = Add(C(n, 2*d*k), mod - C(n-2*d*k+2*k-1, 2*k-1));
            ret = Add(ret, _);
        }
        cout << ret << " ";
    }
    cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
    for(int i = fac[0] = inv[0] = inv[1] = 1; i <= 1000000; ++i) fac[i] = Mul(fac[i-1], i);
    for(int i = 2; i <= 1000000; ++i) inv[i] = Mul(inv[mod%i], (mod-mod/i));
    for(int i = 2; i <= 1000000; ++i) inv[i] = Mul(inv[i], inv[i-1]);
	while(T--) 
		solve();
}