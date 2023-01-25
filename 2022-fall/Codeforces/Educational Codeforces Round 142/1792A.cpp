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
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    std::sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 1; i + 1 <= n; i += 2) {
        if(a[i] + (a[i+1] > a[i]) <= 2) {
            // cout << "sss" << a[i] + (a[i+1] > a[i]) << endl;
            ans += a[i] + (a[i+1] > a[i]);
        }
        else ans += 2;
    }
    if(n&1) ans+=1;
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}