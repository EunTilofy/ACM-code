#include<bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define int long long
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mod 1000000007
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e6+ 55;
int n, val[MN], fa[MN], top[MN], dind, L[MN], R[MN], siz[MN], mx[MN], id[MN];
bool cmp_id(int x,int y){return val[x] < val[y];}
ll num[MN];
std::vector<int> G[MN];
void dfs1(int x, int FA) {
    siz[x] = 1;fa[x] = FA;
    long long cnt = 0;
    REP(i, 0, G[x].size()) if(G[x][i] != FA) {
        dfs1(G[x][i], x);
        if(siz[G[x][i]] > siz[mx[x]]) mx[x] = G[x][i];
        siz[x] += siz[G[x][i]];
        cnt -= 1ll * (siz[G[x][i]] + 1) * siz[G[x][i]] ;
    }
    // dbg1(x); dbg2(siz[x]);
    num[x] = 1ll * siz[x] * (n - siz[x]);
    cnt += 1ll * (siz[x] - 1) * siz[x];
    cnt/=2;
    num[x]+=cnt+siz[x];
}
void dfs2(int x, int Top) {
    top[x] = Top;
    L[x] = ++dind;
    if(mx[x]) dfs2(mx[x], Top);
    REP(i, 0, G[x].size()) if(G[x][i] != fa[x] && G[x][i] != mx[x]) {
        dfs2(G[x][i], G[x][i]);
    }
    R[x] = dind;
}
ll t[MN], T[MN];
ll sum_siz = 0;
void C(ll *_t, int x, int y) {for(; x <= n; x += (x & -x)) _t[x] += y;}
ll Get(ll *_t, int x) {ll r = 0; for(; x; x-= (x & -x)) r += _t[x]; return r;}
ll cal_fa(int x) {
    ll ret = 0;
    while(x) {
        ret += Get(T, L[x]) - Get(T, L[top[x]] - 1);
        x = fa[top[x]];
    }
    return ret;
}
void get(int x) {
    // siz[x] * siz[y]
    // dbg2(x);
    ll sumx = Get(t, R[x]) - Get(t, L[x] - 1);
    num[x] += 1ll * (sum_siz - sumx) * siz[x] % mod;
    num[x] %= mod; 
    // dbg2(num[x]);
    // fa
    // siz[x] * (n - siz[son] - siz[y])
    num[x] += 1ll * cal_fa(x) * siz[x];
    num[x] %= mod;
    // dbg2(num[x]);
    // son
    REP(i, 0, G[x].size()) if(G[x][i] != fa[x]) {
        num[x] += (Get(t, R[G[x][i]]) - Get(t, L[G[x][i]] - 1)) * (n - siz[G[x][i]]) % mod;
        num[x] %= mod;
    }
    // dbg2(num[x]);
    // dbg3(___________);
}
void upd(int x) {
    C(t, L[x], siz[x]);
    REP(i, 0, G[x].size()) if(G[x][i] != fa[x]) {
        C(T, L[G[x][i]], n - siz[G[x][i]] - siz[x]);
    }
    sum_siz += siz[x];
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);
    long long ans = 0;
    n = read();
    REP(i, 1, n + 1) val[id[i] = i] = read();
    REP(i, 1, n) {
        int x = read();
        int y = read();
        G[x].pb(y); G[y].pb(x);
    }
    dfs1(1, 0); dfs2(1, 1);
    std::sort(id + 1, id + n + 1, cmp_id);
    REP(i, 1, n + 1) {
        int x = id[i];
        get(x); upd(x);
    }
    // REP(i, 1, n + 1) dbg1(num[i]); dbg3();
    REP(i, 1, n + 1) ans += 1ll * num[i] * val[i], ans %= mod;
    printf("%lld\n", ans);
    return 0;
}