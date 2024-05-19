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
int a[1005][1005];

void solve()
{
	int n, K;
    cin >> n >> K;
    for(int i = 1; i <= n; ++i) for(int j = i; j <= n; ++j) cin >> a[i][j];
    // vector<multiset<int>> _(vector<multiset<int>>(n+2));
    // _[n+1].insert(0);
    // int i,j;
    // for(i=n;i>=1;--i)
    // {
    //     for(j=n;j>=i;--j)
    //     for(auto &x : _[min(j+2, n+1)])
    //     {
    //         _[i].insert(x + a[i][j]);
    //         if(_[i].size() > K) _[i].erase(_[i].begin()); 
    //     }
    //     for(auto &x : _[i+1])
    //     {
    //         _[i].insert(x);
    //         if(_[i].size() > K) _[i].erase(_[i].begin()); 
    //     }
    // }
    // vector<int> final;
    // for(auto x : _[1]) final.push_back(x);
    // reverse(all(final));
    // for(auto x : final) cout << x << " ";
    // cout << "\n";
    vector<vector<int>> f(n+1, vector<int>(K+1));

    f[0][0] = 0; f[0].resize(1);
    f[1][0] = max(0, a[1][1]);
    f[1][1] = min(0, a[1][1]);
    f[1].resize(2);
    for(int i = 2; i <= n; ++i) 
    {
        priority_queue<pair<int,pair<int,int>>> S;
        for(int j = i - 2; j >= 0; --j) S.push({f[j][0] + a[j+2][i], {j, 0}});
        S.push({a[1][i], {-1, -1}});
        S.push({f[i-1][0], {i-1, 0}});
        int pos = 0;
        while(!S.empty() && pos < K)
        {
            auto [val, _] = S.top(); S.pop();
            f[i][pos++] = val;
            auto [j, u] = _;
            if(j != -1 && u != -1)
            if(u + 1 < f[j].size()) S.push({f[j][u+1] + (j == i-1? 0 : a[j+2][i]), {j, u+1}});
        }
        // cerr << i << " " << pos << "\n";
        f[i].resize(pos);
    }
    for(int i = 0; i < K; ++i) cout << f[n][i] << " ";
    cout << "\n";
    // priority_queue<int, vector<int>, greater<int>> _final;
    // for(auto &F : f)
    // {
    //     for(auto &x : F)
    //     {
    //         _final.push(x);
    //         if(_final.size() > K) _final.pop();
    //     }
    // }
    // vector<int> final;
    // while(!_final.empty()) final.push_back(_final.top()), _final.pop();
    // std::reverse(all(final));
    // for(auto x : final) cout << x << " ";
    // cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}