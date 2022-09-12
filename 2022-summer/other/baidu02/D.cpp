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
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
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
int a[MN], b[MN], c[MN], n, m, q, k, p[MN], d[MN];
std::vector<pii> G[MN];
priority_queue<pii> qu;
bool in[MN];
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // ios::sync_with_stdio(0); cin.tie(0);
    n = read(), m = read(), q = read();
    REP(i, 0, m) {
        int x = read();
        int y = read();
        int w = read();
        G[x].pb(mkp(y, w));
        G[y].pb(mkp(x, w));
    }
    REP(_, 0, q) {
        k = read();
        REP(i, 1, n + 1) in[i] = 0;
        int nm = 0;
        REP(i, 0, k) {
            p[i] = read(), d[i] = read(), qu.push(mkp(d[i], p[i]));
            if(!in[p[i]]) ++nm, in[p[i]] = 1; 
        }
        while(!qu.empty()) {
            pii o = qu.top(); qu.pop();
            if(in[o.se]) continue;
            // dfs()
        }
        printf("%d\n", nm);
    }
    return 0;
}
//写废了
//应该是每个点开个bitset