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

#define int long long

const int N = 4e5 + 5;

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
        int n, m;
        cin >> n >> m;
        vector a = vector(m, vector<bool>(n));
        for(int i = 0; i < n; ++i)
        {
            string s; cin >> s;
            for(int j = 0; j < m; ++j) a[j][i] = s[j] == '1';
        }

        auto print = [&](vector<bool>& _)
        {
            for(auto x : _) cout << x;
            cout << "\n";
        };

        vector<bool> ans(n); int anss = 1;
        ans = a[0]; ans[0] = 1 - ans[0];

        map<pair<int,int>, pair<int, pair<int,int>>> mp;
        int base = 37, mod1 = 1e9+7, mod2 = 1e9+9;
        vector<pair<int,int>> pb(n);
        pb[0] = {1, 1};
        for(int i = 1; i < n; ++i) pb[i] = {1ll*pb[i-1].first*base%mod1, 
                                            1ll*pb[i-1].second*base%mod2};
        auto get_hash = [&](vector<bool>& x) -> pair<int,int>
        {
            pair<int,int> ret = {0, 0};
            for(int i = 0; i < n; ++i)
            {
                ret = {(ret.first + pb[i].first * x[i])%mod1,
                       (ret.second+ pb[i].second * x[i])%mod2};   
            }
            return ret;
        };
        auto modi_hash = [&](pair<int,int> a, int pos, int type) -> pair<int,int>
        {
            auto [x, y] = a;
            x = ((x + 1ll*pb[pos].first*(1-2*type)) % mod1+ mod1) % mod1;
            y = ((y + 1ll*pb[pos].second*(1-2*type)) % mod2 + mod2) % mod2;
            return {x, y};
        };

        for(int i = 0; i < m; ++i)
        {
            pair<int,int> kk = get_hash(a[i]);
            for(int j = 0; j < n; ++j)
            {
                pair<int,int> kkk = modi_hash(kk, j, a[i][j]);
                if(mp.count(kkk))
                {
                    mp[kkk].first ++;
                }
                else
                {
                    mp[kkk].first = 1;
                    mp[kkk].second = {i, j};
                }
            }
        }

        for(auto [x, y] : mp)
        {
            if(y.first > anss)
            {
                anss = y.first;
                ans = a[y.second.first];
                ans[y.second.second] = 1 - ans[y.second.second];
            }
        }
        
        cout << anss << "\n";
        print(ans);
	}
    return 0;
}