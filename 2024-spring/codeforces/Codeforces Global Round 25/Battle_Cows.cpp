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
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = c[i] = a[i];
    swap(a[1], a[m]); swap(b[2], b[m]);
    int id = -1;
    for(int i = 1; i <= n; ++i) {
        if(c[i] > c[m])
        {
            id = i;
            break;
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] <= a[1]) cnt1 += i != 1;
        else break; 
    }
    for(int i = 1; i <= n; ++i)
    {
        if(b[i] <= b[2]) cnt2 += i != 2;
        else break;
    }
    int cnt3 = 0;
    if(id != -1 && id < m && n > 2 && id != 1 && id != 2)
    {
        swap(c[id], c[m]);
        cnt3 = 1;
        for(int i = id + 1; i <= n; ++i)
        {
            if(c[i] <= c[id]) cnt3 += 1;
            else break;
        }
    } 

    cout << max(cnt3, max(cnt1, cnt2)) << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}