#include<bits/stdc++.h>
using namespace std;
const int mo=1e9+7;
const int N=2e7+5;
int fac[N],inv[N];
int qpow(int a,int b){
  int res=1;
  for(;b;b>>=1,a=1ll*a*a%mo){
    if(b&1)res=1ll*res*a%mo;
  }
  return res;
}
int binom(int n,int m){
  if(n>=0&&m>=0&&n-m>=0)
    return 1ll*fac[n]*inv[n-m]%mo*inv[m]%mo;
  else return 0;
}
void init(){
  fac[0]=1;
  for(int i=1;i<N;i++){
    fac[i]=1ll*fac[i-1]*i%mo;
  }
  inv[N-1]=qpow(fac[N-1],mo-2);
  for(int i=N-2;i>=0;i--){
    inv[i]=1ll*inv[i+1]*(i+1)%mo;
  }
}
signed main(){
  int m,c;
  int Q;
  init();
  scanf("%d",&Q);
  while(Q--){
    scanf("%d%d",&m,&c);
    m--;
  int res=0;
    for(int i=0;i<=m;i++){
      int x=(binom(2*m-i,m)-binom(2*m-i,m-i-1)+mo)%mo;
      if(c-1){
	res+=1ll*x*qpow(c,i+1)%mo*qpow(c-1,m-i)%mo;
	res%=mo;
      }
    }
    if(c==1){
      puts("1");
    }
    else{
      printf("%d\n",res);
    }
  }
}