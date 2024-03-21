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
#define int long long
const int MN = 4e5 + 5;

struct node {
    long long sum, sm[2], s;
    long long mk[2];
};

node t[MN << 2];

bool in[MN];
long long val[MN], v1[MN], v2[MN];

void up(int k) {
    t[k].sum = t[k<<1].sum + t[k<<1|1].sum;
    t[k].sm[0] = t[k<<1].sm[0] + t[k<<1|1].sm[0];
    t[k].sm[1] = t[k<<1].sm[1] + t[k<<1|1].sm[1];
    t[k].s = t[k<<1].s + t[k<<1|1].s;
}
void down(int k, int l, int r) {
    int mid = (l + r) >>1;
    if(t[k].mk[0]) {
        t[k<<1].sm[0] = (mid - l + 1) * t[k].mk[0];
        t[k<<1|1].sm[0] = (r - mid) * t[k].mk[0];
        t[k<<1].sum = t[k<<1].sm[1] * t[k].mk[0];
        t[k<<1|1].sum = t[k<<1|1].sm[1] * t[k].mk[0];
        t[k<<1].s = (l + mid) * (mid - l + 1) / 2 * t[k].mk[0];
        t[k<<1|1].s=(mid + 1 + r) * (r - mid) / 2 * t[k].mk[0];
        t[k<<1].mk[0] = t[k<<1|1].mk[0] = t[k].mk[0]; t[k].mk[0] = 0;
    } if(t[k].mk[1]) {
        t[k<<1].sm[1] = (mid - l + 1) * t[k].mk[1];
        t[k<<1|1].sm[1] = (r - mid) * t[k].mk[1];
        t[k<<1].sum = t[k<<1].sm[0] * t[k].mk[1];
        t[k<<1|1].sum = t[k<<1|1].sm[0] * t[k].mk[1];
        t[k<<1].mk[1] = t[k<<1|1].mk[1] = t[k].mk[1]; t[k].mk[1] = 0;
    }
}

void build(int k, int l, int r) {
    if(l == r) {
        t[k].sum = 1ll * v1[l] * v2[l];
        t[k].sm[0] = v1[l];
        t[k].sm[1] = v2[l];
        t[k].s = v1[l] * l;
        return ;
    }
    int mid = (l + r) >> 1;
    build(k<<1,l,mid); build(k<<1|1,mid+1,r);
    up(k);
}

void modify(int k, int l, int r, int a, int b, bool nm, long long val) {
    if(l == a && r == b) {
        t[k].sm[nm] = val * (r - l + 1);
        t[k].sum = t[k].sm[nm^1] * val;
        t[k].mk[nm] = val;

        if(nm == 0) {
            t[k].s = val * (l + r) * (r - l + 1) / 2;
        }

        return ;
    }
    down(k, l, r);
    int mid = (l + r) >>1;
    if(b <= mid) modify(k<<1,l,mid,a,b,nm,val);
    else if(a > mid) modify(k<<1|1,mid+1,r,a,b,nm,val);
    else modify(k<<1,l,mid,a,mid,nm,val), modify(k<<1|1,mid+1,r,mid+1,b,nm,val);
    up(k);
}

long long que(int k, int l, int r, int a, int b) {
    if(l == a && r == b) {
        return t[k].sum - t[k].s;
    }
    down(k, l, r);
    int mid = (l + r) >>1;
    if(b <= mid) return que(k<<1,l,mid,a,b);
    if(a > mid) return que(k<<1|1,mid+1,r,a,b);
    return que(k<<1,l,mid,a,mid)+que(k<<1|1,mid+1,r,mid+1,b);
}
set<pair<int,long long>> all;


void solve(){
	int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int,long long>> a(m);
    for(int i = 1; i <= m; ++i) cin >> a[i-1].first;
    for(int i = 1; i <= m; ++i) cin >> a[i-1].second;
    for(int i = 1; i <= m; ++i) in[a[i-1].first] = 1, all.insert(a[i-1]);
    for(int i = 1; i <= m; ++i) val[a[i-1].first] = a[i-1].second; 
    int u = 0;
    for(int i = 1; i <= n; ++i) {
        v1[i] = u;
        if(in[i]) u = val[i];
    }
    u = n;
    for(int i = n; i; --i) {
        if(in[i]) u = i;
        v2[i] = u;
    }
    build(1, 1, n);
    while(q--) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if(opt == 2) {
            cout << que(1, 1, n, x, y) << "\n";
        } else {
            val[x] = y;
            // for(auto [x, y] : all) dbg1(x), dbg2(y);
            int r = (*all.upper_bound({x, 0})).first;
            int l = (*--all.upper_bound({x, 0})).first;
            // dbg1(l), dbg2(r);
            // l+1 x -> v2 -= r - x
            modify(1, 1, n, l+1, x, 1, x);
            // x+1 r
            modify(1, 1, n, x+1, r, 0, y);
            all.insert({x, y});
        }
    }
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int T = 1;
	while(T--) 
		solve();
}