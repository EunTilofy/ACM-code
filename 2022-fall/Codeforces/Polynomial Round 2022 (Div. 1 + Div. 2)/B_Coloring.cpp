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
int a[MN], b[MN], c[MN];

void solve(){
	int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i) cin >> a[i];
    sort(a + 1, a + m + 1);
    bool fl = 1;
    int nm = 0;
    for(int i = 1; i <= m; ++i) {
        if(a[i] > (n + k - 1) / k) fl = 0;
        else if(a[i] == (n + k - 1)/k) ++nm;
    }
    if(nm > (n + k - 1) % k + 1) fl = 0;
    if(fl) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}