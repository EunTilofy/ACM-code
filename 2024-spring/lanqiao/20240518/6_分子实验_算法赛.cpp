#define LOCAL
#include<bits/stdc++.h>
using namespace std;
typedef unsigned ui;
typedef long double db;
typedef long long ll;
typedef __int128 lll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) (x).begin(),(x).end()
#define MOD 998244353
istream &operator>>(istream &cin, lll &x) { x=0; static string s; cin>>s; for (char c:s) x=x*10+(c-'0'); return cin; }
ostream &operator<<(ostream &cout, lll x) { static char s[60]; int tp=1; s[0]='0'+(x%10); while (x/=10) s[tp++]='0'+(x%10); while (tp--) cout<<s[tp]; return cout; }
template<class T1, class T2> istream &operator>>(istream &cin, pair<T1, T2> &a) { return cin>>a.first>>a.second; }
template<class T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<class T1> istream &operator>>(istream &cin, valarray<T1> &a) { for (auto &x:a) cin>>x; return cin; }
inline int fpow(int x,ll y,int m=MOD){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % MOD;}
inline int Mul(int x, int y){return 1ll * x * y % MOD;}
inline int Dec(int x, int y){return (x+MOD-y)%MOD;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header/IO.h"
#include "my_header/defs.h"
#else
#define dbg(...) ;
#define dbgx(...) ;
#define dbg1(x) ;
#define dbg2(x) ;
#define dbg3(x) ;
#define DEBUG(msg) ;
#define REGISTER_OUTPUT_NAME(Type, ...) ;
#define REGISTER_OUTPUT(Type, ...) ;
#endif
// #define cout std::cout

const int N = 4e5 + 5;
int f[2005][2005], g[2005][2005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	std::cout<<fixed<<setprecision(15);
	int n, m;
    cin >> n >> m;
    swap(n, m);
    if(m == 1)
    { 
        std::cout << n << "\n"; return 0; 
    }
    if(n == 1)
    {
        std::cout << 0 << "\n"; return 0;
    }
    // f[len][num]
    f[2][2] = 2;
    for(int num = 2; num <= m; num += 2) g[2][num] = 2;

    for(int len = 3; len <= n; ++len)
    {
        for(int num = len; num <= m; ++num)
        {
            f[len][num] = g[len-1][num-1];
            if(num - len > 0) f[len][num] = Add(f[len][num], g[len-1][num-len+1]);
        }
        for(int num = len; num <= m; ++num)
        {
            g[len][num] = Add(g[len][num - 2], f[len][num]);
        }
    }

    int ans = 0;

    for(int len = 2; len <= n; ++len)
        for(int num = 2; num <= m; ++num)
        {
            ans = Add(ans, Mul(f[len][num], n-len+1));
        }

    std::cout << ans << "\n";

    return 0;
}