#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int indec;
const int mo=1e9+7;
struct edge{
  int u,v,l;
  int f[2][2];
  int g[2][2];
  edge(){
    memset(f,0,sizeof(f));
    for(int i:{0,1})for(int j:{0,1})f[i][j]=0;
    u = v = l=0;
  }
  edge(int uu, int vv,int ll) : u(uu), v(vv),l(ll){
    f[0][0]=0; f[0][1]=0; f[1][0]=0; f[1][1]=ll;
    g[0][0]=1; g[0][1]=0; g[1][0]=0; g[1][1]=1;
  }
  void rev(){
    swap(u,v);
    swap(f[0][1],f[1][0]);
    swap(g[0][1],g[1][0]);
  }
  pair<int,int> cal(){
    pair<int,int>ans={0,0};
    for(int i:{0,1})for(int j:{0,1}){
      ans=max(ans,{f[i][j],g[i][j]});
    }
    return ans;
  }
}t[N<<2];
set<pair<int,int>>e[N];
int merge(edge a,edge b){
  if(a.v==b.u){
  }
  else if(a.u==b.u){
    a.rev();
  }
  else if(a.v==b.v){
    b.rev();
  }
  else {
    a.rev();
    b.rev();
  }
  if(a.v!=b.u)assert(0);
  ++indec;
  t[indec].u=a.u;
  t[indec].v=b.v;
  for(int i:{0,1})for(int j:{0,1})for(int k:{0,1})for(int l:{0,1}){
    if(!(j&&k)){
      if(t[indec].f[i][l]<a.f[i][j]+b.f[k][l]){
	t[indec].f[i][l]=a.f[i][j]+b.f[k][l];
	t[indec].g[i][l]=(1ll*a.g[i][j]*b.g[k][l])%mo;

      }
      else if(t[indec].f[i][l]==a.f[i][j]+b.f[k][l]){
	t[indec].f[i][l]=a.f[i][j]+b.f[k][l];
	(t[indec].g[i][l]+=(1ll*a.g[i][j]*b.g[k][l])%mo)%=mo;
      }
    }
  }
  return indec;
}
int place(edge a,edge b){
  if(a.v!=b.v)a.rev();
  ++indec;
  t[indec].u=a.u;
  t[indec].v=a.v;
  if(a.v!=b.v)assert(0);
  for(int i:{0,1})for(int j:{0,1})for(int k:{0,1})for(int l:{0,1}){
    if(!(i&&k)&&!(j&&l)){
      if(t[indec].f[i|k][j|l]<a.f[i][j]+b.f[k][l]){
	t[indec].f[i|k][j|l]=a.f[i][j]+b.f[k][l];
	t[indec].g[i|k][j|l]=(1ll*a.g[i][j]*b.g[k][l])%mo;
      }

      else if(t[indec].f[i|k][j|l]==a.f[i][j]+b.f[k][l]){
	t[indec].f[i|k][j|l]=a.f[i][j]+b.f[k][l];
	(t[indec].g[i|k][j|l]+=(1ll*a.g[i][j]*b.g[k][l])%mo)%=mo;
      }
    }
  }
  return indec;
}
void insert(int x,int v,int c){
  auto it=e[x].lower_bound({v,0});
  if(it!=e[x].end()&&(*it).first==v){
    int pre=(*it).second;
    int cur=place(t[c],t[pre]);
    e[x].erase({v,pre});
    e[v].erase({x,pre});
    e[x].insert({v,cur});
    e[v].insert({x,cur});
  }
  else{
    e[x].insert({v,c});
    e[v].insert({x,c});
  }
}
int ban[N];
void solve(int n){
  for(int i=1;i<=n;i++)ban[i]=0;
  queue<int>q;
  for(int i=1;i<=n;i++){
    if(e[i].size()==2){
      q.push(i);
    }
  }
  while(!q.empty()){
    int x=q.front();
    q.pop();
    if(ban[x])continue;
    if(e[x].size()!=2)continue;
    ban[x]=1;
    auto it=e[x].begin();
    auto itt=it;
    ++itt;
    int e1=(*it).second;
    int e2=(*itt).second;
    int cur=merge(t[e1],t[e2]);
    e[t[cur].u].erase({x,e1});
    e[t[cur].v].erase({x,e2});
    insert(t[cur].v,t[cur].u,cur);
    if(e[t[cur].v].size()==2){
      q.push(t[cur].v);
    }
    if(e[t[cur].u].size()==2){
      q.push(t[cur].u);
    }
  }
  for(int i=1;i<=n;i++){
    if(!ban[i]){
      if(e[i].size()!=2)assert(0);
      int x=(*e[i].begin()).second;
      auto res=t[x].cal();
      if(res.first<0)assert(0);
      if(res.second<0)assert(0);
      printf("%lld %lld\n",res.first,res.second);
      return; 
    }
  }
  assert(0);
}
signed main(){
  int T;
  scanf("%lld",&T);
  while(T--){
    int n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=indec;i++){
      t[i]=edge();
    }
    indec=0;
    for(int i=1;i<=n;i++){
      e[i].clear();
    }
    for(int i=1;i<=m;i++){
      int x,y,z;
      scanf("%lld%lld%lld",&x,&y,&z);
      t[++indec]=edge(x,y,z);
      insert(x,y,indec);
    }
    solve(n);
  }
}
