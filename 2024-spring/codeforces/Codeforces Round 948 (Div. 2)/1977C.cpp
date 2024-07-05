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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
        int n;
        cin >> n;
        vector<int> a(n);
        cin >> a;
        sort(all(a));
        set<int> s;
        for(auto x : a) s.insert(x);

        bool flg = 0;

        for(int i = 0; i < n; ++i)
        for(int j = i+1; j<n; ++j)
            if(s.count(lcm(a[i], a[j])) == 0) {flg = 1; break;}
        
        if(!flg) {cout << "0\n";continue;}

        for(int i = flg =  0; i < n-1; ++i)
        {
            if(a[n-1] % a[i] != 0) {flg = 1; break;}
        }
        if(flg) {cout << n << "\n"; continue;}

        int ans = 0;
        function<int(int)> chk = [&](int x)
        {
            if(s.count(x)) return 0;
            int nm = 1, _ = 0;
            for(int i = 0; i < n-1; ++i)
            {
                if(x % a[i] == 0) nm = lcm(nm, a[i]), ++_;
            }
            if(nm == x) {return _;}
            return 0;
        };
        
        for(int i = 1; i * i <= a[n-1]; ++i) if(a[n-1] % i == 0)
        {
            ans = max(ans, chk(a[n-1]/i));
            ans = max(ans, chk(i));
        }
        cout << ans << "\n";
        // dbg3(-----);
	}
    return 0;
}