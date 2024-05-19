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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int N, M;
    cin >> N >> M; vector<int> a(N); cin >> a;
    vector<pair<int, int>> que(M); cin >> que;
    vector rmq = vector(18, vector<int>(N));
    for(int i = 0; i < N; ++i) rmq[0][i] = i;
    auto maxi = [&](int x, int y) -> int
    {
        return a[x] > a[y] ? x : y;
    };
    for(int j = 1; j < 18; ++j) for(int i = 0; i < N; ++i)
    {
        if(i + (1<<j) - 1 >= N) break;
        rmq[j][i] = maxi(rmq[j-1][i], rmq[j-1][i+(1<<(j-1))]);
    }
    auto get = [&](int x, int y) -> int 
    {
        --x, --y;
        if(x > y) swap(x, y);
        int _ = 31 - __builtin_clz(y - x + 1);
        // dbg(x, y, max(rmq[_][x], rmq[_][y - (1<<_) + 1]));
        return maxi(rmq[_][x], rmq[_][y - (1<<_) + 1]);
    };
    vector<int> nex(N), num(N);
    stack<int> q;
    for(int i = N-1; i >= 0; --i) 
    {
        while(!q.empty() && a[q.top()] <= a[i]) q.pop();
        if(q.empty()) nex[i] = N;
        else nex[i] = q.top();
        num[i] = q.size();
        // dbg(i, num[i]);
        q.push(i);
    }
    for(auto [x, y] : que)
    {
        if(x > y) swap(y, x);
        int val = a[get(x, y)];
        int L = y, R = N, pos = N+1;
        while(L <= R)
        {
            int mid = (L+R)>>1;
            if(a[get(y, mid)] <= val) L = mid + 1;
            else pos= mid, R = mid - 1;
        }
        int ans = 0;
        // dbg2(pos);
        if(pos != N+1) ans = num[pos - 1] + 1;
        cout << ans << "\n";
    }
    return 0;
}