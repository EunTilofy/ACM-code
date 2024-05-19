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
inline int Dec(int x, int y){return (x+mod-y)%mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
const int MN = 4e5 + 5;
int a[MN], b[MN], c[MN];

void solve()
{
	int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    vector f(2, vector(n+1, vector<int>(5005))), g(2, vector(n+1, vector<int>(5005)));
    vector sum(2, vector<int>(n+1)), num(2, vector<int>(n+1));
    f[0][0] = vector<int>(5005, 1);
    num[0][0] = 1;
    int ans = 0;
    int inv2 = (mod+1)/2;
    for(int i = 1; i <= n; ++i)
    {
        for(int _ = 0; _ <= 5000; ++_)
        {
            f[0][i][_] = f[0][i-1][_];
            f[1][i][_] = f[1][i-1][_];
            g[0][i][_] = g[0][i-1][_];
            g[1][i][_] = g[1][i-1][_];
            if(_ >= a[i])
            {
                f[0][i][_] = Add(f[0][i][_], f[0^(a[i]&1)][i-1][_-a[i]]);
                f[1][i][_] = Add(f[1][i][_], f[1^(a[i]&1)][i-1][_-a[i]]);
                g[0][i][_] = Add(g[0][i][_], Add(g[0^(a[i]&1)][i-1][_-a[i]], Mul(a[i], f[0^(a[i]&1)][i-1][_-a[i]])));
                g[1][i][_] = Add(g[1][i][_], Add(g[1^(a[i]&1)][i-1][_-a[i]], Mul(a[i], f[1^(a[i]&1)][i-1][_-a[i]])));
            }
        }
        for(int k = 0; k < 2; ++k) num[k][i] = Add(num[k][i-1], num[k^(a[i]&1)][i-1]),
                                   sum[k][i] = Add(sum[k][i-1], Add(sum[k^(a[i]&1)][i-1], Mul(a[i], num[k^(a[i]&1)][i-1])));
        ans = Add(ans, 
        Add(
            Mul(a[i], Add(f[0][i-1][a[i]], f[1][i-1][a[i]])),
            Mul(Add(
                Add(Dec(sum[0][i-1], g[0][i-1][a[i]]), Mul(a[i]+(a[i]%2==1), Dec(num[0][i-1], f[0][i-1][a[i]]))),
                Add(Dec(sum[1][i-1], g[1][i-1][a[i]]), Mul(a[i]+(a[i]%2==0), Dec(num[1][i-1], f[1][i-1][a[i]])))
            ), inv2)
        ));
    }
    cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	while(T--) solve();
}