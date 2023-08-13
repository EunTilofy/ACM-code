#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
const int mo=1e9+7;
const int N=1e7+5;
int fac[N],inv[N];
int qpow(int a,int b){
  int res=1;
  for(;b;b>>=1,a=a*a%mo){
    if(b&1)res=res*a%mo;
  }
  return res;
}
int binom(int n,int m){
  if(n>=0&&m>=0&&n-m>=0)
    return fac[n]*inv[n-m]%mo*inv[m]%mo;
  else return 0;
}
void init(){
  fac[0]=1;
  for(int i=1;i<N;i++){
    fac[i]=fac[i-1]*i%mo;
  }
  for(int i=0;i<N;i++){
    inv[i]=qpow(fac[i],mo-2);
  }
}
signed main(){
  int m,c;
  int Q;
  init();
  scanf("%lld",&Q);
  while(Q--){
    scanf("%lld%lld",&m,&c);
    m--;
  int res=0;
    for(int i=0;i<=m;i++){
      int x=(binom(2*m-i,m)-binom(2*m-i,m-i-1)+mo)%mo;
      if(c-1){
	res+=x*qpow(c,i+1)%mo*qpow(c-1,m-i+1)%mo;
	res%=mo;
      }
    }
    if(c==1){
      puts("1");
    }
    else{
      printf("%lld\n",res);
    }
  }
}
