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
#define int long long

const int N = 4e5 + 5;

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(15);
	int T; cin>>T;
	while (T--)
	{
        string s;
        cin >> s;
        int n=s.size();
        function<bool(string)> chk = [&](string t)->bool
        {
            int lens = n, lent = t.size();
            for(int i=0;i<lens;++i)
            {
                if(s[i]=='a') continue;
                if(i+lent-1>=lens) return 0;
                for(int j=0;j<lent;++j) if(s[i+j]!=t[j]) return 0;
                i+=lent-1;
            }
            return 1;
        };
        if(s==string(n,'a')) cout << n-1 << "\n";
        else
        {
            vector<int> _;
            vector<string> T;
            string tmp="";
            auto Push_back = [&](string ss)
            {
                // dbg(ss);
                // for(int d=1;d<=ss.size();++d)if(ss.size()%d==0)
                // {
                //     bool flg=1;
                //     for(int k=0;k<ss.size();++k)if(ss[k]!=ss[k%d]){flg=0;break;}
                //     if(flg)
                //     {
                //         string add=ss.substr(0,d);
                //         for(int i=0;i<ss.size()/d;++i)
                //         {
                //             if(i) _.push_back(0);
                //             T.push_back(add);
                //         }
                //         return;
                //     }
                // }
                // assert(0);
                bool fl=0;
                for(auto x:ss)
                {
                    if(fl) _.push_back(0);
                    fl=1;
                    T.push_back(string(1,x));
                }
            };
            if(s[0]!='a') _.push_back(0);
            for(int i=0;i<n;++i)if(s[i]=='a')
            {
                if(tmp!="") Push_back(tmp), tmp="";
                int j=i;
                while(j+1<n&&s[j+1]=='a') ++j;
                _.push_back(j-i+1);
                i=j;
            }else
            {
                tmp+=s[i];
            }
            if(tmp!="") Push_back(tmp), _.push_back(0);
            // dbg(T, _);
            assert(T.size()==_.size()-1);

            int g=T[0].size();
            for(auto &x:T) g=gcd(g, x.size());
            long long ans=0;
            for(int i=1;i*i<=g;++i)if(g%i==0)
            {
                ans+=chk(T[0].substr(0, i));
                if(i!=g/i) ans+=chk(T[0].substr(0, g/i));
            }
            int c1=_[0], c3=_.back(), c2;
            if(T.size()==1) ans+=1ll*(c1+1)*(c3+1)-1;
            else
            {
                c2=_[1];
                for(int i=1;i<_.size()-1;++i)c2=min(c2, _[i]);
                if(T==vector<string>(T.size(), T[0]))
                {
                    for(int ii=0;ii<=c1&&ii<=c2;++ii)
                    {
                        ans+=(ii!=0) + max(0ll, min(c2-ii, c3));
                    }
                }
                ans+=1ll*(c1+1)*(c3+1);
                function<long long(int)> sol=[&](int len)->int
                {
                    assert(len>=2&&len!=T.size());
                    for(int i=len+1;i<_.size();++i)if(i%len!=0)if(_[i]!=_[i%len]) return 0;
                    for(int i=len;i<T.size();++i) if(T[i]!=T[i%len]) return 0;
                    c2=_[len];
                    for(int i=len;i<_.size()-1;i+=len) c2=min(c2, _[i]);
                    long long ret=0;
                    for(int ii=0;ii<=c1&&ii<=c2;++ii)
                    {
                        ret+=1 + max(0ll, min(c2-ii, c3));
                    }
                    return ret;
                };
                for(int i=2;i*i<=T.size();++i)if(T.size()%i==0)
                {
                    ans+=sol(i);
                    if(i!=T.size()/i) ans+=sol(T.size()/i);
                }
            }
            cout << ans << "\n";
        }
	}
    return 0;
}