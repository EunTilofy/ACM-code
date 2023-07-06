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
long long a[MN], b[MN], c[MN];

#define int long long

void solve(){
	long long n, m;
    cin >> n >> m;
    long long all = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i], all += b[i] - a[i] + 1ll;
    if(all < m) {
        cout << "-1" << endl;
        return ;
    }
    all = 0;
    long long ans = n * 2 + b[n];

    priority_queue<ll, vector<ll>, greater<ll>> q;
    int ret = 0;
    for(int i = 1; i <= n; ++i) {
        q.push(b[i] - a[i] + 1ll);
        all += b[i] - a[i] + 1ll;
        ++ret;
        while(all >= m && !q.empty()) {
            if(all - q.top() >= m) {
                ans = min(max(a[i], b[i] - (all - m)) + ret * 2, ans);
                all -= q.top();
                q.pop();
                --ret;
            }
            else break;
        }
        // cerr << b[i] << " " << ret << endl;
        if(all >= m) {
            ans = min(max(a[i], b[i] - (all - m)) + ret * 2, ans);
        }
    }
    // cerr << "---" << endl;
    cout << ans << endl;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}