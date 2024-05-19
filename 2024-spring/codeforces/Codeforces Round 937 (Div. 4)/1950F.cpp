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
// int a[MN], b[MN], c[MN];

void solve(){
	int a, b, c;
    cin >> a >> b >> c;
    if(c - a != 1)
    {
        cout << "-1\n";
        return;
    }
    if(a == 0)
    {
        cout << b << "\n";
        return;
    }
    int n = 1, layer = 0, all = 0;
    if(b == 0)
    {
        cout << 32 - __builtin_clz(a) << "\n";
        return ;
    }
    while(all <= a)
    {
        if(all + n > a)
        {
            int cc = all + n - a;
            if(b <= cc)
            {
                cout << layer+1 << "\n";
                return;
            }
            else 
            {
                b -= cc;
                int dd = n * 2 - cc;
                // cerr << b << " " << cc << " " << layer << " " << dd <<  "\n";
                layer += (b + dd - 1) / dd;
                cout << layer+1 << "\n";
                return;
            }
        }
        else 
        {
            all += n;
            ++layer;
            n <<= 1;
        }
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}