#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
vector<int>e[5];
int vis[N];
int main(){
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  for(int i=1;i<=k;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    y--;
    e[y].push_back(x);
  }
  int ans=-1;
  for(int i=0;i<(1<<5);i++){
    for(int j=0;j<5;j++){
      if((i>>j)&1){
	for(auto v:e[j])vis[v]=i+1;
      }
    }

    int cnt=0;
    for(int j=1;j<=n;j++){
      if(vis[j]!=i+1)++cnt;
    }
    if(cnt<=m)ans=max(ans,cnt);
  }
  if(ans==-1){
    puts("Round will be unrated");
  }
  else{
    printf("%d\n",ans);
  }
}
