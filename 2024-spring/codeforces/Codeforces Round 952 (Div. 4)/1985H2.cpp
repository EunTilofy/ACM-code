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
        vector<string> a(n); cin >> a;
        vector<bool> vis(n*m);
        int lx, rx, ly, ry, siz;
        function<void(int,int)> dfs = [&](int x, int y) -> void
        {
            lx = min(lx, x);
            ly = min(ly, y);
            rx = max(rx, x);
            ry = max(ry, y);
            ++siz;
            vis[x*m+y] = 1;
            for(int dx : {-1, 0, 1}) for(int dy : {-1, 0, 1}) if(abs(dx) + abs(dy) == 1)
            {
                int xx = x + dx, yy = y + dy;
                if(xx >= 0 && yy >= 0 && xx < n && yy < m && a[xx][yy] == '#' && vis[xx*m+yy] == 0) dfs(xx, yy);
            }
        };
        vector rr(n, vector<int>(m));
        vector rl(n, vector<int>(m));
        vector lr(n, vector<int>(m));
        vector LL(n, vector<int>(m));

        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) 
        if(a[i][j] == '#' && !vis[i*m+j]) 
        {
            lx = rx = i, ly = ry = j, siz = 0, dfs(i, j);
            rr[rx][ry] += siz;
            rl[rx][ly] += siz;
            lr[lx][ry] += siz;
            LL[lx][ly] += siz;
        }

        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
            rr[i][j] += (i>0?rr[i-1][j]:0) + (j>0?rr[i][j-1]:0) - (i>0&&j>0?rr[i-1][j-1]:0);
        for(int i = 0; i < n; ++i) for(int j = m-1; ~j; --j)
            rl[i][j] += (i>0?rl[i-1][j]:0) + (j<m-1?rl[i][j+1]:0) - (i>0&&j<m-1?rl[i-1][j+1]:0);
        for(int i = n-1; ~i; --i) for(int j = 0; j < m; ++j)
            lr[i][j] += (i<n-1?lr[i+1][j]:0) + (j>0?lr[i][j-1]:0) - (i<n-1&&j>0?lr[i+1][j-1]:0);
        for(int i = n-1; ~i; --i) for(int j = m-1; ~j; --j)
            LL[i][j] += (i<n-1?LL[i+1][j]:0) + (j<m-1?LL[i][j+1]:0) - (i<n-1&&j<m-1?LL[i+1][j+1]:0);

        int ans = 0;
        int all = 0;
        for(auto x : a) for(auto y : x) all += y == '#';

        vector<int> sc(m), sr(n);
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(a[i][j] == '.') sc[j] ++, sr[i] ++;


        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j)
        {
            int sum = all + sc[j] + sr[i] - (a[i][j]=='.');
            if(i>1&&j>1) sum -= rr[i-2][j-2];
            if(i>1&&j<m-2) sum -= rl[i-2][j+2];
            if(i<n-2&&j>1) sum -= lr[i+2][j-2];
            if(i<n-2&&j<m-2) sum -= LL[i+2][j+2];

            ans = max(ans, sum);
        }
        cout << ans << "\n";
	}
    return 0;
}