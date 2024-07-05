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
        int n, m; cin >> n >> m;
        vector<string> a(n), b(m);
        cin >> a;
        for(int i = 0; i < m; ++i)
        {
            string t = "";
            for(int j = 0; j < n; ++j) t += a[j][i];
            b[i] = t;
        }
        auto sol = [](vector<string> a, int n, int m) -> int 
        {
            vector<int> nw(n);
            vector<int> sm(m);
            vector<int> fa(n*m), siz(n*m);
            {
                for(int i = 0; i < n*m; ++i) fa[i] = i;
                for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(a[i][j]=='#') siz[i*m+j] = 1;
            }
            function<int(int)> getf = [&](int x) -> int { return x == fa[x] ? x :fa[x] = getf(fa[x]); };
            function<void(int,int)> merge = [&](int x, int y) -> void
            {
                x = getf(x); y = getf(y); if(x != y) fa[x] = y, siz[y] += siz[x], siz[x] = 0;
            };
            for(int i = 0; i < m; ++i)
            {
                sm[i] = 0;
                for(int j = 0; j < n; ++j) if(a[j][i] == '#')
                {
                    if(j-1>=0&&a[j-1][i]=='#') merge(j*m+i, (j-1)*m+i);
                    if(i-1>=0&&a[j][i-1]=='#') merge(j*m+i, j*m+(i-1));
                }
                set<int> nx;
                for(int j = 0; j < n; ++j) if(a[j][i] == '#')
                    if(nx.count(getf(j*m+i)) == 0) {
                    sm[i] += siz[getf(j*m+i)], nx.insert(getf(j*m+i));
                    dbg(j, siz[getf(j*m+i)]);
                    }
                dbg(i, sm[i]);
            }
            dbg(sm);
            fill(all(nw), 0);
            {
                for(int i = 0; i < n*m; ++i) fa[i] = i;
                for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(a[i][j]=='#') siz[i*m+j] = 1;
            }
            int smm = 0, ans = 0;
            for(int i = m-1; i>=0; --i)
            {
                int SM = n + smm;
                if(i > 0) SM += sm[i-1];
                // dbg(n, smm, (i>0)?sm[i-1]:0);
                ans = max(ans, SM);
                smm = 0;
                for(int j = 0; j < n; ++j) if(a[j][i] == '#')
                {
                    if(j-1>=0&&a[j-1][i]=='#') merge(j*m+i, (j-1)*m+i);
                    if(i+1<m&&a[j][i+1]=='#') merge(j*m+i, j*m+(i+1));
                }
                set<int> nx;
                for(int j = 0; j < n; ++j) if(a[j][i] == '#')
                    if(nx.count(getf(j*m+i)) == 0) 
                        smm += siz[getf(j*m+i)], nx.insert(getf(j*m+i));
                // dbg(i, smm);
            }
            return ans;
        };
        cout << max(sol(a,n,m), sol(b,m,n)) << "\n";
	}
    return 0;
}