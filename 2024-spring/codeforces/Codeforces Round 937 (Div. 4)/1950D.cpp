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

bool solve()
{
    int n;
	cin >> n;
    int N = n;
    // std::vector<int> d;
    function<bool(int)> chk = [](int x) -> bool
    {
        string s = to_string(x);
        bool flg = 1;
        for(auto y : s) flg &= (y == '0' || y == '1');
        return flg;
    };
    if(chk(n)) return 1;
    for(int i=2; i*i <= n; ++i) if(N % i == 0 && chk(i))
    {
        while(N % i == 0 && N != 0) 
        {
            N /= i;
            // cerr << N << "\n";
        }
    }
    return chk(N);
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
    string _[] = {"NO", "YES"};
	while(T--) {
        cout << _[solve()] << "\n";
    }
}