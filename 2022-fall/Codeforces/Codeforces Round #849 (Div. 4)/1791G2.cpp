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
int a[MN];

int solve(){
	int n, m;
    cin >> n >> m;
    std::vector<pii> b;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        b.pb({a[i]+min(i, n+1-i), i});
    }
    int num = 0; sort(all(b));
    for(int i = 0; i < n; ++i) {
        if(m - b[i].fi >= 0) {
            num += (b[i].se*2<=n+1);
            m -= b[i].fi;
        } else {
            if(i == 0) return 0;
            if(num > 0) return i;
            int M = a[b[n-1].se]+b[n-1].se;
            for(int j = i; j < n; ++j) M = min(M, a[b[j].se]+b[j].se);
            vector<int> c(i);
            c[0] = b[0].se*2-n-1;
            for(int j = 1; j < i; ++j) c[j] = min(c[j-1], b[j].se*2-n-1);
            for(int j = i-1; ~j; --j) {
                if(m>=min(c[j], M - b[j].fi)) return j+1;
                m+=b[j].fi; M = min(M, a[b[j].se]+b[j].se);
            }
            return 0;
        }
    }
    return n;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) cout << solve() << endl;
    return 0;
}