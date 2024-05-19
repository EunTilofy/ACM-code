#include<bits/stdc++.h>
using namespace std;
const int N=2*7005;

namespace flow {
    int S,T,head[N],kl=1,n,INF=1e9,dis[N],cur[N];
    struct edge{
        int v,flow,next;
    }e[8*N];
    void add_edge(int x,int y,int w){
        e[++kl]={y,w,head[x]};
        head[x]=kl; 
     //   cout<<"add "<<x<<" "<<y<<" "<<w<<endl;
    }
    void add(int x,int y){
        y=y+n;
        add_edge(x,y,INF);
        add_edge(y,x,0);
    }
    void reset(int m){
        n=m;
        S=2*n+1;
        T=2*n+2;
        for(int i=1;i<=n;i++){
            add_edge(S,i,1);
            add_edge(i,S,0);
            add_edge(i+n,i,INF);
            add_edge(i,i+n,0);
            add_edge(i+n,T,1);
            add_edge(T,i+n,0);
        }
    }
    int bfs(){
        queue<int>q;
        q.push(S);
        for(int i=1;i<=T;i++)dis[i]=INF;
        dis[S]=0;
        while(!q.empty()){
            int x=q.front();
         //   cout<<"bfs: "<<x<<endl;
            q.pop();
            if(x==T)return 1;
            for(int i=head[x];i;i=e[i].next){
                int v=e[i].v;
                if(e[i].flow==0)continue;
              //  cout<<"v: "<<v<<" "<<dis[v]<<" "<<dis[x]+1<<endl;
              //  if(v==T)return 1;
                if(dis[v]>dis[x]+1){
                    dis[v]=dis[x]+1;
                    q.push(v);
                }
            }
        }
        return 0;
    }
    int mp[N],id=0;
    int fnd(int x){
        if(x==S||x==T)return 0;
        if(x>n)return x-n;
        return x;
    }
    int dfs(int x,int in,int c){
        if(x==T){
            mp[fnd(x)]=c;
            return in;
        }
        if(in==0)return 0;
        int out=0;
        for(int &i=cur[x];i;i=e[i].next){
            int v=e[i].v;
            if(dis[v]==dis[x]+1){
         //       cout<<"flow "<<x<<" "<<v<<endl;
                int w=dfs(v,min(in,e[i].flow),c);
                in-=w;
                out+=w;
                if(w)mp[fnd(v)]=c;
            //    cout<<"modify "<<x<<" "<<e[i].flow<<" "<<e[i^1].flow<<endl;
                e[i].flow-=w;
                e[i^1].flow+=w;
                if(in==0)return out;
            }
        }
        if(out)mp[fnd(x)]=c;
        return out;
    }

    int fa[N];
    int find(int x){
        if(x==fa[x])return x;
        else return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
    }
    void max_flow(){
        int ans=0;
        /*
        bfs();
        for(int i=1;i<=T;i++)cur[i]=head[i];
            ans+=dfs(S,2e9);
        for(int x=1;x<=T;x++){
            for(int i=head[x];i;i=e[i].next){
                int v=e[i].v;
                cout<<x<<" "<<v<<" "<<e[i].flow<<endl;
            }
        }
        */
       int rnd=0;
        while(bfs()){
            for(int i=1;i<=T;i++)cur[i]=head[i];
            ans+=dfs(S,2e9,++rnd);
         /*   cout<<"round "<<endl;
            for(int x=1;x<=T;x++){
            for(int i=head[x];i;i=e[i].next){
                int v=e[i].v;
                if(!(i&1))
                cout<<x<<" "<<v<<" "<<e[i].flow<<endl;
            }
        }
        */
        }
       // for(int i=1;i<=n;i++)cout<<mp[i]<<" ";cout<<endl;
    }
}
vector<int>e[N];
int dfn[N],low[N],cc,col[N];
int indec,in[N];
vector<int>bel[N];
vector<int>st;
void dfs(int x){
    dfn[x]=low[x]=++indec;
    in[x]=1;
    st.push_back(x);
    for(auto v:e[x]){
        if(!dfn[v]){
            dfs(v);
            low[x]=min(low[x],low[v]);
        }
        else {
            if(in[v])low[x]=min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]){
        ++cc;
        while(st.back()!=x){
            col[st.back()]=cc;
            bel[cc].push_back(st.back());
            in[st.back()]=0;
            st.pop_back();
        }
        col[st.back()]=cc;
            in[st.back()]=0;
            bel[cc].push_back(st.back());
            st.pop_back();
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    map<pair<int,int>,int>mp;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        mp[{x,y}]=1;
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])dfs(i);
    }
    flow::reset(cc);
  //  for(int i=1;i<=n;i++)cout<<col[i]<<" ";
   // cout<<endl;

    for(int i=1;i<=cc;i++){
        for(int j=1;j<=cc;j++){
            int ok=0;
            if(i==j)continue;
            for(auto x:bel[i]){
                if(ok)break;
                for(auto y:bel[j]){
                    if(mp.find({x,y})!=mp.end()){
                        ok=1;break;
                    }
                }
            }
            if(ok){
        //        cout<<"add! "<<i<<" "<<j<<endl;
                flow::add(i,j);
            }
        }
    }
    
    flow::max_flow();
    for(int i=1;i<=n;i++){
        cout<<flow::mp[col[i]]<<" ";
    }
    
}