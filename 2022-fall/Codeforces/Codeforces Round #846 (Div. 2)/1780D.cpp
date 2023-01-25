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
    long long now = 0, sb = 1, sh = 0;
    while(n != 0) {
        now += sb;
        cout << "- " << sb << endl;
        cout.flush();
        cin >> m;
        if(m < n) {
            sb <<= 1;
            ++sh;
        }
        else {
            long long ssb = ((1ll << (ll)(m-n+1ll)) - 1ll) << (ll)(sh);
            now += ssb;
            cout << "- " << ssb << endl;
            cout.flush();
            sb <<= (m-n+2);
            sh += m-n+2;
            cin >> m;
        }
        n = m;
    }
    cout << "! " << now << endl;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}