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
#define dbg1(x) cerr << #x << '=' << (x) << ' '
#define dbg2(x) cerr << #x << '=' << (x) << '\n'
#define dbg3(x) cerr << #x << '\n'
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
void solve(){
	int n, x, y;
    cin >> n >> x >> y;
    vector<int> _(x);
    for(auto &xx : _) cin >> xx;
    sort(all(_));
    vector<pair<int,int>> __;
    int ans = 0;
    for(int i = 0; i < x; ++i) 
    {
        if(((_[i] + 2) - 1) % n + 1 == _[(i+1)%x]) ++ans;
        int val = (_[(i+1)%x] - _[i] + n) % n - 1;
        __.push_back({- (val & 1), val});
    }
    ans += x - 2;
    // cerr << "ans = " << ans << "\n";
    sort(all(__));
    for(auto [k, val] : __) 
    {
        if(val == 0 || val == 1) continue;
        // cerr << val << "\n";
        if(y >= val / 2) ans += val, y -= val / 2;
        else {
            ans += y * 2;
            y = 0;
            break;
        }
    }
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}