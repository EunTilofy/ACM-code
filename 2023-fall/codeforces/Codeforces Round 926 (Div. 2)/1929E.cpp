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

vector<int> G[MN], GG[MN];
int dep[MN], fa[MN][20];
int top, st[MN];

void dfs(int x, int f, int d) {
    fa[x][0] = f;
    for(int i = 1; i < 20; ++i) fa[x][i] = fa[fa[x][i-1]][i-1];
    dep[x] = d;
    for(auto y : G[x]) if(y != f) dfs(y, x, d + 1);
}
int lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 19; ~i; --i) if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    if(x == y) return x;
    for(int i = 19; ~i; --i) if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int Fa[MN], Dep[MN], Cov[MN];
vector<int> id[MN];
vector<int> nodes;
void Dfs(int x, int f) {
    nodes.push_back(x);
    Fa[x] = f; Dep[x] = Dep[f] + 1;
    for(auto y : GG[x]) if(y != f) Dfs(y, x);
}
void Cover(int x, int y, int i) {
    while(Dep[x] != Dep[y]) {
        if(Dep[x] > Dep[y]) Cov[x] ++, id[x].push_back(i), x = Fa[x];
        else Cov[y]++, id[y].push_back(i), y = Fa[y];
    }
    while(x != y) {
        Cov[x] ++; Cov[y] ++;
        id[x].push_back(i);
        id[y].push_back(i);
        x = Fa[x]; y = Fa[y];
    }
}
int findmx(int x, int y) {
    int mx = 0;
    while(Dep[x] != Dep[y]) {
        if(Dep[x] > Dep[y]) mx = max(Cov[x], mx), x = Fa[x];
        else mx = max(Cov[y], mx), y = Fa[y];
    }
    while(x != y) {
        mx = max(Cov[x], mx);
        mx = max(Cov[y], mx),
        x = Fa[x]; y = Fa[y];
    }
    return mx;
}
int cnt[(1<<21)];

void solve(){
	int n;
    cin >> n;
    nodes.clear();
    for(int i = 1; i <= n; ++i) {
        G[i].clear();
        GG[i].clear();
        dep[i] = 0;
        Fa[i] = 0;
        Dep[i] = 0;
        Cov[i] = 0;
        id[i].clear();
        st[i] = 0;
        memset(fa[i], 0, sizeof(fa[i]));
    }
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0, 1);
    set<int> val;
    int m;
    cin >> m;
    vector<pair<int,int>> I(m);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        I[i] = {x, y};
        val.insert(x); val.insert(y);
    }
    {
        GG[st[top=1]=(*val.begin())].clear();
        for(auto x : val) if(x != st[top]) { // leafs
            GG[x].clear();
            int y=lca(st[top], x);
            if(y == st[top]) {
                st[++top] = x;
                continue;
            }
            while(dep[st[top-1]]>dep[y]) {
                GG[st[top-1]].push_back(st[top]);
                top--;
            }
            if(y==st[top-1]) {
                GG[y].push_back(st[top]);
                top--;
            } else {
                GG[y].clear(); GG[y].push_back(st[top]);
                st[top]=y;
            }
            st[++top]=x;
        }
        while(top>1) GG[st[top-1]].push_back(st[top]),--top;
    }
    nodes.clear();
    Dfs(1, 0);
    for(int i = 0; i < m; ++i) Cover(I[i].first, I[i].second, i);
    vector<int> mx(m);
    int _ = 0;
    for(int i = 0; i < m; ++i) {
        mx[i] = findmx(I[i].first, I[i].second);
        if(mx[i] == 1) ++_;
    }
    vector<int> nm;
    for(auto x : nodes) if(Cov[x] > 1) {
        bool fl = 0;
        for(auto i : id[x]) {
            if(mx[i] > 1) if(Cov[x] == mx[i]) fl = 1;
        }
        if(fl) nm.push_back(x);
    }
    int all = nm.size(), S = (1ll<<all);
    int ans = all;
    for(int i = 0; i < S; ++i) {
        if(cnt[i] > ans) continue;
        set<int> has;
        for(int j = 0; j < all; ++j) if((i >> j)&1) for(auto y : id[j]) if(mx[y] > 1) has.insert(y);
        if(has.size() == m - _) ans = min(ans, cnt[i]);
    }
    cout << ans + _ << "\n";
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    for(int i = 1; i < (1<<21); ++i) {
        cnt[i] = cnt[i - (i&-i)] + 1;
    }
	int T;
	cin>>T;
	while(T--) solve();
}