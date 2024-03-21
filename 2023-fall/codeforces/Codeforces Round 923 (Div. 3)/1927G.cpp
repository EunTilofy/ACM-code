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
const int MN = 100 + 5;
int a[MN];
char f[105][105][105][105];

pair<char,char> cut(int l, int r, int a, int b) {
    if(l > b || r < a) return {a, b};
    if(l <= a && r >= b) return {-1, -1};
    if(l <= a) return {r+1, b};
    if(r >= b) return {a, l-1};
    return {a, b};
}

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) for(int j = i; j <= n; ++j) 
    for(int l = 1; l <= n; ++l) for(int r = l; r <= n; ++r) {
        f[i][j][l][r] = 127;
    }

    for(int i = 1; i <= n; ++i) {
        for(int k = max(1, i-a[i]+1); k <= i; ++k) 
            f[i][i][k][i] = 1;
        for(int k = min(n, i+a[i]-1); k >= i; --k)
            f[i][i][i][k] = 1;
    }
    pair<char,char> _e = {-1, -1};
    for(int i = 1; i <= n; ++i) for(int j = i+1; j <= n; ++j) 
    for(int l = 1; l <= n; ++l) for(int r = l; r <= n; ++r) {
        f[i][j][l][r] = f[i][j-1][l][r];
        pair<char,char> _1 = cut(max(1, j-a[j]+1), j, l, r), _2 = cut(j, min(n, j+a[j]-1), l, r);
        if(_1 == _e || _2 == _e) {
            f[i][j][l][r] = 1;
        } else {
            if(f[i][j-1][_1.first][_1.second] < 127) {
                f[i][j][l][r] = min(f[i][j][l][r], (char)(f[i][j-1][_1.first][_1.second]+1));
            }
            if(f[i][j-1][_2.first][_2.second] < 127) {
                f[i][j][l][r] = min(f[i][j][l][r], (char)(f[i][j-1][_2.first][_2.second]+1));
            }
        }
    }
    cout << (short)f[1][n][1][n] << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}