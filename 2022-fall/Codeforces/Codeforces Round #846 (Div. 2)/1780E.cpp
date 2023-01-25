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
	long long l, r;
    cin >> l >> r;
    long long ans = 0ll;
    long long c = r - l + 1; --l;
    ans += max((c + l)/2 - l, 0ll);
    for(long long nl = 1; nl <= l; ++nl) {
        long long nr = (l/(l/nl));
        long long _ = nl - 1, nnl = nl, nnr = nr;
        while(nnl <= nnr) {
            int mid = (nnr + nnl) >>1;
            if(2ll*mid-(l%mid) <= c) _ = mid, nnl = mid + 1;
            else nnr = mid - 1;
        }
        ans += _ - nl + 1;
        nl = nr;
    }
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}