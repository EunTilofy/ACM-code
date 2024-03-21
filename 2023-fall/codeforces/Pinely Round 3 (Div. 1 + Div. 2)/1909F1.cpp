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
const int MN = 4e5 + 5;
int a[MN], b[MN], c[MN];
int fac[MN], inv[MN];

int C(int x, int y) {
    if(x < 0 || x > y) return 0;
    return Mul(fac[x], Mul(inv[x], inv[x - y]));
}

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) {cin >> a[i]; b[i] = 0;}
    for(int i = 2; i <= n; ++i) if(a[i] < a[i- 1] || a[n] != n) {
        cout << "0\n";
        return;
    }
    long long ans = 1;
    int now = 0, _ = 0;
    int cnt = 0;
    for(int i = n-1; ~i; --i) {
        int c = a[i+1] - a[i];
        if(c == 0) {
            if(now < 2) {
                cout << "0\n";
                return;
            }
            // cerr << ans << "\n";
            ans = Mul(ans, Mul(now / 2, now / 2));
            now -= 2;
        } else if (c == 1) {
            ++cnt;
            b[i + 1] = 1;
            ans = Mul(ans, Add(1, Mul(2, now / 2)));
        } else if (c == 2) {
            now += 2;
        } else {
            cout << "0\n";
            return;
        }
    }
    if(now != 0) {
        cout << "0\n";
        return ;
    }
    cout << ans << "\n";
}

int main(){
    for(int i = fac[0] = 1; i < MN; ++i) fac[i] = Mul(fac[i - 1], i);
    inv[0] = inv[1] = 1;
    for(int i = 2; i < MN; ++i) inv[i] = Mul(inv[mod%i], (mod - mod / i));
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}