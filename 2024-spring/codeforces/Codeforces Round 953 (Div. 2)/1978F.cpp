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
const int N = 1e6 + 5;

int pr[N], tot, mi[N];
bool mk[N];

void init()
{
    for(int i=2;i<N;++i)
    {
        if(mk[i]==0) {pr[++tot]=i;mi[i]=i;}
        for(int j=1;j<=tot&&(ll)pr[j]*i<N;++j)
        {
            mi[i*pr[j]]=pr[j];
            mk[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
}
vector<int> id[N];


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int T; cin>>T;
    init();
	while (T--)
	{
        int n, k; cin >> n >> k;
        vector<int> a(n); cin >> a;
        long long ans = 0, bl = n;
        for(auto x : a) if(x == 1) ans += n, --bl;
        ans+=bl*2;
        vector<int> fa(n*2);
        for(int i=0;i<n*2;++i) fa[i]=i;
        function<int(int)> getf = [&](int x) -> int { return fa[x]==x?x:fa[x]=getf(fa[x]); };
        function<void(int,int)> _union = [&](int x, int y)
        {
            // if(a[x]==1||a[y]==1) return;
            x = getf(x); y = getf(y);
            if(x == y) return ;
            // dbg(ans, x, y);
            fa[x] = y; --ans; --bl; return;
        };
        if(a[0]!=1) _union(0, 1);
        if(k>=n) for(int i=1;i<n;++i) if(a[i]!=1) _union(i*2,i*2+1);

        unordered_set<int> allid;
        for(int i=0;i<n;++i) 
        {
            int x=a[i];
            while(x!=1)
            {
                int y=mi[x];
                while(x%y==0)x/=y;
                id[y].push_back(i);
                allid.insert(y);
            }
        }
        // dbg(allid);
        for(auto p : allid)
        {
            int siz=id[p].size();
            for(int i=0;i<siz-1;++i) 
            {
                if(id[p][i+1]-id[p][i]<=k)
                {
                    // dbg(id[p][i]*2, id[p][i+1]*2, p);
                    // dbg(id[p][i]*2+1, id[p][i+1]*2+1, p);

                    _union(id[p][i]*2, id[p][i+1]*2);
                    if(id[p][i] != 0) _union(id[p][i]*2+1, id[p][i+1]*2+1);
                }
            }
            for(int i=0;i<siz;++i)
            {
                if(n-(id[p][i]-id[p][0])<=k)
                {
                    // dbg(id[p][i]*2+1, id[p][0]*2, p);
                    if(id[p][i] != 0) _union(id[p][i]*2+1, id[p][0]*2);
                }
                if(n-(id[p][siz-1]-id[p][i])<=k)
                {
                    // dbg(id[p][i]*2, id[p][siz-1]*2+1,p);
                    _union(id[p][i]*2, id[p][siz-1]*2+1);
                }
            }
        }
        cout << ans << "\n";
        for(auto x : allid) id[x].clear();
	}
    return 0;
}