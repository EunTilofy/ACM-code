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
string STR[2] = {"No", "Yes"};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
        int n, q;
        cin >> n >> q;
        vector<int> c(n+1);
        for(int i = 1; i <= n; ++i) cin >> c[i];
        vector G = vector(n+1, vector<int>());
        for(int i = 1; i < n; ++i) 
        {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        vector<int> Q(q);
        cin >> Q;
        // vector<int> t(n+1);
        // function<void(int,int)> C = [&](int x, int y)
        // {
        //     for(;x<=n;x+=(x&-x)) t[x]+=y;
        // };
        
        // function<int(int)> Get = [&](int x)
        // {
        //     int r=0;
        //     for(;x;x-=(x&-x)) r+=t[x];
        //     return r;
        // };
        vector<int> numson(n+1), fa(n+1), dep(n+1), siz(n+1), top(n+1), mx(n+1), dfn(n+1);
        int dind = 0;

        function<void(int, int)> dfs = [&](int x, int f)
        {
            fa[x] = f;
            siz[x] = 1;
            mx[x] = 0;
            dep[x] = dep[f] + 1;
            
            for(auto y : G[x]) if(y != f) 
            {
                dfs(y, x);
                if(c[y]) ++numson[x];
                siz[x] += siz[y];
                if(siz[mx[x]] < siz[y]) mx[x] = y;
            }
        };
        function<void(int,int,int)> dfs2 = [&](int x, int f, int tp)
        {
            top[x] = tp; dfn[x] = ++dind;
            if(mx[x]) dfs2(mx[x], x, tp);
            for(auto y : G[x]) if(y != f && y != mx[x]) dfs2(y, x, y);
        };
        dfs(1, 0);
        set<pair<int,int>> NOW;
        set<int>num2;
        for(int i = 1; i <= n; ++i) if(c[i]) NOW.insert({dep[i], i});
        for(int i = 1; i <= n; ++i) if(c[i]&&numson[i]==2) num2.insert(i);

        vector<int> ton(n+1);
        int num = 0;
        for(int i = 1; i <= n; ++i) if(c[i])
        {
            ++ton[numson[i]];
            if(numson[i] > 2 && ton[numson[i]] == 1) ++num;
        }
        for(auto x : Q)
        {
            if(c[x])
            {
                num2.erase(x);
                --ton[numson[x]];
                NOW.erase({dep[x], x});
                if(numson[x] > 2 && ton[numson[x]] == 0) --num;
            }
            else
            {
                // dbg2(numson[x]);
                NOW.insert({dep[x], x});
                ++ton[numson[x]];
                if(numson[x] > 2 && ton[numson[x]] == 1) ++num;
                if(numson[x]==2) num2.insert(x);
            }
            c[x] ^= 1;
            if(fa[x])
            {
                int f = fa[x];
                int yuan = numson[f]; numson[f] += c[x] ? 1 : -1; int now = numson[f];
                if(c[f])
                {
                    --ton[yuan];
                    ++ton[now];
                    if(yuan > 2 && ton[yuan] == 0) --num;
                    if(now > 2 && ton[now] == 1) ++num; 
                }
                if(c[f]&&numson[f]==2) num2.insert(f);
                else num2.erase(f);
            }
            // dbg(ton);
            cout << STR[num==0&&(ton[0]==1||(ton[2]==1&&ton[0]==2&&(*num2.begin()==(NOW.begin()->second))))] << "\n";
        }

        // set<pii> NOW;
        // for(int i = 1; i <= n; ++i) if(c[i-1]) C(dfn[i], 1), NOW.insert({dep[i], i});
        // set<int> _0;
        // for(int i = 1; i <= n; ++i) if(!numson[i] && c[i-1]) _0.insert(i);

        // function<int(int,int)> LCA = [&](int x, int y)
        // {
        //     while(top[x] != top[y])
        //     {
        //         if(dep[top[x]] > dep[top[y]]) x = fa[top[x]];
        //         else y = fa[top[y]];
        //     }
        //     return dep[x] < dep[y] ? x : y;
        // };
        // function<int(int, int)> get = [&](int x, int y)
        // {
        //     return Get(max(x, y)) - Get(min(x, y) - 1);
        // };
        // function<int(int, int)> cal = [&](int x, int y)
        // {
        //     int ans = 0;
        //     // dbg(x, y, top[x], top[y]);
        //     while(top[x] != top[y]) 
        //     {
        //         ans += get(dfn[x], dfn[top[x]]);
        //         x = fa[top[x]];
        //     }
        //     assert(dep[x] >= dep[y]);
        //     ans += get(dfn[x], dfn[y]);
        //     return ans;
        // };

        // function<bool(int,int)> chk1 = [&](int x, int y)
        // {
        //     if(x == y) return 0;
        //     while(top[x] != top[y]) x = fa[top[x]];
        //     if(top[x] != top[y]) return 0;
        //     if(dep[x] < dep[y]) return 0;

        //     if(NOW.size() != dep[x] - dep[y] + 1) return 0;
        //     if(cal(x, y) != dep[x] - dep[y] + 1) return 0;
        //     return 1;
        // };
        // function<bool(int,int,int,int)> chk2 = [&](int x, int y, int lca, int now)
        // {
        //     if(lca == x || lca == y) return 0;
        //     if(lca != now) return 0;
        //     if(dep[x] + dep[y] - dep[lca] * 2 + 1 != NOW.size()) return 0;
        //     if(cal(x, lca)+cal(y, lca)-1 != dep[x] + dep[y] - dep[lca] * 2 + 1) return 0;
        //     return 1;
        // };

        // exit(0);

        // for(auto x : Q)
        // {
        //     if(fa[x])
        //     {
        //         _0.erase(fa[x]);
        //         if(c[x-1]) --numson[fa[x]];
        //         else ++numson[fa[x]];
        //         if(numson[fa[x]] == 0 && c[fa[x]-1]) _0.insert(fa[x]);
        //     }
        //     c[x-1]=1-c[x-1];
        //     C(dfn[x], c[x-1]?1:-1);
        //     if(c[x-1]) NOW.insert({dep[x], x});
        //     else NOW.erase({dep[x], x});
        //     if(c[x-1] && numson[x] == 0) _0.insert(x);
        //     else _0.erase(x);
        //     if(NOW.size()==0)
        //     {
        //         cout << "No\n";
        //         continue;
        //     }
        //     if(_0.size() > 2)
        //     {
        //         cout << "No\n";
        //         continue;
        //     }
        //     if(NOW.size() == 1)
        //     {
        //         cout << "Yes\n";
        //         continue;
        //     }
        //     if(_0.size() == 1)
        //     {
        //         int x = *_0.begin();
        //         // dbg(x, NOW.begin()->second);
        //         cout << STR[chk1(x, (NOW.begin()->second))] << "\n";
        //     }
        //     else
        //     {
        //         assert(_0.size() == 2);
        //         int x = *_0.begin(), y = *_0.rbegin();
        //         assert(x != y);
        //         int lca = LCA(x, y);
        //         // dbg(x, y, lca, NOW.begin()->second);
        //         cout << STR[chk2(x, y, lca, (NOW.begin()->second))] << "\n";
        //     }
        // }
	}
    return 0;
}