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

void solve(){
	int n, m;
    cin >> n >> m;
    if(m == 1) {
        for(int i = 1; i <= n+1; ++i) cout << "0\n";
        return ;
    }
    cout << min(n + 1, m) << "\n";
    for(int i = 1; i <= n && i <= m - 1; ++i) {
        int pos0 = i;
        vector<int> a(m);
        for(int j = i, k = 1; k <= m; ++k, j = (j + 1) % m) {
            a[j] = k - 1;
        }
        for(auto x : a) cout << x << " ";cout << "\n";
    }
    for(int i = min(n, m-1) + 1; i <= n; ++i) {
        cout << m-1 << " ";
        for(int i = 0; i < m-1; ++i) cout << i << " ";
        cout << "\n";
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}