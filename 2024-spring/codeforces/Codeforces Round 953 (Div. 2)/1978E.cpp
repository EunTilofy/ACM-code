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
        int n; cin >> n;
        string s, t; cin >> s >> t;
        int Q; cin >> Q;
        vector<pii> q(Q); cin >> q;

        vector<int> ok(n);
        for(int i=0; i<n; ++i) 
        {
            if(s[i]=='1') ok[i]=1;
            else 
            {
                bool flg = 1;
                flg &= ((i>0&&t[i-1]=='1')||(i>1&&s[i-2]=='0'));
                flg &= ((i<n-1&&t[i+1]=='1')||(i<n-2&&s[i+2]=='0'));
                ok[i]=flg;
            }
        }
        for(int i=1;i<n;++i) ok[i]+=ok[i-1];
        auto cal = [&](int l, int r, int i) -> int
        {
            if(s[i]=='1') return 1;
            bool flg=1;
            flg &= ((i>l&&t[i-1]=='1')||(i>l+1&&s[i-2]=='0'));
            flg &= ((i<r&&t[i+1]=='1')||(i<r-1&&s[i+2]=='0'));
            return flg;
        };
        for(auto [l, r] : q)
        {
            int ans = 0;
            --l;--r;
            if(r-l+1<=5) for(int i=l;i<=r;++i) ans+=cal(l, r, i);
            else
            {
                ans=ok[r-2]-ok[l+1];
                ans+=cal(l,r,l)+cal(l,r,l+1)+cal(l,r,r-1)+cal(l,r,r);
            }
            cout << ans << "\n";
        }
	}
    return 0;
}