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
#define mod 1000000007
#define dbg1(x) cerr << #x << '=' << (x) << ' '
#define dbg2(x) cerr << #x << '=' << (x) << '\n'
#define dbg3(x) cerr << #x << '\n'
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
int a[MN], dep[MN], siz[MN];
vector<int> G[MN];
#define int long long
int n, m;
long long ans = 0;
void dfs1(int x, int f) {
    siz[x] = 1;
    dep[x] = dep[f] + 1;
    for(auto y : G[x]) if(y != f){
        dfs1(y, x);
        siz[x] += siz[y];
    }
    long long all = 0, _ = 0;
    vector<int> son;
    for(auto y : G[x]) if(y != f) {
        son.push_back(siz[y]);
    }
    son.push_back(n - siz[x]);

    int now = 0, now2 = 0;
    for(auto y : son) {
        // ans += 1ll * y * now2 % mod;
        ans %= mod;
        now2 = (now2 + y * now % mod) % mod;
        now += y;
    }
    ans = (ans + now2 + n - 1) % mod;
}
void dfs2(int x, int f) {
    siz[x] = 1;
    dep[x] = dep[f] + 1;
    for(auto y : G[x]) if(y != f){
        dfs2(y, x);
        siz[x] += siz[y];
    }
    long long all = 0, _ = 0;
    vector<int> son;
    for(auto y : G[x]) if(y != f) {
        son.push_back(siz[y]);
    }
    son.push_back(n - siz[x]);

    int now = 0, now2 = 0;
    for(auto y : son) {
        ans += 1ll * y * now2 % mod;
        ans %= mod;
        now2 = (now2 + y * now % mod) % mod;
        now += y;
    }
    ans = (ans + now2) % mod;
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    if(m == 1) {
        cout << 1 << endl;
        return;
    }
    if(m == 2) {
        dfs1(1, 0);
        long long nm1 = 1ll * n * (n - 1) / 2 % mod;
        cout << 1ll*ans*qpow(nm1,mod-2)%mod;
    }
    if(m == 3) {
        dfs2(1, 0);
        long long nm1 = 1ll * n * (n - 1) * (n - 2) / 6ll % mod;
        cout << 1ll*ans*qpow(nm1,mod-2)%mod;
    }
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T = 1;
	while(T--) 
		solve();
}