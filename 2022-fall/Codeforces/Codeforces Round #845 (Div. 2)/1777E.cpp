#include"bits/stdc++.h"
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
#define inf 0x3f3f3f3f
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
const int MN = 3e5 + 5;
int dfn[MN], bel[MN], low[MN], dind, block, deg[MN], st[MN], tp;
bool in[MN];
int n, m;
vector<pair<pair<int,int>, int> > GG;
vector<int> G[MN];
void tj(int x) {
    // cerr << x << endl;
    low[x] = dfn[x] = ++dind;
    st[++tp] = x; in[x] = 1;
    for(auto y : G[x]) {
        if(!dfn[y]) {
            tj(y);
            low[x] = min(low[x], low[y]);
        }
        else if(in[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if(dfn[x] == low[x]) {
        ++block;
        while(st[tp] != x) {
            bel[st[tp]] = block;
            in[st[tp--]] = 0;
        }
        bel[st[tp]] = block;
        in[st[tp--]] = 0;
    }
}

bool check() {
    dind = 0; block = 0; tp = 0;
    for(int i = 1; i <= n; ++i) dfn[i] = low[i] = bel[i] = in[i] = 0;
    for(int i = 1; i <= n; ++i) if(!dfn[i]) tj(i);
    // cerr << block << endl;
    // for(int i = 1; i <= n; ++i) cerr << bel[i] << " "; cerr << endl;
    int xx = 0;
    for(int i = 1; i <= block; ++i) deg[i] = 0;
    for(int i = 1; i <= n; ++i) for(auto y : G[i]){
        // cerr << i << " " << y << endl;
        if(bel[i] != bel[y]) {
            
            ++deg[bel[y]];
        }
    }
    // cerr << "ssss" << endl;
    for(int i = 1; i <= block; ++i) xx += (deg[i] == 0);
    // cerr << xx << endl;
    return xx == 1;
}

bool chk(int val) {
    for(int i = 1; i <= n; ++i) {
        G[i].clear();
    }
    for(int i = 0; i < m; ++i) {
        int x = GG[i].fi.fi;
        int y = GG[i].fi.se;
        if(GG[i].se <= val) {
            // cerr << x << y << endl;
            G[x].pb(y);
            G[y].pb(x);
        }
        else G[x].pb(y);
    }
    // cerr << "sr" << endl;
    return check();
}

void solve(){
    cin >> n >> m;
    GG.clear();
    for(int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        GG.pb({{x, y}, w});
    }
    int ans = 1000000000+5, l = 0, r = 1000000000;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(chk(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    if(ans > 1000000000) ans = -1;
    cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}