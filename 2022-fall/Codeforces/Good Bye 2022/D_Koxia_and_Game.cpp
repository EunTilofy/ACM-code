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
int a[MN], b[MN], c[MN], d[MN], e[MN];
int getf(int x) {
    if(c[x] == x) return x;
    else return c[x] = getf(c[x]);
}
void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n;  ++i) cin >>a[i];
    for(int i = 1; i <= n;  ++i) cin >>b[i];
    for(int i = 1; i <= n; ++i) c[i] = i, d[i] = e[i] = 0;
    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        int x = getf(a[i]);
        int y = getf(b[i]);
        if(x != y) c[x] = y;
    }
    for(int i = 1; i <= n; ++i) ++d[getf(i)], ++e[getf(a[i])];
    int cnt0 = 0, cnt1 = 0;
    for(int i = 1; i <= n; ++i) if(i == getf(i)) {
        if(e[i] != d[i]) ans = 0;
        else ++cnt0;
    }
    for(int i = 1; i <= n; ++i) if(a[i] == b[i]) --cnt0, ++cnt1;
    if(ans) {
        for(int i = 1; i <= cnt0; ++i) ans = Mul(ans, 2);
        for(int i = 1; i <= cnt1; ++i) ans = Mul(ans, n);
    }
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}