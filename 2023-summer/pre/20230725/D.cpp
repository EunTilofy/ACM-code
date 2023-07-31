#include<bits/stdc++.h>
using namespace std;
const int N=2505;
#define double long double
double f[N][N];
int a[N],b[N],sz[N];
double sum[N];
double cur;
int k,n;
vector<int>e[N];
void dfs(int x){
  sum[x]=a[x]-cur*b[x];
  f[x][0]=0;
  for(auto v:e[x]){
    dfs(v);
    sum[x]+=sum[v];
    for(int i=sz[x];i>=0;i--){
      for(int j=sz[v];j>=0;j--){
	f[x][i+j]=min(f[x][i+j],f[x][i]+f[v][j]);
      }
    }
    sz[x]=sz[x]+sz[v];
  }
  sz[x]++;
  if(x!=1)f[x][sz[x]]=sum[x];
  /*
  for(int i=0;i<=n;i++){
    cout<<x<<' '<<i<<" "<<f[x][i]<<endl;
  }
  */
}
double check(double mid){
  cur=mid;
  for(int i=1;i<=n;i++){
    sz[i]=0;
    sum[i]=0;
    for(int j=0;j<=n;j++){
      f[i][j]=1e12;
    }
  }
  dfs(1);
//  cout<<mid<<" "<<" "<<sum[1]<<" "<<f[1][n-k]<<endl;
  return sum[1]-f[1][n-k-1];
}
int main(){
  scanf("%d%d",&k,&n);
  n++;
  for(int i=2;i<=n;i++){
    int x;
    scanf("%d%d%d",&b[i],&a[i],&x);
    x++;
    e[x].push_back(i);
  }
  double l=0,r=1e8;
  for(int i=1;i<=100;i++){
    double mid=(l+r)/2;
    if(check(mid)<0){
      r=mid;
    }
    else{
      l=mid;
    }
  }
  printf("%.3Lf\n",r);

}
