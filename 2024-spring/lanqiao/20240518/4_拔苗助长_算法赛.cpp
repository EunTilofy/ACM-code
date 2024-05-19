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

const int N = 1e6 + 5, M = 1e6+5;
bool in[N];

bool np[M];
int pri[M],cnt=0,mp[M];
void sieve(int n){
    np[1]=1;
    for(int i=2;i<=n;++i){
        if(!np[i])pri[++cnt]=i,mp[i]=i;
        for(int j=1;j<=cnt&&i*pri[j]<=n;++j){
            np[i*pri[j]]=1;
            mp[i*pri[j]]=pri[j];
            if(!(i%pri[j]))break;
        }
    }
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	std::cout<<fixed<<setprecision(15);
	int T = 1;
    sieve(1000000);
	while (T--)
	{
        int n;
        cin >> n;
        vector<int> a(n); cin >> a;
        map<int, int> b;
        // set<int> p;
        for(int i = 0; i < n; ++i)
        {
            int x = a[i];
            while(x != 1)
            {
                int j = mp[x];
                int _ = 0;
                while(x % j == 0) x /= j, _ ^= 1;
                if(_ == 1) b[j] ++;
            }
            // if(x != 1) b[i][x] = 1, in[x] = 1;
        }
        int ans = 0;
        for(auto [v, vv] : b)
        {
            ans += min(vv, n - vv);
        }
        std::cout << ans << "\n";
	}
    return 0;
}