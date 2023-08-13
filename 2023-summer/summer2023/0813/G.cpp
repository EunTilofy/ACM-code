#include<bits/stdc++.h>
using namespace std;
const int mo=242121643;
int c[200][200];
void init(){
  for(int i=0;i<200;i++){
    for(int j=0;j<=i;j++){
      if(i==j||j==0)c[i][j]=1;
      else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
    }
  }
  
}
int C(int n,int m){
  return c[n][m];
}
int main(){
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  init();
  while(1){
    int n,k,cnt=0;
    scanf("%d%d",&n,&k);
    if(n==0&&k==0)break;
    for(int i=1;i<=n;i++){
      int x;
      scanf("%d",&x);
      if(x==1)cnt++;
    }
    int ans=0;
    for(int i=1;i<=min(k,cnt);i+=2){
      (ans+=1ll*C(cnt,i)*C(n-cnt,k-i)%mo)%=mo;
    }
    printf("%d\n",ans);

  }
}
