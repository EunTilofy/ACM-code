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
int a[MN], b[MN], c[MN];

void solve()
{
	int n, m;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int mex = 0;
    for(int i = 0; i < n; ++i) c[i] = 0;
    for(int i = 0; i < n; ++i)
    {
        // a[i] = mex - b[i]
        b[i] = mex - a[i];
        if(b[i] != mex && b[i] >= 0 && b[i] < n && c[b[i]] == 0) 
        {
            c[b[i]] = 1;
        }
        else 
        {
            b[i] = mex;
            c[mex] = 1;
            while(c[mex] == 1) ++mex;
            // assert(mex - b[i] == a[i]);
        }
    }
    for(int i = 0; i < n; ++i) cout << b[i] << " ";
    cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}