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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 10005, MM = 30005, INF = 1e9;
struct edge{int to, w, nex;}e[MM<<1], E[MN<<1];
int cur[MN], Hr[MN], hr[MN], En = 1, en = 1;
void ins(int x, int y, int w, int *h, edge *ed, int &tt) {
    ed[++tt]=(edge){y,w,h[x]},h[x]=tt;
    ed[++tt]=(edge){x,w,h[y]},h[y]=tt;
}
int d[MN], q[MN], top;
#define clr(x) memset((x), 0, sizeof (x))
bool bfs(int S, int T) {
    clr(d);
    int i,j;
    for(d[q[i=top=1]=S]=1;i<=top;++i)
        for(j=hr[q[i]];j;j=e[j].nex)
            if(e[j].w&&!d[e[j].to])
                d[q[++top]=e[j].to]=d[q[i]]+1;
    return d[T];
}
int dfs(int x, int T, int f) {
    if(x==T) return f;
    int used=0;
    for(int  &i=cur[x];i;i=e[i].nex)
    if(e[i].w&&d[e[i].to]==d[x]+1) {
        int tmp=dfs(e[i].to,T,min(f-used,e[i].w));
        e[i].w-=tmp,e[i^1].w+=tmp;used+=tmp;
        if(f==used) return f;
    }
    return d[x]=-1,used;
}
void clear(){
    for(int i = 2; i < en; i += 2) e[i].w=e[i^1].w=(e[i].w+e[i^1].w)>>1;
}
int dinic(int S, int T) {
    int maxflow = 0; clear();
    while(bfs(S,T)) {
        memcpy(cur,hr,sizeof cur);
        maxflow+=dfs(S,T,inf);
    }
    return maxflow;
}
void Build(int *id, int n) {
    if(n==1) return;
    static int s[MN], t[MN]; int cnts=0,cntt=0;
    int cut=dinic(id[0],id[1]);
    ins(id[0],id[1],cut,Hr,E,En);
    for(int i = 0; i < n; ++i)
        if(d[id[i]]) s[cnts++]=id[i];
        else t[cntt++]=id[i];
    memcpy(id,s,cnts<<2);
    memcpy(id+cnts,t,cntt<<2);
    if(cnts) Build(id,cnts);
    if(cntt) Build(id+cnts,cntt); 
}
int dep[MN],fa[MN][16],path[MN][16];
void init_dfs(int x, int f) {
    for(int i = Hr[x];i;i=E[i].nex) if(E[i].to!=f)
        dep[E[i].to]=dep[x]+1,fa[E[i].to][0]=x,path[E[i].to][0]=E[i].w,init_dfs(E[i].to,x);
}
void init(int n){
    dep[1]=1;init_dfs(1,-1);reg int i,j;
    for(i=1;i<10;++i)for(j=1;j<=n;++j) {
        fa[j][i]=fa[fa[j][i-1]][i-1];
        path[j][i]=min(path[j][i-1],path[fa[j][i-1]][i-1]);
    }
}
int Min(int x, int y) {
    int ret = 1e9;
    if(dep[x]>dep[y]) swap(x,y);
    int i,c=dep[y]-dep[x];
    for(i=10;~i;--i)if(c>>i&1) ret=min(ret,path[y][i]),y=fa[y][i];
    if(x==y) return ret;
    if(dep[x]!=dep[y]) return -1;
    for(i=10;~i;--i)if(fa[x][i]!=fa[y][i])
        ret=min(ret,min(path[x][i],path[y][i])),x=fa[x][i],y=fa[y][i];
    return min(ret,min(path[x][0],path[y][0]));
}
char s[605][605];
int name[405][605];
int id[MN];
void CLEAR() {
    clr(id);clr(name);
    clr(dep);clr(fa);clr(path);
    clr(d);clr(q);top=0;
    clr(cur);clr(Hr);clr(hr);En=1;en=1;
}
int main() {
    int T = read();
    for(int o = 1; o <= T; ++o) {
        long long ans = 0;
        int N = read(); int M = read();
        CLEAR();
        int n = 0;
        for(int i = 1; i <= 4 * N + 3; ++i) scanf("%[^\n]", s[i]), getchar();
        for(int i = 3; i <= 4 * N + 3; i += 2) {
            int len = strlen(s[i]);
            for(int j = 0; j < 6 * M + 3; ++j) if(s[i][j] == '*'){
                //+4 -4 2 6
                name[i][j] = ++n;
                if(i > 4 && name[i - 4][j] && s[i - 2][j] != '-') {
                    ins(n,name[i-4][j],1,hr,e,en);
                }
                if(i > 2 && j > 6 && name[i - 2][j - 6] && s[i - 1][j - 3] != '/'){
                    ins(n, name[i-2][j-6],1,hr,e,en);
                }
                if(i > 2 && name[i - 2][j + 6] && s[i - 1][j + 3] != '\\'){
                    ins(n, name[i-2][j+6],1,hr,e,en);
                }
            }
        }
        for(int i = 1; i <= n; ++i) id[i - 1] = i; Build(id, n);init(n);
        for(int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j) ans += Min(i, j);
        printf("Case #%d: %lld\n", o, ans);
    }
}
/*
2
2 2
  +---+
 /     \
+   *   +---+
 \     /     \
  +---+   *   +
 /           /
+   *   +   +
 \           \
  +---+   *   +
       \     /
        +---+
2 3
  +---+       +---+
 /     \     /     \
+   *   +---+       +
 \           \     /
  +---+   *   +---+
 /                 \
+   *   +---+   *   +
 \                 /
  +---+   *   +---+
       \     /
        +---+
*/