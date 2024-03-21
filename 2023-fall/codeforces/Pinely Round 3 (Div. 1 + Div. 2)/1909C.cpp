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
const int MN = 4e5 + 5;
int a[MN], b[MN], c[MN];

void solve(){
	int n, m;
    cin >> n;
    set<int> l, r;
    for(int i = 1; i <= n; ++i) cin >> a[i], l.insert(a[i]);
    for(int i = 1; i <= n; ++i) cin >> b[i], r.insert(b[i]);
    for(int i = 1; i <= n; ++i) cin >> c[i];
    sort(c+1, c+n+1);
    priority_queue<pair<int, pair<int, int>>> q;
    for(int i = 1; i <= n; ++i) {
        int _r = *r.upper_bound(a[i]);
        q.push({-(_r - a[i]), {a[i], _r}});
    }
    std::vector<int> len;
    while(!q.empty()) {
        auto [L, I] = q.top(); q.pop();
        auto [u, v] = I;
        // cerr << u << " " << v << "\n";
        if(!l.count(u)) {
            // cerr << "\?\\n";
            continue;
        }
        if(!r.count(v)) {
            // cerr << "aaa\?\n";
            int _r = *r.upper_bound(u);
            q.push({-(_r - u), {u, _r}}); 
            continue;
        }
        l.erase(u);
        r.erase(v);
        len.push_back(-L);
    }
    long long ans = 0;
    // assert(len.size() == n);
    for(int i = 0; i < n; ++i) {
        ans = ans + 1ll * len[i] * c[n-i];
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