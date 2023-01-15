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
const int MN = 5e5 + 5;
int a[MN], b[MN], c[MN], rk[MN], Ans;
bool cmp(int x,int y){return a[x]<a[y];}
void solve(){
	int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = i;
    sort(b+1, b+n+1, cmp);
    Ans = n + 1;
    for(int i = 1; i <= n; ++i) rk[b[i]] = i;
    for(int i = 2; i <= n; ++i) if(a[b[i]] == a[b[i-1]]) rk[b[i]] = rk[b[i-1]];
    for(int i = 1; i <= n; ++i) c[i] = c[i-1]+a[b[i]];
    for(int i = 1; i <= n; ++i) {
        if(m >= a[i]) {
            int val = m - a[i];
            int pos = upper_bound(c, c + n + 1, val) - c - 1;
            if(pos >= rk[i]) pos = upper_bound(c, c + n + 1, m) - c - 1 - 1;
            ++pos;
            if(pos >= i-1) Ans = min(Ans, n-i+1);
        }
        
        int pos = upper_bound(c, c+n+1, m) - c - 1;
        if(pos >= i) Ans = min(Ans, n-i+1);
    } 
    cout << Ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}