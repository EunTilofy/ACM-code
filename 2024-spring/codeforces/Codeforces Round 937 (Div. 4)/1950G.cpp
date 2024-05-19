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

bool f[16][16][1<<16|5];
int num[1<<16|5];

void solve(){
	int n;
    cin >> n;
    vector<vector<int>> e(n, vector<int>(n));
    int i, j, s;
    vector<pair<string, string>> a(n);
    for(auto &[x, y] : a) cin >> x >> y;
    for(i=0;i<n;++i)for(j=0;j<n;++j)
    {
        if(a[i].first==a[j].first||a[i].second==a[j].second)
        {
            e[i][j] = e[j][i] = 1;
        }
    }
    // function<int(int)> chk = [&](int x) -> int
    // {
    //     // vector<int> d(n);
    //     // fill(all(d), 0);
    //     // d[x] = 1;
    //     // priority_queue<pair<int,int>> q; q.push({1, x});
    //     // while(!q.empty())
    //     // {
    //     //     auto [_, y] = q.top(); q.pop();
    //     //     d[y] = max(d[y], _);
    //     //     for(auto v : e[y])
    //     //     {
    //     //         if(d[v] < d[y] + 1)
    //     //         {
    //     //             d[v] = d[y] + 1;
    //     //             q.push({d[v], v});
    //     //         }
    //     //     }
    //     // }
    //     // return *max_element(all(d));
        
    // };
    int ans = 1, all = (1<<n);
    for(i=0;i<n;++i)for(j=0;j<n;++j)for(s=0;s<all;++s)f[i][j][s]=0;
    for(i=0;i<n;++i) f[i][i][1<<i] = 1;
    for(s=0;s<all;++s)for(i=0;i<n;++i)for(j=0;j<n;++j)if(f[i][j][s])
    {
        ans=max(ans, num[s]);
        for(int k=0;k<n;++k) if(e[j][k]&&(s>>k&1)==0)
            f[i][k][s|(1<<k)] = 1;
    }
    cout << n - ans << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    num[1] = 1;
    num[2] = 1;
    for(int i = 3; i < (1<<16); ++i) num[i] = num[i-(i&-i)] + 1;
	int T;
	cin>>T;
	while(T--) 
		solve();
}