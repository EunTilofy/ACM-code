#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MN = 40210;
const int S = 40204;
const int T = 40205;

struct Flow {
public:
    ll d[MN], q[MN], top;
    int en = 1, cur[MN], hr[MN]; 
    struct edge{
        int to, nex;
        ll w;
    }e[MN*50];
    void ins(int x, int y, int w) {
        e[++en]=(edge){y, hr[x], w}; hr[x] = en;
        e[++en]=(edge){x, hr[y], 0}; hr[y] = en;
  //      cout<<"ins "<<x<<" "<<y<<" "<<w<<endl;
    }
    Flow() {en = 1;}
    bool bfs() {
        memset(d, 0, sizeof d);
        int i, j;
        for(d[q[i=top=1]=S]=1; i <= top; ++i)
            for(j=hr[q[i]];j;j=e[j].nex)
                if(e[j].w&&!d[e[j].to])
                    d[q[++top]=e[j].to]=d[q[i]]+1;
        return d[T];
    }
    int dfs(int x, ll f) {
        if(x==T) return f;
        int used = 0;
        for(int &i=cur[x];i;i=e[i].nex) {
            if(d[e[i].to]==d[x]+1&&e[i].w) {
                int tmp=dfs(e[i].to, min(f-used, e[i].w));
                e[i].w-=tmp;e[i^1].w+=tmp;used+=tmp;
                if(used==f) return used;
            }
        }
        return d[x]=-1, used;
    }
    ll dinic() {
        ll mf = 0;
        ll inf = 0x3f3f3f3f;
        while(bfs()) {
            memcpy(cur, hr, sizeof cur);
            mf += dfs(S, inf);
         //   assert(0);
        }
        return mf;
    }
}sol;

const int N=501;
int w[N],v[N];
int n;
int id(int i,int j){
    return j*n+i;
}
vector<int>e[N];
int dis[N][N];
void dfs(int x,int fa,int beg,int dep){
    dis[beg][x]=dep;
    for(auto v:e[x]){
        if(v==fa)continue;
        dfs(v,x,beg,dep+1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ans=n*v[n-1];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        dfs(i,0,i,0);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            if(j>=1)sol.ins(id(i,j),id(i,j-1),1e9);
            if(j>=1)sol.ins(S,id(i,j),v[j]-v[j-1]);
            if(j==0)sol.ins(S,id(i,j),v[j]);
        }
        for(int j=1;j<=n;j++){
            sol.ins(id(i,dis[i][j]),id(j,n),1e9);
        }
        sol.ins(id(i,n),T,w[i]);
    }
    ans-=sol.dinic();
    cout<<ans<<endl;

    // ins edge sol.ins(x, y, w);
    // get ans sol.dinic()

    return 0;
}