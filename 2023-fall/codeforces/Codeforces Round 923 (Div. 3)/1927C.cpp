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

void solve(){
	int n, m;
    cin >> n >> m;
    int k; cin >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int j = 1; j <= m; ++j) cin >> b[j];
    for(int i = 0; i <= k; ++i) c[i] = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] <= k) c[a[i]] |= 1;
    }
    for(int i = 1; i <= m; ++i) {
        if(b[i] <= k) c[b[i]] |= 2;
    }
    int _1 = 0, _2 = 0, _3 = 0;
    for(int i = 1; i <= k; ++i) {
        if(!c[i]) {cout << "NO\n"; return;}
        if(c[i] == 1) _1 ++;
        if(c[i] == 2) _2 ++;
        if(c[i] == 3) _3 ++;
    }
    if(_1 > k/2 || _2 > k/2) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}