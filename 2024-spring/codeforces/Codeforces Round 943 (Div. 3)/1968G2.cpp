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
#include "my_header/defs.h"
#include "my_header/IO.h"
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
int a[N], b[N], c[N];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
        int n, L, R;
        cin >> n >> L >> R;
        string s;
        cin >> s;
        auto kmp = [=](int k) -> int 
        {
            vector<int> nxt(k+1);
            nxt[0] = nxt[1] = 0;
	        for(int i = 1; i < k; ++i)
            {
		        int j = nxt[i];
		        while(j && s[i] != s[j]) j = nxt[j];
		        nxt[i + 1] = s[i]==s[j]?j+1:0;
	        }
            int sum = 0;
            for(int i = 0, j = 0; i < n; ++i)
            {
                while(j && s[i] != s[j]) j = nxt[j];
                if(s[i] == s[j]) ++j;
                if(j == k) ++sum, j = 0;
            }
            return sum;
        };
        int l, r;
        vector<int> ans(n + 1);
        ans[1] = n;
        vector<int> nm(n + 1, -1);
        nm[n] = 1;
        auto get = [&](int k) -> int
        {
            if(nm[k] != -1) return nm[k];
            else nm[k] = kmp(k);
            return nm[k];
        };
        int _ = get(1);

        for(int i = 2; i <= _; ++i)
        {
            r = n / i;
            l = 1;
            int __ = l;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                int tmp = get(mid);
                // dbg(mid, tmp);
                if(tmp < i) r = mid - 1;
                else { __ = mid; l = mid + 1;}
            }
            // int tmp = get(l);
            // for(int j = i; j <= tmp; ++j) ans[j] = l;
            // i = tmp;
            ans[i] = __;
        }
        for(int i = L; i <= R; ++i) cout << ans[i] << " ";
        cout << "\n";
	}
    return 0;
}