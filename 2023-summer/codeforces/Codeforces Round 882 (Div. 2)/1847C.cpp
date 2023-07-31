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
const int MN = 3e5 + 5;
int a[MN];

int ch[MN*5][2], tot = 0;

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], a[i] ^= a[i - 1];
    tot = 1;
    for(int i = 1; i <= n * 10; ++i) ch[i][0] = ch[i][1] = 0;
    for(int i = 0; i <= n; ++i) {
        int p = 1;
        for(int j = 7; ~j; --j) {
            int k = (a[i] >> j) & 1;
            if(!ch[p][k]) ch[p][k] = ++tot;
            p = ch[p][k];
        }
    }
    // cout << tot << endl;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int num = 0;
        int p = 1;
        for(int j = 7; ~j; --j) {
            int k = (a[i] >> j) & 1;
            if(!ch[p][k^1]) k ^= 1;
            assert(ch[p][k^1]);
            p = ch[p][k^1];
            num += ((k^1) << j);
        }
        ans = max(ans, (a[i] ^ num));
    }
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}