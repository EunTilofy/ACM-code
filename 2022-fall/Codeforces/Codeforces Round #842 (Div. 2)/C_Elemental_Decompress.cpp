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
int a[MN], b[MN], c[MN], d[MN];
const int inv2 = (mod + 1)/2, inv3 = (mod + 1)/3, inv4 = (mod * 2 + 1) / 4;
bool cmp(int x, int y) {return a[x] < a[y];}
vector<pii> G[MN];
std::vector<pii> ans;
void dfs(int x) {
    // cout << x << endl;
    c[x] = 1;
    for(auto y : G[x]) {
        int to = y.fi;
        int ed = y.se;
        if(d[ed] == 1) continue;
        d[ed] = 1;
        if(ans[ed].se == x) swap(ans[ed].se, ans[ed].fi);
        if(c[to] == 0) {
            dfs(to);
        }
        else {
            return;
        }
    }
}
void solve(){
	int n;
	cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = i;
    sort(b + 1, b + n + 1, cmp);
    std::multiset<int> s;
    std::vector<bool> has(n+1);
    ans.resize(n+1);
    for(int i = 1; i <= n; ++i) s.insert(i), s.insert(i);
    for(int i = 1; i <= n; ++i) {
        if(!s.count(a[i])) {
            cout << "NO" << endl;
            return ;
        }
        s.erase(s.find(a[i]));
    }
    for(int i = 1; i <= n; ++i) {
        int nm = *(s.begin());
        if(nm > a[b[i]]) {
            cout << "NO" << endl;
            return;
        }        
        ans[b[i]] = {nm, a[b[i]]};
        s.erase(s.find(nm));
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i <= n; ++i) {
        if(ans[i].fi != ans[i].se) G[ans[i].fi].pb({ans[i].se, i}), G[ans[i].se].pb({ans[i].fi, i});
    }
    for(int i = 1; i <= n; ++i) c[i] = 0, d[i] = 0;
    for(int i = 1; i <= n; ++i) if(c[i] == 0) {
        dfs(i);
    }
    for(int i = 1; i <= n; ++i) cout << ans[i].fi << " ";cout << endl;
    for(int i = 1; i <= n; ++i) cout << ans[i].se << " ";cout << endl;
    return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}