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
const int MN = 3e5 + 5;
vector<int> a[MN];
int b[MN], c[MN];
vector<int> G[MN];
int dfs(int x, int f) {
    int ret = 0;
    map<int,int> mp;
    int son = 0;
    for(auto y : G[x]) if(y != f) {
        ++son;
        dfs(y, x);
        ret += dfs(y, x);
        for(auto v : a[y]) ++mp[v];
    }
    int mx = 0;
    vector<int> val;
    for(auto [xx, yy]: mp) {
        if(yy > mx) {
            mx = yy;
            val.clear();
            val.pb(xx);
        }
        else if(yy == mx) val.pb(xx);
    }
    cerr << x << " : " << son << " " << mx << endl;
    ret += son - mx;
    for(auto &vv : val) vv ^= a[x][0];
    a[x].clear();
    for(auto &vv : val) a[x].pb(vv);
    return ret;
}

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[i].push_back(x);
    }
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    cout << dfs(1, 0) << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T = 1;
	while(T--) 
		solve();
}