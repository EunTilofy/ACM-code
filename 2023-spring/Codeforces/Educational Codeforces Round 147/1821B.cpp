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
    for(int i = 1; i <= n; ++i) cin >> b[i];
    int l = n+1, r = 0;
    for(int i = 1; i <= n; ++i) if(a[i] != b[i]) {l = i; break;}
    for(int i = n; i; --i) if(a[i] != b[i]) {r = i; break;}
    if(r == 0) cout << "1 " << n << endl;
    else {
        int mn = a[l], mx = a[l];
        for(int i = l; i <= r; ++i) mn = min(mn, a[i]), mx = max(mx, a[i]);
        while(l>1 && a[l-1]<=mn) {
            --l;
            mn=a[l];
        }
        while(r<n&&a[r+1]>=mx){
            ++r;
            mx=a[r];
        }
        cout << l << " " << r << endl;
    }
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}