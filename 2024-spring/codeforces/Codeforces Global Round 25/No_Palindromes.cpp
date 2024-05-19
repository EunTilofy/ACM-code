#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define mod 998244353
#define dbg1(x) cerr << #x << '=' << (x) << ' '
#define dbg2(x) cerr << #x << '=' << (x) << '\n'
#define dbg3(x) cerr << #x << '\n'
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
const int MN = 4e5 + 5;

vector<bool> chk(string S)
{
    int n = S.size();
    // vector<int> fail(n+5), len(n+5);
    // vector<vector<int>> c(n+5, vector<int>(26));
    vector<char> s(2 * n + 2);
    vector<int> p(2 * n + 2), r(2 * n + 2);
    int cnt = 0;
    for(int i = 0; i < n; ++i) 
    {
        s[++cnt] = S[i];
        s[++cnt] = '!';
    }
    // int en = 0;
    vector<bool> ans(n);
    // fail[0] = 1;
    // len[++en] = -1;

    // for(int i=1,j=1; i<=n; ++i)
    // {
    //     while(s[i]!=s[i-len[j]-1]) j = fail[j];
    //     if(!c[j][s[i]-'a'])
    //     {
    //         len[++en]=len[j]+2;
    //         ans[i-1] = len[en] == i;
    //         int k=fail[j];
    //         while(s[i]!=s[i-len[k]-1])
    //             k=fail[k];    
    //         fail[en]=c[k][s[i]-'a'];
    //         c[j][s[i]-'a']=en;
    //     }
    //     j=c[j][s[i]-'a'];
    // }

    int k, i;
    for(k = p[1] = 1, i = r[1] = 2; i <= cnt; ++i)
    {
        if(r[k] <= i) p[i] = 1;
        else p[i] = min(p[k*2-i], r[k]-i);
        for(; s[i+p[i]]==s[i-p[i]]; ++p[i]);
        r[i] = p[i] + i;
        r[i] > r[k] ? k=i : 0;
        // p[i]-1>ans?ans=p[i]-1:0;
    }
    for(int i = 0; i < n; ++i) ans[i] = (p[i+1] == i+1);
    return ans;
}

void solve()
{
	string s;
    cin >> s;
    int flg = 1;
    for(auto x : s) flg &= s[0] == x;
    if(flg)
    {
        cout << "NO\n";
        return ;
    }
    // chk1
    int n = s.size();
    bool flg3 = 1;
    for(int i = 0; i < n; ++i)
    {
        flg3 &= s[i] == s[n-1-i];
    }
    if(!flg3)
    {
        cout << "YES\n";
        cout << "1\n" << s << "\n";
        return ;
    }
    // chk2
    vector<bool> a = chk(s);
    for(int i = 0; i < n-1; ++i)
    {
        if(!a[i] && !a[n-i-2])
        {
            cout << "YES\n";
            cout << "2\n" << s.substr(0, i+1) << " " << s.substr(i+1, n-(i+1)) << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}