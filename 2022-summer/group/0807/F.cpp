#include<bits/stdc++.h>
#define ll long long
#define db double
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

const int N = 1e4 + 10, LOG = 16;
vector<int> g[N];
int st[N], en[N], res = 0;
int d[N], G[N][LOG + 1];

void dfs(int x, int fa) {
    st[x] = ++res;
    d[x] = d[fa] + 1;
    G[x][0] = fa;
    for(int i = 1; i <= LOG; ++i) G[x][i] = G[G[x][i - 1]][i - 1];
    for(int i = 0; i < g[x].size(); ++i) {
        int u = g[x][i];
        if(u == fa) continue;
        dfs(u, x);
    }
    en[x] = res;
}

int lca(int x, int y) {
    // printf("!!%d %d\n", x, y);
    if(d[x] < d[y]) swap(x, y);
    for(int i = LOG; i >= 0; --i) {
        if(d[G[x][i]] >= d[y]) x = G[x][i];
    }
    for(int i = LOG; i >= 0; --i) {
        if(G[x][i] != G[y][i]) x = G[x][i], y = G[y][i];
    }
    if(x == y) return x;
    return G[x][0];
}

bool have(int x, int y) {
    return st[x] <= st[y] && en[y] <= en[x];
}
int deeper(int x,int y) {
    return d[x] > d[y] ? x : y;
}
int lower(int x, int y) {
    return d[x] < d[y] ? x : y;
}
struct P {
    int x, y, z;
    P(){}
    P(int _x, int _y, int _z) {
        x = _x, y = _y, z = _z;
    }
    bool check(int o) {
        if(!z) return 1;
        if(z < 0) return 0;
        return have(z, o) && (have(o, x) || have(o, y));
    }
    void read() {
        scanf("%d%d", &x, &y);
        z = lca(x, y);
    }
    int ans() {
        if(z < 1) return 0;
        return d[x] + d[y] - 2 * d[z];
    }
} tmp, val[N];
P merge(P a, P b) {
    if(!a.z) return b;
    if(!b.z) return a;
    if(a.z < 0 || b.z < 0) return P(0, 0, -1);
    if(d[a.z] < d[b.z]) swap(a, b);
    if(!b.check(a.z)) return P(0, 0, -1);
    if(a.z == b.z) {
        int t1 = deeper(lca(a.x, b.x), lca(a.x, b.y));
        int t2 = deeper(lca(a.y, b.x), lca(a.y, b.y));
        return P(t1, t2, lca(t1, t2));
    }
    int x = deeper(lca(a.x, b.y), lca(a.y, b.x));
    int y = deeper(lca(a.x, b.x), lca(a.y, b.y));
    return P(lower(x, y), deeper(x, y), lca(lower(x, y), deeper(x, y)));
}

void solve() {
    res = 0;
    int n = read();
    for(int i = 1; i <= n; ++i) for(int j = 0; j <= LOG; ++j) G[i][j] = 0;
    for(int i = 1; i <= n; ++i) g[i].clear();
    for(int i = 1, x, y; i < n; ++i) {
        x = read(), y = read();
        g[x].push_back(y), g[y].push_back(x);
    }
    dfs(1, 0);
    // for(int i = 1; i <= n; ++i) printf("d[%d] = %d, f[%d] = %d\n", i, d[i], i, G[i][0]);
    // printf("!!!lca = %d\n", lca(2, 2));
    int q = read();
    for(int o = 1, k; o <= q; ++o) {
        k = read();
        for(int i = 1; i <= k; ++i) {
            val[i].read();
            // printf("x = %d, y = %d, lca = %d\n", val[i].x, val[i].y, val[i].z);
            // printf("len = %d\n", val[i].ans());
        }
        for(int i = 2; i <= k; ++i) {
            val[1] = merge(val[1], val[i]);
            // printf("!!!x = %d, y = %d, z = %d\n", val[1].x, val[1].y, val[1].z);
        }
        if(val[1].z == -1) puts("0");
        else if(val[1].z == 0) puts("1");
        else printf("%d\n", val[1].ans() + 1);
        // else printf("ans = %d %d %d %d\n", val[1].x, val[1].y, val[1].z, val[1].ans() + 1);
    }
}

int main() {
    int T = read();
    for(int o = 1; o <= T; ++o) {
        printf("Case %d:\n", o);
        solve();
    }
    return 0;
}