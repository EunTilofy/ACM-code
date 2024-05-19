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
	int T; cin>>T;
	while (T--)
	{
        int n; cin >> n;
        vector<int> a(n); cin >> a;
        vector<int> b(n); for(int i = 0; i < n; ++i) b[i] = n+1-a[i];
        vector<int> b1(n), b2(n); int ans1 = 0, ans2 = 0;
        {
            set<pair<int,int>> s1, s2;
            for(int i = 0; i < n; i+=2) s1.insert({b[i], i}); s1.insert({b[n-1], n-1});
            for(int i = 1; i < n-1; i+=2) s2.insert({b[i], i});
            int num = 0;
            for(auto [v, p] : s1) b1[p] = ++num;
            for(auto [v, p] : s2) b1[p] = ++num;
            // set<pair<int,int>> ss1; for(int i = 1; i < n-1; i+=2) ss1.insert({b1[i], i});
            // for(auto [v, p] : ss1) 
            // {
            //     if(s1.upper_bound({v, p})!=s1.end())
            //     {
            //         auto _ = *s1.upper_bound({v, p});
            //         // dbgx(b1[i], _.second, _.first);
            //         swap(b1[p], b1[_.second]);
            //         s1.erase(_);
            //         // s1.insert({b1[_.second], _.second});
            //     }
            // }
            vector<int> ss(n); for(int i = 0; i < n; ++i) ss[i] = a[i] + b1[i];
            for(int i = 1; i < n-1; ++i) if(ss[i] > ss[i-1] && ss[i] > ss[i+1]) ++ans1;
            // dbgx(ss, ans1,b1);
        }
        {
            set<pair<int,int>> s2,s1;
            for(int i = 1; i < n; i+=2) s2.insert({b[i], i}); s2.insert({b[0], 0});
            for(int i = 2; i < n-1; i+=2) s1.insert({b[i], i});
            int num = 0;
            for(auto [v, p] : s2) b2[p] = ++num;
            for(auto [v, p] : s1) b2[p] = ++num;
            // set<pair<int,int>> ss2; for(int i = 2; i < n-1; i+=2) ss2.insert({b2[i], i});
            // for(auto [v, p] : ss2) 
            // {
            //     if(s2.upper_bound({v, p})!=s2.end())
            //     {
            //         auto _ = *s2.upper_bound({v, p});
            //         // dbgx(b1[i], _.second, _.first);
            //         swap(b2[p], b2[_.second]);
            //         s2.erase(_);
            //         // s1.insert({b1[_.second], _.second});
            //     }
            // }
            vector<int> ss(n); for(int i = 0; i < n; ++i) ss[i] = a[i] + b2[i];
            for(int i = 1; i < n-1; ++i) if(ss[i] > ss[i-1] && ss[i] > ss[i+1]) ++ans2;
            // dbgx(ss,ans2,b2);
        }
        // dbgx(ans1, ans2);
        b = (ans1 > ans2) ? b1 : b2;
        // assert(max(ans1 , ans2) == n/2-1);
        for(int i = 0; i < n; ++i) cout << b[i] << " \n"[i == n-1];
    }
    return 0;
}