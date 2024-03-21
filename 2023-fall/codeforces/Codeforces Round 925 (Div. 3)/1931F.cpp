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

vector<int> G[MN];
bool vis[MN], in[MN]; int now;
int dfn[MN], low[MN], q[MN], top;

bool chk(int x) {
    vis[x] = 1; dfn[x] = low[x] = ++now;
    bool fl = 1;
    in[x] = 1; q[++top] = x;
    for(auto y : G[x]) {
        if(!vis[y]) {
            fl &= chk(y);
            low[x] = min(low[x], low[y]);
        }
        else if(in[y]) {
            fl = 0;
            // cout << x << " " << y << "!!!\n";
            low[x] = min(low[x], dfn[y]);
        }
    }
    if(low[x] == dfn[x]) {
        while(q[top] != x) in[q[top]] = 0, --top;
        in[x] = 0; --top;
    }
    return fl;
}

void solve(){
	int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; ++i) {
        int last = 0, x;
        cin >> x; 
        if(n == 1) continue;
        cin >> last;
        if(n == 2) continue;
        for(int j = 3; j <= n; ++j) {
            cin >> x;
            G[last].push_back(x);
            last = x;
        }
    }
    for(int i = 1; i <= n; ++i) {
        sort(G[i].begin(), G[i].end());
        G[i].resize(unique(G[i].begin(), G[i].end()) - G[i].begin());
    }
    bool flg = 1; now = 0;
    // cout << n << "_________" << m << "\n";
    for(int i = 1; i <= n; ++i) if(!vis[i]&&flg) {flg&=chk(i);}

    cout << (flg?"YES":"NO") << "\n";

    for(int i=1;i<=n;++i) G[i].clear(), vis[i] = dfn[i] = low[i] = in[i] = top = q[i] = now = 0;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}