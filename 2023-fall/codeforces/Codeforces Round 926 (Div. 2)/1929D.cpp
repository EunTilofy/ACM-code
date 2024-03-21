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
int f[MN][3];
vector<int> G[MN];
void dfs(int x, int af) {
    if(G[x].size() == 1 && G[x][0] == af) {
        f[x][0] = 1;
        f[x][1] = 1;
        f[x][2] = 0;
        return ;
    }
    for(auto y : G[x]) if(y != af) dfs(y, x);
    f[x][0] = 1; f[x][1] = 1; f[x][2] = 0;
    for(auto y : G[x]) if(y != af) {
        f[x][1] = Mul(f[x][1], Add(f[y][0], f[y][1]));
        f[x][0] = Mul(f[x][0], f[y][0]);
        f[x][2] = Add(f[x][2], Add(f[y][2], f[y][1]));
    }
    // dbg1(x); dbg1(f[x][0]); dbg1(f[x][1]); dbg2(f[x][2]);
}

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) f[i][0] = f[i][1] = f[i][2] = 0, G[i].clear();
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    cout << Add(Add(f[1][0], f[1][1]), f[1][2]) << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}