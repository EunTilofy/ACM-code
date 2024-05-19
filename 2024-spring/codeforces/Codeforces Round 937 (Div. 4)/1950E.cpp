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
// #define mod 998244353
#define dbg1(x) cerr << #x << '=' << (x) << ' '
#define dbg2(x) cerr << #x << '=' << (x) << '\n'
#define dbg3(x) cerr << #x << '\n'
// inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y, int mod){return (x + y) % mod;}
inline int Mul(int x, int y, int mod){return 1ll * x * y % mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
const int MN = 4e5 + 5;

// const int mod1 = 1e9+7, mod2 = 1e9+9, base = 37;
// int a[MN][2], b[MN][2];

void solve(){
	int n;
    string s;
    cin >> n >> s;

    function<bool(int)> chk = [&](int i) -> bool
    {
        if(i == n) return true;
        set<string> S;
        for(int j = 0; j < n; j += i)
        {
            S.insert(s.substr(j, i));
            if(S.size() > 2) return false;
        }
        if(S.size() < 2) return true;
        string x = *S.begin(), y = *S.rbegin();
        vector<int> numx, numy;
        for(int j = 0; j < n; j += i)
        {
            if(s.substr(j, i) == x) 
            {
                numx.push_back(j);
            }
            else 
            {
                numy.push_back(j);
            }
        }
        if(numx.size() > 1 && numy.size() > 1) return false;
        int id = numx[0], ID = numy[0];
        int cc = 0;
        for(int k = id, j = ID; k < id + i; ++k, ++j)
        {
            cc += (s[k] != s[j]);
            if(cc > 1) return false;
        }
        return true;
    };

    for(int i = 1; i <= n; ++i) if(n % i == 0)
    {
        if(chk(i)) 
        {
            cout << i << '\n';
            return;
        }
    }
    
    // for(int i = 1; i <= n; ++i) {
    //     a[i][0] = Add(Mul(a[i-1][0], base, mod1), s[i-1]-'a'+1, mod1);
    //     a[i][1] = Add(Mul(a[i-1][1], base, mod2), s[i-1]-'a'+1, mod2);
    // }

    // function<pair<int,int>(int, int)> get = [&](int l, int r) -> pair<int,int>
    // {
    //     return
    //     {
    //         Add(mod1 - Mul(a[l-1][0], b[r-l+1][0], mod1), a[r][0], mod1),
    //         Add(mod2 - Mul(a[l-1][1], b[r-l+1][1], mod2), a[r][1], mod2)
    //     };
    // };

    // function<bool(int)> chk = [&](int len) -> bool
    // {
    //     if(len == n) return 1;
    //     set<pair<int,int>> S;
    //     for(int i = 0; i < n; i += len)
    //     {
    //         S.insert(get(i+1, i+len));
    //         cerr << get(i+1,i+len).first << "  " << get(i+1,i+len).second << "\n";
    //         if(S.size() > 2) return false;
    //     }
    //     if(S.size() < 2) return true;
    //     cerr << len << "! " << s << "\n";
    //     auto x = *S.begin(), y = *S.rbegin();
    //     vector<int> numx, numy;
    //     for(int i = 0; i < n; i += len)
    //     {
    //         if(get(i+1, i+len) == x) 
    //         {
    //             numx.push_back(i);
    //         }
    //         else 
    //         {
    //             numy.push_back(i);
    //         }
    //     }
    //     if(numx.size() > 1 && numy.size() > 1) return 0;
    //     int id = numx[0], ID = numy[0];
    //     int cc = 0;
    //     for(int i = id + 1, j = ID + 1; i <= id + len; ++i, ++j)
    //     {
    //         cc += (s[i-1] != s[j-1]);
    //         if(cc > 1) return false;
    //     }
    //     return true;
    // };
    
    // vector<int> c;
    // for(int i = 1; i * i <= n; ++i) if(n % i == 0)
    // {
    //     cerr << i << "\n";
    //     if(chk(i))
    //     {
    //         cout << i << "\n";
    //         return;
    //     }
    //     c.push_back(n/i);
    // }
    // reverse(all(c));
    // for(auto i : c) {
    //     cerr << i << "\n";
    //     if(chk(i))
    //     {
    //         cout << i << "\n";
    //         return;
    //     }
    // }
    // cerr << "---------\n";
    // return ;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    // for(int i = 1; i < MN; ++i) b[i][0] = Mul(b[i-1][0], base, mod1), b[i][1] = Mul(b[i-1][1], base, mod2);
	int T;
	cin>>T;
	while(T--) 
		solve();
}