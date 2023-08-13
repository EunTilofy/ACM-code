#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=405,mo=1e9+7;
int s[N][N],a[N][N];
int fac[N],inv[N];
int H[N][N],h[N][N];
int qpow(int a,int b){
  int res=1;
  for(;b;b>>=1,a=a*a%mo){
    if(b&1)res=res*a%mo;
  }
  return res;
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
int C(int n,int m){
  if(n<m)return 0;
  return fac[n]*inv[m]%mo*inv[n-m]%mo;
}
signed main(){
  int n,m;
  scanf("%lld%lld",&n,&m);
  init();
  for(int i=1;i<=max(n,m);i++){
    for(int j=1;j<=max(n,m)-i;j++){
      for(int k=0;k<=min(i,j);k++)
	(s[i+j][k]+=C(i-1,k)*C(j-1,k)%mo)%=mo;
	//cout<<i<<" "<<j<<" "<<k<<"   "<<i+j<<' '<<k<<' '<<s[i+j][k]<<endl;
    }
  }
///  for(int i=0;i<=n;i++){
   // for(int j=0;j<=n;j++){
      //cout<<s[i][j]<<' ';
      
    //}
    //cout<<endl;
//  }
  h[1][1]=1;
  for(int i=2;i<=max(n,m);i++){
    h[i][1]=1;
      for(int k=1;k<=n;k++){
    for(int j=1;j<=i-2;j++){
	(h[i][k]+=h[j][k-1]*(i-j-1)%mo)%=mo;
      }
  //  cout<<i<<" "<<k<<" "<<h[i][k]<<endl;
    }
  }
  int ans=0;

  for(int k=1;k<=max(n,m);k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
	(H[i][j]+=h[i][k]*h[j][k]%mo)%=mo;
      }
    }
  }
  for(int k=1;k<=max(n,m);k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
	ans=(ans+s[n-i][k-1]*s[m-j][k-1]%mo*H[i][j]%mo*i%mo*j%mo)%mo;
//	cout<<i<<" "<<j<<" "<<k<<" "<<s[n-i][k-1]<<" "<<s[m-j][k-1]<<" "<<ans<<endl;
      }
    }
  }
  ans=(ans+H[n][m]*(n*m%mo)%mo)%mo;
  printf("%lld\n",ans);
}
