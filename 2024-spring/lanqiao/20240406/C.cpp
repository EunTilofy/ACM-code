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

void solve()
{
	long long n, m;
    cin >> n >> m;
    // m - 1, (m * m - 1)
    long long dig = 1, num = m - 1, last = 0;
    long long last_cnt = 0, now_cnt = m - 1;
    while(now_cnt < n)
    {
        ++dig;
        last = num;
        last_cnt = now_cnt;
        num = (num + 1) * m - 1;
        now_cnt = last_cnt + (num - last) * dig;
    }
    // cerr << dig << " " << last << " " << last_cnt << "\n";
    n -= last_cnt;
    // cerr << n << "\n";
    long long pos = (n + dig - 1) / dig;
    // cerr << pos << "\n";
    long long _ = n - (pos - 1) * dig;
    // cerr << _ << "\n";
    pos += last;
    // cerr << pos << "\n";
    vector<int> a(dig);
    for(int i = 0; i < dig; ++i) 
    {
        a[i] = pos % m;
        pos = pos / m;
    }
    reverse(all(a));
    cout << a[_ - 1] << "\n";
    return ;
// 1 2 3 4 10 11 12
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}