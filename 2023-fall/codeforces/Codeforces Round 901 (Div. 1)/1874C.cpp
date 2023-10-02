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
// int a[MN];

#define double long double
double b[MN], f[5005][5005];
vector<pair<double, int>> G[MN];

double p[5005],p2[5005];

void init() {
    // p[0] = 0;
    // for(int i = 1; i <= 5000; ++i) p[i] = p[i-1] + log(i);
    // p2[0] = p2[1] = 0;
    // for(int i = 2; i <= 5000; ++i) p2[i] = p2[i-2] + log(i);

    for(int i = 1; i <= 5000; ++i) {
        if(i%2==1) {
            for(int j = 1; j <= i; ++j) f[i][j] = 1.0/i;
        } else {
            for(int j = 1; j <= i/2; ++j) f[i][j] = 1.0/i;            
        }
    }

    f[2][2]=.5;
    for(int i = 2; i <= 2500; ++i) {
        for(int j = 1; j <= i-1; ++j) {
            f[i*2][i+j]=f[(i-1)*2][i-1+j]*(i+j-2)/(2*i);
        }
        f[i*2][i*2]=f[i*2][i*2-1];
    }
    for(int i = 1; i <= 2500; ++i) {
        for(int j = 1; j <= i; ++j)
            f[i*2][i+j]=f[i*2][i+j-1]-f[i*2][i+j];
    }

    //  for(int i = 1; i <= 10; ++i) {
    //      for(int j = 1; j <= i; ++j) cerr << f[i][j] << " ";
    //      cerr << "\n";
    //  }
}

void solve(){
	int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back({0, y});
    }
    b[n] = 1.0;
    for(int i = n-1; i; --i) {
        b[i] = 0;
        for(auto &[w, y] : G[i]) w=b[y];
        sort(all(G[i]));
        reverse(all(G[i]));
        for(int j = 0; j < G[i].size(); ++j) {
            b[i] += G[i][j].first * f[G[i].size()][j+1];
        }
    }
    cout << fixed << setprecision(12) << b[1] << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
    init();
	while(T--) 
		solve();
}