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
#define mod 1000000007
#define inv2 ((mod+1)/2)
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3005;
int a[MN], b[MN][MN], c[MN][MN];
int pw2[MN<<1], inv[MN<<1], d[MN][MN];
void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int ans = qpow(2, n);
    ans = Add (ans, mod - 1);
    for(int i = 2; i <= n; ++i) for(int j = i + 1; j < n; ++ j) {
        if(i+1==j) b[i][j] = i;
        else b[i][j] = b[i][j-1];
        while(b[i][j]>1&&a[i]-a[b[i][j]-1]<=a[j]-a[i]) --b[i][j];
    }
    for(int j = 3; j < n; ++j) for(int i = j - 1; i > 1; --i) {
        if(i+1==j) c[i][j] = j;
        else c[i][j] = c[i+1][j];
        while(c[i][j]<n&&a[c[i][j]+1]-a[j]<a[j]-a[i]) ++c[i][j];
    }
    for(int i = pw2[0] = 1; i <= n*2; ++i) pw2[i] = Mul(pw2[i-1], 2);
    for(int i = inv[0] = 1; i <= n*2; ++i) inv[i] = Mul(inv[i-1], inv2);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        d[i][j] = Add(d[i][j-1], d[i-1][j]);
        d[i][j] = Add(d[i][j], mod - d[i-1][j-1]);
        d[i][j] = Add(d[i][j], inv[i+j]);
    }
    for(int i = 2; i < n; ++i) for(int j = i + 1; j < n; ++j) {
        if(b[i][j] == i) continue;
        if(c[i][j] == j) continue;
        int x = i - b[i][j];
        int y = c[i][j] - j;
        // cerr << b[i][j] << " " << i << " " << j << " " << c[i][j] << endl;
        ans = Add(ans, Mul(pw2[n-(j-i+1)], d[x][y]));
    }
    ans = Add(ans, mod - n);
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T = 1;
	while(T--) 
		solve();
}