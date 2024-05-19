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

const int N = 4e5 + 5;
// int a[N], b[N], c[N];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int T = 1;
	while (T--)
	{
        map<int, int> mp, mp2;
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
        {
            int x;
            cin >> x;
            int val = min(i, n - i + 1);
            if(mp.count(x) == 0) mp[x] = val;
            else 
            {
                if(mp[x] > val) mp2[x] = mp[x], mp[x] = val;
                else 
                {
                    if(mp2.count(x) == 0) mp2[2] = val;
                    else mp2[x] = min(mp2[x], val);
                }
            }
        }
        int ans = -1;
        for(auto [x, v] : mp)
        {
            if(x == m - x)
            {
                if(mp2.count(x))
                {
                    if(ans == -1) ans = mp2[x];
                    else ans = min(ans, mp2[x]);
                }
            }
            else if(mp.count(m - x))
            {
                if(ans == -1) ans = max(v, mp[m-x]);
                else ans = min(ans, max(v, mp[m-x]));
            }
        }
        cout << ans << "\n";
	}
    return 0;
}