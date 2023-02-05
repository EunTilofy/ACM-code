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
	int n;
    cin >> n;
    int nn = n;
    vector<pii> p;
    for(int i = 2; i * i <= n; ++i) {
        if(nn % i == 0) {
            int _ = 0;
            while(nn % i == 0) nn /= i, ++_;
            p.pb({_, i});
        }
    }
    if(nn) p.pb({1, nn});
    long long ans = 0;
    // cerr << "_________" << endl;
    // cerr << p.size() << endl;
    std::sort(all(p));
    for(int i = 0; i < p.size(); ++i) {
        if(p[i].fi == 0) continue;
        int y = p[i].fi, tmp = 1ll;
        for(int j = i; j < p.size(); ++j) tmp *= (ll)p[j].se, p[j].fi -= y;
        // cerr << tmp << " " << y << endl;
        ans += 1ll * tmp * y;
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