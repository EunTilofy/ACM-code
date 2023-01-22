#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define mod 1000000007
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN];

void solve(){
	int n;
    cin >> n;
    cout << Mul(a[n], Mul(n, n - 1)) << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    a[0] = 1;
    for(int i = 1; i <= 100000; ++i) a[i] = 1ll * a[i-1] * i % mod;
	int T;
	cin>>T;
	while(T--) 
		solve();
}