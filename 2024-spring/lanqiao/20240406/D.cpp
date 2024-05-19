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
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    int last = 0, num = 0;
    vector<int> lef;
    for(int i = 1; i <= n; ++i)
    {
        int j = i;
        while(j + 1 <= n && a[j+1] == a[i]) ++j;
        int cnt = j - i + 1;
        while (last <= a[i] - 1 && num > 0) 
        {
            if(num & 1) lef.push_back(last);
            num /= 2;
            last ++;
        }
        if (last == a[i]) 
        {
            cnt += num;
        }
        num = cnt;
        last = a[i];
        i = j;
    }
    while(num > 0)
    {
        if(num & 1) lef.push_back(last);
        last ++;
        num /= 2;
    }
    int ans = lef.size();
    for(int i = 0; i + 1 < lef.size() - 1; ++i)
    {
        if(lef[i] == lef[i + 1] - 1) --ans;
    }
    cout << ans << "\n";
    return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; T = 1;
	while(T--) solve();
}