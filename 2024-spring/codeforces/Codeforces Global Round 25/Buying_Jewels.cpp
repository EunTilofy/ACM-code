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
	int n, m;
    cin >> n >> m;
    if(n == m)
    {
        cout << "YES\n";
        cout << "1\n1\n";
        return ;
    }
    if((n + 1) / 2 < m)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if(n % 2 == 1 && (n + 1) / 2 == m)
    {
        cout << "2\n2 1\n";
        return;
    }
    if(n % m == 0)
    {
        cout << "1\n" << (n / m) << "\n";
        return;
    }
    if(n - (m - 1) > m - 1)
    {
        cout << "2\n" << n - m + 1 << " " << 1 << "\n";
        return;
    }
    assert(0);
}

// bool f[101][101];
signed main()
{
    // freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

    // f[0][0] = 1;
    // for(int i = 1; i <= 100; ++i)
    //     for(int j = 1; j <= i; ++j)
    //     for(int k = 1; k <= i; ++k)
    //     if(i / k <= j)
    //     {
    //         if(f[i%k][j-(i/k)])
    //         {
    //             cout << i << " " << j << " : " << k << " " << i%k << " " << (j-i/k) << "\n";
    //         }
    //         f[i][j] |= f[i % k][j - (i / k)];
    //     }
    // for(int i = 1; i <= 100; ++i, cout << "\n")
    // for(int j = 1; j <= 100; ++j)
    //     cout << f[i][j] << " ";

    // cout << f[100][50] << " " << f[99][50] << "\n";
    //     // cout << "f[" << i << "][" << j << "]=" << f[i][j] << " ";


	int T;
	cin>>T;
	while(T--) solve();
}