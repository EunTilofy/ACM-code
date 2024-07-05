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
// #define cin std::cin
// #define cerr std::cerr

const int N = 4e5 + 5;
// int a[N], b[N], c[N];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
        int n;
        cin >> n;
        int a, b;
        cin >> a >> b;
        vector<int> G[n+1];
        for(int i = 1; i < n; ++i)
        {
            int x, y; cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        vector<int> dep(n+1), fa(n+1), mxdep(n+1);
        vector d = vector(2, vector<int>(n+1));
        long long sm = 0; int mx = 0;
        dep[0] = -1; d[0][0] = d[1][0] = -1;
        function<void(int, int, vector<int>&)> dfs = [&](int x, int f, vector<int>& de)
        {
            de[x] = de[fa[x] = f] + 1;
            mxdep[x] = x;
            sm += dep[x]; mx = max(mx, dep[x]);
            for(auto y : G[x]) if(y != f) 
            {
                dfs(y, x, de);
                if(de[mxdep[y]] > de[mxdep[x]]) mxdep[x] = mxdep[y];
            }
        };
        dfs(a, 0, dep);
        if(a == b)
        {
            cout << ((n-1) * 2ll - mx) << "\n";
            continue;
        }
        long long ans = (n-1) * 2ll - mx + dep[b];
        int _1 = mxdep[a];
        dfs(_1, 0, d[0]);
        // cout << d[0] << "\n";
        int _2 = mxdep[_1];
        dfs(_2, 0, d[1]);
        // cout << d[1] << "\n";
        // dbg(_1, _2);
        dfs(a, 0, dep);
        int dd = dep[b], cc = 0;
        while(dd >= 0 && b != a)
        {
            if(cc * 2 < dd) 
            {
                b = fa[b]; ++cc;
                continue;
            }
            else
            {
                // dbg(b, cc, d[0][b], d[1][b]);
                ans = min(ans, cc + (n-1)*2ll - max(d[0][b], d[1][b]));
                b = fa[b]; ++cc;
            }
        }
        cout << ans << "\n";
	}
    return 0;
}