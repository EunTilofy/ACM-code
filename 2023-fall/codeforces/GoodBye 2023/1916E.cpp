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
int tag[MN<<2], t[MN << 2], fa[MN];
vector<int> G[MN];

int dind, dfn[MN], L[MN], R[MN], val[MN], n;
int depcol[MN], dep[MN], a[MN], mx[MN];
long long Ans = 0;

vector<vector<pair<int, int>>> id[MN];

void Add(int x, int l, int r, int a, int b) {
    if(l == a && r == b) { tag[x] ++; return; }
    int mid = (l + r) >>1;
    if(b <= mid) Add(x<<1,l,mid,a,b);
    else if(a > mid) Add(x<<1|1,mid+1,r,a,b);
    else Add(x<<1,l,mid,a,mid), Add(x<<1|1,mid+1,r,mid+1,b);
    t[x] = max(t[x<<1] + tag[x<<1], t[x<<1|1] + tag[x<<1|1]);
}

int Que(int x, int l, int r, int a, int b) {
    if(l == a && r == b) {return tag[x] + t[x];}
    int mid = (l + r) >>1;
    if(b <= mid) return tag[x] + Que(x<<1,l,mid,a,b);
    if(a > mid) return tag[x] + Que(x<<1|1,mid+1,r,a,b);
    return tag[x] + max(Que(x<<1,l,mid,a,mid), Que(x<<1|1,mid+1,r,mid+1,b));
}

void init(int n) {
    for(int i = 1; i <= n; ++i) {
        G[i].clear(), 
        a[i] = fa[i] = L[i] = R[i] = dfn[i] = depcol[i] = dep[i] = val[i] = 0;
        mx[i] = 0;
        id[i].clear();
    }
    for(int i = 1; i <= n * 4; ++i) tag[i] = t[i] = 0;
    dind = 0;
    Ans = 0;
}


void dfs(int x) {
    L[x] = dfn[x] = ++dind;
    depcol[a[x]] ++;
    mx[a[x]] = max(mx[a[x]], depcol[a[x]]);
    dep[x] = depcol[a[x]];
    for(auto y : G[x]) {
        dfs(y);
    }
    R[x] = dind;
    depcol[a[x]] --;
}

void Dfs(int x) {
    for(auto y : G[x]) Dfs(y);

    vector<int> pos;
    pos.push_back(L[x] - 1);
    if(mx[a[x]] > dep[x]) {
        int num = upper_bound(id[a[x]][dep[x] + 1].begin(), id[a[x]][dep[x] + 1].end(), make_pair(L[x], 0)) - id[a[x]][dep[x] + 1].begin();
        for(; num < id[a[x]][dep[x] + 1].size() && id[a[x]][dep[x] + 1][num].first <= R[x]; ++num) {
            pos.push_back(id[a[x]][dep[x] + 1][num].first);
            pos.push_back(id[a[x]][dep[x] + 1][num].second);
        }
    }
    pos.push_back(R[x] + 1);

    for(int i = 0; i < pos.size(); i += 2) {
        if(pos[i] + 1 <= pos[i + 1] - 1) Add(1, 1, n, pos[i] + 1, pos[i + 1] - 1);
    }
    val[x] = Que(1, 1, n, L[x], R[x]);

    if(G[x].size() > 1) {
        vector<int> _;
        for(auto y : G[x]) {
            _.push_back(Que(1, 1, n, L[y], R[y]));
        }
        sort(_.begin(), _.end());
        reverse(_.begin(), _.end());
        Ans = max(Ans, 1ll * _[0] * _[1]);
    } else Ans = max(Ans, 1ll * val[x]);
}


void solve(){
    cin >> n;
    for(int i = 2; i <= n; ++i) {
        cin >> fa[i];
        G[fa[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        id[i].resize(mx[i] + 1);
    }
    for(int i = 1; i <= n; ++i) {
        id[a[i]][dep[i]].push_back({dfn[i], R[i]});
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= mx[i]; ++j) sort(id[i][j].begin(), id[i][j].end());
    }
    Dfs(1);
    cout << Ans << "\n";
    init(n);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--) 
		solve();
}