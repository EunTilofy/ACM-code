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
inline int fpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int Dec(int x, int y){return (x+mod-y)%mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
const int MN = 4e5 + 5;
int a[MN], b[MN], c[MN];

void solve()
{
	int n, m;
    cin >> n;
    vector<int> a(n),b;
    for(auto &x : a) cin >> x;
    sort(all(a));
    int ans = 0, last = 0;
    for(auto x : a) {
        if(x > last) b.push_back(x - last);
        last = x;
    }
    reverse(all(b));
    for(auto x : b)
    {
        if(ans == 0) ans = 1;
        else if(ans == 1)
        {
            if(x == 1) ans = 0;
            else ans = 1;
        }
    }
    if(ans) cout << "Alice\n";
    else cout << "Bob\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}