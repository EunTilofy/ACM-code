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
// #define mk make_pair
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
vector<pair<int, int> > a[MN];
vector<int> g[MN];
bool ve[MN];
int vs[MN], mk[MN];
int res;

void dfs(int x, int fa) {
    vs[x] = 1;
    for(int i = 0; i < a[x].size(); ++i) {
        int to = a[x][i].first, id = a[x][i].second;
        if(ve[id]) continue;
        ve[id] = 1;
        if(vs[to]) {
            // printf("to = %d\n", to);
            mk[++res] = x;
            g[to].push_back(res);
        } else {
            g[x].push_back(to);
            dfs(to, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n = read(), m = read();
    res = n;
    for(int i = 1; i <= n; ++i) mk[i] = i;
    for(int i = 1, x, y; i <= m; ++i) {
        x = read(), y = read();
        a[x].push_back(make_pair(y, i)), a[y].push_back(make_pair(x, i));
    }
    dfs(1, 0);
    printf("%d\n", res);
    for(int i = 1; i <= res; ++i) printf("%d ", mk[i]);
    puts("");
    for(int i = 1; i <= res; ++i) {
        for(int j = 0; j < g[i].size(); ++j) {
            printf("%d %d\n", i, g[i][j]);
        }
    }
    return 0;
}