#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
#define N 2000005
using namespace std;
ll dis[N];
int vis[N];
int n,m,x;
struct sett{
  int u,v;
  ll w;
  friend bool operator <(sett a,sett b){return a.w<b.w;}
}lib[N];
struct qaq{
  int id;
  ll x;
  friend bool operator <(qaq a,qaq b){return a.x>b.x;}
};
priority_queue<qaq> q;
struct zero{
  int nxt,to;
  ll dis;
}edge[N<<1];
int head[N],tot=0;
void add_edge(int a,int b,ll c){edge[++tot]=(zero){head[a],b,c};head[a]=tot;}
void spfa(int s,ll lim){
  for(int i=1;i<=n;i++)dis[i]=1e18,vis[i]=0;
  dis[s]=0;q.push((qaq){s,0});
  while(!q.empty()){
    qaq nw=q.top();q.pop();
    int x=nw.id;
    if(vis[x])continue;
    vis[x]=1;
    // cout<<"start:"<<x<<endl;
    for(int i=head[x];i;i=edge[i].nxt){
      int to=edge[i].to;
      if(edge[i].dis>lim)continue;
      if(dis[to]>dis[x]+edge[i].dis){
        dis[to]=dis[x]+edge[i].dis;
        if(!vis[to]){
          q.push((qaq){to,dis[to]});
        }
      }
    }
   
  }
}
ll s1,s2,t1,t2,limit;
int main(){
  scanf("%d%d%d",&n,&m,&x);
  for(int i=1;i<=m;i++){
    scanf("%d%d%lld",&lib[i].u,&lib[i].v,&lib[i].w);
    add_edge(lib[i].u,lib[i].v,lib[i].w);
    add_edge(lib[i].v,lib[i].u,lib[i].w);
  } 
  sort(lib+1,lib+m+1);
  spfa(1,1e18);
  limit=1ll*dis[n]*(100+x)/100;
  // cout<<"limit:"<<limit<<endl;
  int l=1,r=m,mid,ans=m;
  while(l<=r){
    mid=(l+r)>>1;
    int u=lib[mid].u,v=lib[mid].v,w=lib[mid].w;
    spfa(1,w);
    if(dis[n] <= limit) {ans = mid; r = mid - 1;}
    else l = mid + 1;
  }
  printf("%lld\n",lib[ans].w);
}
/*
9 8 30
1 9 16
1 4 4
4 5 4
5 6 4
6 8 4
4 7 5
7 8 5
8 9 4
*/