#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int f[N],sf[N],uf[N];
int res[N];
vector<int>e[N];
void dfs(int x,int fa){
  for(auto v:e[x]){
    if(v==fa)continue;
    dfs(v,x);
    if(f[v]+1>=f[x]){
      sf[x]=f[x];
      f[x]=f[v]+1;
    }
    else if(f[v]+1>sf[x]){
      sf[x]=f[v]+1;
    }
    f[x]=max(f[x],f[v]+1);
  }
}
void udfs(int x,int fa){
  for(auto v:e[x]){
    if(v==fa)continue;
    if(f[v]+1==f[x]){
      uf[v]=sf[x]+1;
    }
    else {
      uf[v]=f[x]+1;
    }
    uf[v]=max(uf[v],uf[x]+1);
    udfs(v,x);
  }
  vector<int>s;
  for(auto v:e[x]){
  if(v!=fa)
    s.push_back(f[v]+1);
  }
  if(uf[x])s.push_back(uf[x]);
  sort(s.begin(),s.end());
  reverse(s.begin(),s.end());
  for(int i=0;i<s.size();i++){
    res[s[i]]=max(res[s[i]],i+1);
  }
}
int main(){
  freopen("amoeba.in","r",stdin);
  freopen("amoeba.out","w",stdout);
  int n,A,B;
  scanf("%d%d%d",&n,&A,&B);
  for(int i=1;i<n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(2,0);
  udfs(2,0);
  for(int i=n;i>=1;i--){
    res[i]=max(res[i],res[i+1]);
  }
  for(int i=A;i<=B;i++){
    printf("%d\n",res[i]);
    
  }
}
