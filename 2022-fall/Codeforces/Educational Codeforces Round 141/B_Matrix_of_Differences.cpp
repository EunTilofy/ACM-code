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
int a[MN], b[55][55], c[MN];

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n*n; ++i) {
        if(i&1) a[i] = (i+1)/2;
        else a[i] = (n*n)-i/2+1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(i&1) {
            for(int j = 1; j <= n; ++j) b[i][j] = a[++cnt];
        }  
        else {
            for(int j = n; j; --j) b[i][j] = a[++cnt];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) cout << b[i][j] << " ";
        cout << endl;
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}