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
inline int fpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int Dec(int x, int y){return (x+mod-y)%mod;}
#define cerr std::cerr
#define cout std::cout
#define cin std::cin
const int MN = 4e5 + 5;
int a[MN], b[MN], c[MN];
void solve()
{
	int n;
    cin >> n;
    vector<pair<pair<int,int>, vector<int>>> opt;
    vector vec(n, vector<int>(n));
    for(int i = 0; i < n; ++i) vec[0][i] = i+1;
    for(int j = 1; j < n; ++j)
    {
        vec[j][n-1] = n;
        for(int k = n-1, cnt=1; cnt <= j; ++cnt, --k) vec[j][cnt-1] = k;
        for(int k = 1, cnt = j; cnt < n-1; ++k, ++cnt) vec[j][cnt] = k;
    }
    vector a(n, vector<int>(n));
    auto OPT = [&](int type, int id, vector<int> _) -> void {
        if(type == 1)
        {
            a[id-1] = _;
        }
        else
        {
            for(int i = 0; i < n; ++i) a[i][id-1] = _[i];
        }
    };
    auto PUSH = [&](int type, int id, vector<int> _) -> void {
        opt.push_back({{type, id}, _});
        OPT(type, id, _);
    };
    PUSH(1, n, vec[0]);
    for(int i = 1; i < n; ++i)
    {
        PUSH(1, i, vec[i]);
        PUSH(2, i, vec[i]);
    }
    long long sm = 0;
    for(auto _ : a) for(auto __ : _) sm += __;
    cout << sm << " " << opt.size() << "\n";
    for(auto _ : opt)
    {
        cout << _.first.first << " " << _.first.second << " ";
        for(auto __ : _.second) cout << __ << " ";
        cout << "\n";
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}