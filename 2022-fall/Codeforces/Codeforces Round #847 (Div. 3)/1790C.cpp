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
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
int a[105][105], b[MN], c[MN];

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        b[i] = 0; c[i] = 0;
        for(int j = 1; j < n; ++j) cin >> a[i][j];
    }
    for(int i = 1; i < n; ++i) b[a[1][i]] = 1;
    int fd = -1;
    for(int i = 1; i <= n; ++i) if(b[i] == 0) fd = i;
    for(int i = 1; i <= n; ++i) {
        int _ = 0;
        for(int j = 1; j < n; ++j) {
            if(a[i][j] == fd) _ = 1;
            else {
                c[a[i][j]] = _;
            }
        }
    }
    a[1][n] = 0; c[0] = 1;
    if(c[a[1][1]] == 1) cout << fd << " ";
    for(int i = 1; i < n; ++i) {
        cout << a[1][i] << " ";
        if(c[a[1][i]] == 0 && c[a[1][i+1]] == 1) cout << fd << " ";
    }
    cout << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}