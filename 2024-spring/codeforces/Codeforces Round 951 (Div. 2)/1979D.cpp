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

const int B[]={691,769,823,877,911,967};
int p[6][N];
struct node
{
	vector<int> v;
	int& operator [](int x){return v[x];}
    node (string s) : v(6) 
    {
        for(int i=0;i<6;++i) v[i]=0;
        for(int i=0;i<6;++i) for(int j=0;j<s.size();++j)
            v[i]=Add(Mul(v[i], B[i]), s[j]-'0'+1);
    }
    node () : v(6) {}
	bool operator <(const node o)const
	{
		for(int i=0;i<6;++i)if(v[i]!=o.v[i])return v[i]<o.v[i];
		return false;
	}
	bool operator ==(const node o)const
	{
		for(int i=0;i<6;++i)if(v[i]!=o.v[i])return false;
		return true;
	}
    node add(int x) const 
    {
        node y = *this;
        for(int i=0;i<6;++i) y[i]=Add(Mul(y[i], B[i]), x);
        return y;
    }
    node operator - (node o) {
        node y = *this;
        for(int i=0;i<6;++i) y[i]=Dec(y[i], o[i]);
        return y;
    }
    node operator + (node o) {
        node y = *this;
        for(int i=0;i<6;++i) y[i]=Add(y[i], o[i]);
        return y;
    }
    node shift(int len)
    {
        node y=*this;
        for(int i=0;i<6;++i) y[i]=Mul(y[i], p[i][len]);
        return y;
    }
    REGISTER_OUTPUT(node, v);
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int T; cin>>T;
    for(int i=0;i<6;++i)for(int j=p[i][0]=1;j<N;++j) p[i][j]=Mul(p[i][j-1], B[i]);
	while (T--)
	{
        int n, k; cin >> n >> k;
        string s, t1, t2;
        cin >> s;
        for(int i = 0; i < n; ++i) if((i / k) % 2 == 1) t1 += '0', t2 += '1'; else t1 += '1', t2 += '0';
        node T1(t1), T2(t2);
        // dbg(T1, T2);
        // dbg(t1, t2);
        vector<node> a(n+1), b(n+1);
        for(int i=1;i<=n;++i) { a[i]=a[i-1].add(s[i-1]-'0'+1); }
        for(int i=1;i<=n;++i) { b[i]=b[i-1].add(s[n-i]-'0'+1); }
        int ans = -1;
        for(int i=1;i<n;++i)
        {
            node _1 = b[n]-(b[n-i].shift(i)), _2=a[n]-(a[i].shift(n-i));
            node _ = (_2.shift(i))+_1;
            // dbg(s.substr(i, n-1));
            // dbg(_, T1, T2, (string)(s.substr(i, n-i)+s.substr(0, i)));
            if(_ == T1 || _ == T2) { ans = i; break; }
        }
        cout << ans << "\n";
	}
    return 0;
}