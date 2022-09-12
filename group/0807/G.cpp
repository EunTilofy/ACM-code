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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
int n;
std::vector<int> G[MN];
//oular  
int xu[MN], _o, l[MN], o[MN][22], fa[MN], dep[MN];

void dfs_o(int x, int f) {
    xu[++_o] = x;
    l[x] = _o;
    fa[x] = f;
    dep[x] = dep[f] + 1;
    for(int i = 0; i < G[x].size(); ++i) if(G[x][i] != f) {
        int y = G[x][i];
        dfs_o(G[x][i], x);
        xu[++_o] = x;
    }
}
int lg[MN];
int LCA(int x, int y) {
    x = l[x]; y = l[y];
    if(x > y) swap(x, y);
    int j = lg[y - x + 1];
    if(dep[o[x][j]] < dep[o[y-(1<<j)+1][j]]) return o[x][j];
    return o[y-(1<<j)+1][j];
}
int DIS(int x, int y) {
    return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}

struct block {
    int ans[MN];
    int l, r;
}B[500];
int mindep[MN], mindis[MN];
void dfs1(int id, int L, int R, int x) {
    mindep[x] = inf;
    mindis[x] = inf;
    if(x>=L&&x<=R) {
        B[id].ans[x] = 0;
        mindep[x] = dep[x];
    }
    for(int i = 0; i < G[x].size(); ++i) if(G[x][i] != fa[x]) {
        int y = G[x][i];
        dfs1(id, L, R, y);
        mindep[x] = min(mindep[x], mindep[y]);
    }
    if(mindep[x] < inf) B[id].ans[x] = min(B[id].ans[x], mindep[x] - dep[x]);
    mindis[x] = mindep[x] - dep[x];
}
void dfs2(int id, int L, int R, int x) {
    mindis[x] = min(mindis[fa[x]] + 1, mindis[x]);
    B[id].ans[x] = min(B[id].ans[x], mindis[x]);
    for(int i = 0; i < G[x].size(); ++i) if(G[x][i] != fa[x]) {
        int y = G[x][i];
        dfs2(id, L, R, y);
    }
}
int nowl[MN], nowr[MN], BL;
int get(int x, int _l, int _r) {
    int i;
    int ret = inf;
    for(i = _l; i <= _r && i % BL != 1; ++i) {
        ret = min(ret, DIS(i, x));
    }
    for( ; i + BL - 1<=_r; i += BL) {
        int id = (i-1) / BL + 1;
        int y = B[id].ans[x];
        ret = min(ret, B[id].ans[x]);
    }
    for(; i <= _r; ++i) {
        ret = min(ret, DIS(i, x));
    }
    return ret;
}
int main() {
    // freopen("G.out","w",stdout);
    // freopen("G.in","r",stdin);
    int T = read();
    for(int i = 2; i <= 300000; i <<= 1) lg[i] = lg[i >> 1] + 1;
    for(int i = 3; i <= 300000; ++i) lg[i] = max(lg[i], lg[i - 1]);
    for(int _T = 1; _T <= T; ++_T) {
        mindis[0] = inf;
        printf("Case %d:\n", _T);
        n = read();
        for(int i = 1; i <= n; ++i) G[i].clear();
        for(int i = 1; i < n; ++i) {
            int x = read();
            int y = read();
            G[x].pb(y); G[y].pb(x);
        }
        _o = 0; dfs_o(1, 0);
        for(int i = 1; i <= _o; ++i) o[i][0] = xu[i];
        for(int j = 1; j <= 20; ++j) for(int i = 1; i <= _o; ++i) {
            if(i + (1<<j) - 1 > _o) break;
            if(dep[o[i][j - 1]] < dep[o[i + (1<<(j - 1))][j - 1]])
                o[i][j] = o[i][j - 1];
            else o[i][j] = o[i + (1<<(j-1))][j - 1];
        }
        BL = (int) min(n, (int)sqrt(n + 2));
        for(int i = 1; i <= n; i += BL) {
            int id = (i - 1) / BL + 1;
            B[id].l = i;
            B[id].r = min(n, i + BL - 1);
            for(int j = 1; j <= n; ++j) B[id].ans[j] = inf;
            dfs1(id, B[id].l, B[id].r, 1);
            dfs2(id, B[id].l, B[id].r, 1);
        }

        int Q = read();
        while(Q--) {
            int opt = read();
            if(opt == 1) {
                int x = read(); 
                nowl[x] = read();
                nowr[x] = read();
            }
            else if (opt == 2) {
                int x = read();
                nowl[x] = 0;
                nowr[x] = 0;
            }
            else if(opt == 3) {
                int x = read();
                int m = read();
                int ans = inf;
                while(m--) {
                    int k = read();
                    int L = nowl[k], R = nowr[k];
                    if(!L||!R) continue;
                    int y = get(x, L, R);
                    ans = min(ans, y);
                }
                if(ans >= n) puts("-1");
                else printf("%d\n", ans);
            }
        }
    }
    return 0;
}
/*
2
6
1 4
1 5
1 6
5 2
5 3
4
1 1 2 3
3 5 1 1
2 1
3 4 1 1
2
1 2
2
1 100000 1 1
3 2 1 100000
*/