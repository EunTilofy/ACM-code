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
	std::cout<<fixed<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
        int n,d;cin>>n>>d;
        vector<pii> a(n);cin>>a;
        vector c(8, vector<pair<pii, int>>(n));
        int ii,i=1,j,k;
        for(auto &[x,y] : a) 
        {
            int xx = x+y, yy = y-x;
            c[0][i-1]={{xx, yy}, i};
            c[1][i-1]={{-xx, yy}, i};
            c[2][i-1]={{xx, -yy}, i};
            c[3][i-1]={{-xx, -xx}, i};
            c[4][i-1]={{yy, -xx}, i};
            c[5][i-1]={{yy, xx}, i};
            c[6][i-1]={{-yy, -xx}, i};
            c[7][i-1]={{-yy, xx}, i};
            ++i;
        }
    
        tuple<int,int,int> ans = {0, 0, 0}, ans0 = {0, 0, 0};
        for(int _ : {0, 1, 2, 3, 4, 5, 6, 7})
        {
        sort(all(c[_]));
        i=ii=j=k=0;
        vector<pair<pii, int>> b = c[_];
        for(;i<n;++i)
        {
            while(k<n&&b[k].first.first<b[i].first.first+d) ++k;
            while(j<n&&b[j].first.first<b[i].first.first-d) ++j;
            while(k<n&&b[k].first.first==b[i].first.first+d&&b[k].first.second<b[i].first.second) ++k;
            while(j<n&&b[j].first.first==b[i].first.first-d&&b[j].first.second<b[i].first.second) ++j;
            ii=max(i+1, ii);
            while(ii<n&&b[ii].first.first==b[i].first.first&&b[ii].first.second<b[i].first.second+d) ++ii;
            if(ii<n&&i<n&&b[i].first.first==b[ii].first.first&&b[i].first.second==b[ii].first.second-d)
            {
                if(k<n&&b[k].first.first==b[i].first.first+d&&b[k].first.second>=b[i].first.second&&b[k].first.second<=b[i].first.second+d)
                {
                    ans = {b[k].second, b[i].second, b[ii].second};
                }
                if(k<n&&b[j].first.first==b[i].first.first-d&&b[j].first.second>=b[i].first.second&&b[j].first.second<=b[i].first.second+d)
                {
                    ans = {b[j].second, b[i].second, b[ii].second};
                }
            }
            if(ans != ans0) break;
        }
        if(ans != ans0) break;
        }
        auto [xx, yy, zz] = ans;
        std::cout << xx << " " << yy << " " << zz << "\n";
	}
    return 0;
}