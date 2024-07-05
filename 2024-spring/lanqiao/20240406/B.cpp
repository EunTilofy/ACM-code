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
#define int long long

void solve()
{
    int N;
    cin >> N;
    long long ans = 0;
    for(int i = 1; i <= N; ++i) cin >> a[i];
    for(int i = 0; i < 32; ++i)
    {
        int cnt = 0;
        for(int j = 1; j <= N; ++j)
        {
            cnt += (a[j] >> i) & 1;
        }
        ans = ans + 1ll * (cnt - 1) * cnt / 2ll;
    }
    cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	T = 1;
	while(T--) solve();
}