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
int a[MN];
vector<int> G[MN];
// set<int> S;
long long ans = 0;
// void dfs1(int x, int f) {
//     bool de = 0;
//     if(S.count(a[x])) ++ans;
//     else S.insert(a[x]), de = 1;

//     for(auto y : G[x]) if(y != f) {
//         dfs1(y, x);
//     }
//     if(de) S.erase(a[x]);
// }
set<pair<int,int>> s[MN];
int id[MN];
void dfs2(int x, int f) {
    id[x] = x;
    for(auto y : G[x]) if(y != f) {
        dfs2(y, x);
        auto k = s[id[y]].lower_bound({a[x], 0});
        if(k != s[id[y]].end() && (k->first == a[x])) ans += k->second, s[id[y]].erase(*k);
        if(s[id[x]].size() < s[id[y]].size()) swap(id[x], id[y]);
        for(auto [col, num] : s[id[y]]) {
            if(col != a[x]) {
                auto k = s[id[x]].lower_bound({col, 0});
                if(k != s[id[x]].end() && (k->first == col)) ans += 1ll * num * (k->second);
            }
        }
        for(auto [col, num] : s[id[y]]) if(col != a[x]) {
            auto k = s[id[x]].lower_bound({col, 0});
            int NUM = num;
            if(k != s[id[x]].end() && (k->first == col)) {
                NUM += k->second; s[id[x]].erase(*k);
            }
            s[id[x]].insert({col, NUM});
        }
    }
    s[id[x]].insert({a[x], 1});
}

void solve(){
	int n, m;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], G[i].clear(), s[i].clear();
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    ans = 0;
    // dfs1(1, 0);
    // S.clear();
    dfs2(1, 0);
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}