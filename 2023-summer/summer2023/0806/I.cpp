#include<bits/stdc++.h>
using namespace std;
const int N=600005;
vector<int>e[N];
int a[N];
map<int,vector<int>>mp;
int col[N];
int n,m,Q;
int rst[N][21]; 
int main(){
  scanf("%d%d%d",&n,&m,&Q);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
    mp[a[i]].push_back(i);
  }
  int id=0;
  for(auto [key,val]:mp){
    ++id;
    for(auto v:val){
      col[v]=id;
    }
  }
  for(int i=1;i<=m;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    if(col[x]>col[y]) swap(x,y);
    if(col[x]<col[y]) rst[col[x]][0]=max(rst[col[x]][0],col[y]);	    
  }
  for(int i=1;i<=id;i++){
    if(rst[i-1][0] > rst[i][0]) rst[i][0]=max(rst[i][0],rst[i-1][0]);
  }
  for(int j=1;j<=20;j++){
    for(int i=1;i<=id;i++){
      rst[i][j]=rst[rst[i][j-1]][j-1];
      // rst[i][j]=max(rst[i][j],rst[i-1][j]);
    }
  }
  /*
  for(int j=0;j<=4;j++)
  for(int i=1;i<=n;i++){
    cout<<rst[i][j]<<" ";
  }
  cout<<endl;
  */
  while(Q--){
    int x,y;
    char s[10];
    scanf("%s%d%d",s,&x,&y);
    x=col[x],y=col[y];
    int ans=0;
    if(x < y) {
    //  int ans=0;
    for(int i=20;i>=0;i--){
      if(rst[x][i]&&rst[x][i]<y){	
	      ans+=(1<<i);
      	//cout<<x<<" "<<rst[x][i]<<" "<<ans<<endl;
	      x=rst[x][i];
      }
    }
    if(x<y){
      x=rst[x][0];
      ans++;
    } 
    }
    if(x>=y) printf("%d\n",ans);
    else puts("-1");
  }
}
