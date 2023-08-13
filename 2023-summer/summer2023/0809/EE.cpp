#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=1e9;
int indec;
const int mo=1e9+7;
struct edge{
  int u,v,l;
  int f[2][2];
  int g[2][2];
  edge(){
    memset(f,0,sizeof(f));
    for(int i:{0,1})for(int j:{0,1})f[i][j]=0;
    u = v = 0;
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
  void pr(){
    cout<<u<<' '<<v<<' '<<l<<"   "<<f[0][0]<<" "<<f[0][1]<<' '<<f[1][0]<<" "<<f[1][1]<<endl;
  }
}t[N];
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
  ++indec;
  a.pr(),b.pr();
  t[indec].u=a.u;
  t[indec].v=b.v;
      a.pr();
      b.pr();
  for(int i:{0,1})for(int j:{0,1})for(int k:{0,1})for(int l:{0,1}){
    if(!(j&&k)){
      if(t[indec].f[i][l]<a.f[i][j]+b.f[k][l]){
	t[indec].f[i][l]=a.f[i][j]+b.f[k][l];
	t[indec].g[i][l]=(a.g[i][j]*b.g[k][l])%mo;

      }
      else if(t[indec].f[i][l]==a.f[i][j]+b.f[k][l]){
	t[indec].f[i][l]=a.f[i][j]+b.f[k][l];
	(t[indec].g[i][l]+=(a.g[i][j]*b.g[k][l])%mo)%=mo;
      }
    }
  }
  t[indec].pr();
  return indec;
}
int place(edge a,edge b){
  if(a.v!=b.v)a.rev(),b.rev();
  if(a.v!=b.v)assert(0);
  ++indec;
  t[indec].u=a.u;
  t[indec].v=a.v;
  cout<<"place "<<endl;
  a.pr();
  b.pr();
  for(int i:{0,1})for(int j:{0,1})for(int k:{0,1})for(int l:{0,1}){
    if(!(i&&k)&&!(j&&l)){
      if(t[indec].f[i|k][j|l]<a.f[i][j]+b.f[k][l]){
	t[indec].f[i|k][j|l]=a.f[i][j]+b.f[k][l];
	t[indec].g[i|k][j|l]=(a.g[i][j]*b.g[k][l])%mo;

      }
    else if(t[indec].f[i|k][j|l]==a.f[i][j]+b.f[k][l]){
	t[indec].f[i|k][j|l]=a.f[i][j]+b.f[k][l];
	(t[indec].g[i|k][j|l]+=(a.g[i][j]*b.g[k][l])%mo)%=mo;
      }
    }
  }
  t[indec].pr();
  return indec;
}
void insert(int x,int v,int c){
  auto it=e[x].lower_bound({v,0});
  if(it!=e[x].end()&&(*it).first==v){
    cout<<"here "<<endl;
    int pre=(*it).second;
    int cur=place(t[c],t[pre]);
    cout<<e[2].size()<<endl;
    e[x].erase({v,pre});
    e[v].erase({x,pre});
    e[x].insert({v,cur});
    e[v].insert({x,cur});
    cout<<e[2].size()<<endl;
    cout<<"replace "<<x<<" "<<v<<endl;
    cout<<"replace "<<v<<" "<<x<<endl;
  }
  else{
    e[x].insert({v,c});
    e[v].insert({x,c});
    cout<<"insert "<<x<<" "<<v<<endl;
    cout<<"insert "<<v<<" "<<x<<endl;
  }
}
int ban[N];
void solve(int n){
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
    cout<<endl;
    cout<<"round  "<<x<<endl;
    cout<<"heeeeeere "<<e[2].size()<<endl;
    cout<<e[x].size()<<endl;
    for(auto [a,b]:e[x])cout<<a<<" "<<b<<"    ";
    cout<<endl;
    auto it=e[x].begin();
    auto itt=it;
    ++itt;
    int e1=(*it).second;
    int e2=(*itt).second;
    cout<<x<<endl;
    cout<<e1<<' '<<e2<<endl;
    int cur=merge(t[e1],t[e2]);
    cout<<e[2].size()<<endl;
    e[t[cur].u].erase({x,e1});
    e[t[cur].v].erase({x,e2});
    cout<<e[2].size()<<endl;
    cout<<"del "<<t[cur].v<<" "<<x<<endl;
    cout<<"del "<<t[cur].u<<" "<<x<<endl;
    cout<<e[t[cur].v].size()<<"     "<<e[t[cur].u].size()<<endl;
    insert(t[cur].v,t[cur].u,cur);
    if(e[t[cur].v].size()==2){
    cout<<" in "<<t[cur].v<<endl;
      q.push(t[cur].v);
    }
    if(e[t[cur].u].size()==2){
    cout<<" in "<<t[cur].u<<endl;
      q.push(t[cur].u);
    }
  }
  for(int i=1;i<=n;i++){
  cout<<i<<" "<<ban[i]<<" "<<e[i].size()<<endl;
    if(!ban[i]){
      int x=(*e[i].begin()).second;
      t[x].pr();
      auto res=t[x].cal();
      cout<<res.first<<' '<<res.second<<endl;
      assert(0);
      return; 
    }
  }
  assert(0);
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      t[++indec]=edge(x,y,z);
      e[x].insert({y,indec});
      e[y].insert({x,indec});
    }
    solve(n);
  }
}
