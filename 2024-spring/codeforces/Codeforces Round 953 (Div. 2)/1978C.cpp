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
        long long n, k; cin >> n >> k;
        if(k & 1) { cout << "No\n"; continue; }
        vector<int> a(n+1);
        for(int i = 1; i <= n; ++i) a[i] = i;
        long long now = 0;
        long long mx = 1ll * ((n/2)*2) * ((n+1)/2);
        // if(k > mx) { cout << "No\n"; continue;}
        for(int i = 1; now < k && i*2 <= n; ++i)
        {
            if(k - now >= 2 * (n-i+1-i)) 
            {
                now += 2 * (n-i+1-i);
                swap(a[i], a[n-i+1]);
            }
            else 
            {
                int num = (k - now) / 2;
                swap(a[i], a[i+num]);
                now += 2 * num;
            }
            // dbg(i, now, k);
        }
        if(now < k) cout << "No\n";
        else {
        cout << "Yes\n";
        for(int i = 1; i <= n; ++i) cout << a[i] << " "; cout << "\n";}
	}
    return 0;
}