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
#define mod 1000000007
inline int qpow(int x,ll y=mod-2,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
int f[2][MN], g[2][MN], n;
std::vector<int> G[MN];
int Mul(int x, int y) {return (1ll * x * y) % mod;}
int Add(int x, int y) {return (x + y) % mod;}
void dfs(int x, int F) {
    f[1][x] = 1;f[0][x] = 0;
    g[1][x] = 0;g[0][x] = 0;
    int id=-1,res,fl=0;
    REP(i, 0, G[x].size()) if(G[x][i] != F) {
        dfs(G[x][i], x);
        f[0][x] = Add(f[0][x], Add(f[1][G[x][i]], f[0][G[x][i]]));
        g[0][x] = Add(g[0][x], Add(g[1][G[x][i]], g[0][G[x][i]]));
        f[1][x] = Mul(f[1][x], Add(1, f[1][G[x][i]]));
        if(Add(1,f[1][G[x][i]]))res=Mul(res,Add(1,f[1][G[x][i]]));
        else if(id==-1)id=G[x][i];
        else fl=1;
    }
    g[1][x]=f[1][x];
    if(fl)return;
    REP(i, 0, G[x].size()) if(G[x][i] != F) {
        if(id==-1)g[1][x] = Add(g[1][x], Mul(Mul(qpow(Add(1, f[1][G[x][i]])),g[1][G[x][i]]),f[1][x]));
        else if(id==G[x][i])g[1][x] = Add(g[1][x], Mul(res,g[1][G[x][i]]));
    }
    // dbg1(x); dbg1(g[0][x]); dbg2(g[1][x]);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    n = read();
    REP(i, 1, n) {
        int x = read();
        int y = read();
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1, 0);
    int ans1, ans2;
    ans1 = Add(f[1][1], f[0][1]);
    ans2 = Add(g[1][1], g[0][1]);
    printf("%d %d\n", ans1, ans2);
    return 0;
}
/*
5
4 2
2 5
3 2
5 1

*/