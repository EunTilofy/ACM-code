#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infL 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN], n, m;
std::set<int> S1;
std::set<int> S2;
std::vector<pii> G[MN];
void dfs1(int x, int _, int f, int val) {
    if(f != 0) S1.insert(val);
    for(auto y : G[x]) if(y.fi != f && y.fi != _) {
        dfs1(y.fi, _, x, val ^ y.se);
    }
}
void dfs2(int x, int f, int val) {
    if(f != 0) S2.insert(val);
    for(auto y : G[x]) if(y.fi != f) {
        dfs2(y.fi, x, val ^ y.se);
    }
}
void solve() {
    cin>>n;S1.clear();S2.clear();S1.insert(0);
    bool fl = 0;
    int A, B;
    cin>>A>>B;
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i < n; ++i) {
        int w, x, y;
        cin>>x>>y>>w;
        G[x].pb(mkp(y, w));
        G[y].pb(mkp(x, w));
    } 
    dfs1(A, B, 0, 0);
    dfs2(B, 0, 0);

    // for(auto x: S1) {
    //     dbg2(x);
    // }
    // for(auto y : S2) {
    //     dbg2(y);
    // }

    for(auto x : S1) fl |= S2.count(x);
    if(fl) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}