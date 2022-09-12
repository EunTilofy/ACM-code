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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;

int n, m, k;
long long d[MN][21];
std::vector<pii> G[MN];
std::priority_queue<std::pair<ll, pii> > q;
signed main() {
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    n = read(), m = read(), k = read();
    REP(i, 0, m) {
        int x, y, z;
        x = read(), y = read(), z = read();
        G[x].pb(mkp(y, z));
        G[y].pb(mkp(x, z));
    }
    q.push(mkp(0ll, mkp(0, 1)));
    memset(d, 0x3f, sizeof(d));
    memset(d[1], 0, sizeof d[1]);
    while(!q.empty()) {
        std::pair<ll, pii> o = q.top();
        q.pop();
        ll dis = o.fi; int num = o.se.fi; int x = o.se.se;
        if(d[x][num] < dis) continue;
        REP(i, 0, G[x].size()) {
            int y = G[x][i].fi, w = G[x][i].se;
            if(d[y][num] > d[x][num] + w) {
                REP(j, num, k + 1) d[y][j] = min(d[y][j], d[x][num] + w);
                q.push(mkp(d[y][num], mkp(num, y)));
            }
        }
        if(num < k) {
            
        }
    }
    return 0;
}