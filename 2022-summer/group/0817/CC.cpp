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
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
#define mk make_pair
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
const int MN = 1e6+ 55;
int f[MN][2], g[MN][2], a[MN];
vector<int> G[MN];

void dfs(int x, int fa) {
    for(int i = 0; i < G[x].size(); ++i) {
        int to = G[x][i];
        if(to == fa) continue;
        dfs(to, x);
    }
    f[x][0] = f[x][1] = 1;
    g[x][0] = 0, g[x][1] = 1e9;
    for(int i = 0; i < G[x].size(); ++i) {
        int to = G[x][i];
        if(to == fa) continue;
        // puts("???");
        if(a[to] < a[x]) {
            f[x][0] &= f[to][1];
            f[x][0] &= (g[to][1] > a[x]);
            g[x][0] = max(a[to], g[x][0]);
            int pos = 0;
            if(f[to][1]) pos = max(pos, g[to][1]);
            if(f[to][0] && g[to][0] < a[x]) pos = max(pos, a[to]);
            if(pos) g[x][1] = min(g[x][1], pos);
            else f[x][1] = 0;
        } else if(a[to] > a[x]) {
            f[x][1] &= f[to][0];
            f[x][1] &= (g[to][0] < a[x]);
            g[x][1] = min(a[to], g[x][1]);
            int pos = 1e9;
            if(f[to][0]) pos = min(pos, g[to][0]);
            if(f[to][1] && g[to][1] > a[x]) pos = min(pos, a[to]);
            if(pos != 1e9) g[x][0] = max(g[x][0], pos);
            else f[x][0] = 0;
        } else {
            f[x][0] &= f[to][1];
            f[x][0] &= (g[to][1] > a[x]);
            g[x][0] = max(a[to], g[x][0]);
            f[x][1] &= f[to][0];
            f[x][1] &= (g[to][0] < a[x]);
            g[x][1] = min(a[to], g[x][1]);
        }
    }
    // printf("x = %d, %d %d \n", x, f[x][0], f[x][1]);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    for(int i = 1, x, y; i < n; ++i) {
        x = read(), y = read();
        G[x].push_back(y), G[y].push_back(x);
    }
    dfs(1, 0);
    // for(int i = 1; i <= n; ++i) {
    //     printf("%d %d, %d %d\n", f[i][0], f[i][1], g[i][0], g[i][1]);
    // }
    if(f[1][0] | f[1][1]) puts("YES");
    else puts("NO");
    return 0;
}