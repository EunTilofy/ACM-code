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
long long a[MN], b[MN], c[MN];
#define int long long

void solve(){
	long long n, k;
    cin >> n >> k;
    bool fl = 1; long long B = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        fl &= a[i] == a[1];
        B += a[i];
    }
    if(fl == 1) {
        cout << "0\n";
        return ;
    }
    sort(a+1, a+n+1);
    int d = a[2] - a[1];
    for(int i = 2; i <= n; ++i) d = gcd(d, a[i] - a[i-1]);
    // cout << "nowd = " << d << "\n";
    if(k > a[n]) {
        // cout << "d1 = " << d << "\n";
        d = gcd(d, k - a[n]);
        // kc | d
        cout << ((1ll * n * (k - d) - B)/d) << "\n";
    }
    else if(k < a[1]) {
        d = gcd(d, a[1] - k);
        // cout << "d2 = " << d << "\n";
        cout << ((B - 1ll * n * (k + d))/d) << "\n";
    } else {
        cout << "-1\n";
        return;
    }
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}