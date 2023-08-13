#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int a[N],b[N],c[N],d[N],tmp[N],tmp2[N],res[N];
const int mo=175781251;
// const int mo=998244353;
int cc[300][300];
int qpow(int a,int b){
  int res=1;
  for(;b;b>>=1,a=1ll*a*a%mo){
    if(b&1)res=1ll*res*a%mo;
  }
  return res;
}
void init(){
  for(int i=0;i<300;i++){
    for(int j=0;j<=i;j++){
      if(i==j||j==0)cc[i][j]=1;
      else cc[i][j]=(cc[i-1][j-1]+cc[i-1][j])%mo;
    }
  }
  
}
int ans[N],rans[N];
int C(int n,int m){
  return cc[n][m];
}
int sqr(int x){
  for(int i=0;i<mo;i++){
    if(1ll*i*i%mo==x)return i;
  }
  return 0;
}
void getinv( int *a,int *b,int n){
  // b[0] = qpow(a[0], mo - 2);
  // for(int i = 1; i < n; ++i) {
  //   for(int j = 1; j <= i; ++j) b[i] = (b[i] + 1ll * a[j] * b[i-j] % mo) % mo;
  //   b[i] = (mo - b[i]) * 1ll * b[0] % mo;
  // }
  // for(int i = n; i < n * 2; ++i) b[i] = 0;
  if(n==1){
    b[0]=qpow(a[0],mo-2);
    return;
  }
  getinv(a,b,n>>1);
  int k=n<<1;
  for(int i=0;i<n;i++){
    tmp[i]=a[i];
  }
  for(int i=n;i<k;i++)tmp[i]=b[i]=0;
  for(int i=0;i<k;i++)d[i]=c[i]=0;
  for(int i=0;i<k;i++){
    for(int j=0;j<k;j++)if(i + j < k){
      (c[i+j]+=1ll*tmp[i]*b[j]%mo)%=mo;
    }
  }
  for(int i=0;i<k;i++){
    c[i]=(mo-c[i])%mo;
  }
  c[0] = (c[0] + 2) % mo;
  for(int i=0;i<k;i++){
    for(int j=0;j<k;j++)if(i + j < k){
      (d[i+j]+=1ll*c[i]*b[j]%mo)%=mo;
    }
  }
  for(int i=n;i<k;i++)b[i]=0;
  for(int i=0;i<n;i++)b[i]=d[i];
}
void getroot(int *a,int *b,int n){
  // b[0] = 1;
  // assert(a[0] == 1);
  // for(int i = 1; i < n; ++i) {
  //   b[i]=0;
  //   for(int j = 1; j <i; ++j) b[i] = (b[i] + b[j] * 1ll * b[i-j] % mo) %mo;
  //   b[i] = (a[i] - b[i]+mo) * 1ll * ((mo + 1) / 2) % mo;
  // }
  // for(int i = n; i < n * 2; ++i) b[i] = 0;
  if(n==1){
    b[0]=1;
    return;
  }
  getroot(a,b,n>>1);
  getinv(b,tmp2,n);
  int k=n<<1;
  for(int i=0;i<n;i++){
    tmp[i]=a[i];
  }
  for(int i=0;i<k;i++){
    res[i]=0;
  }
  for(int i=n;i<k;i++){
    tmp[i]=b[i]=0;
  }
  for(int i=0;i<k;i++){
    for(int j=0;j<k;j++)if(i + j < k){
      (res[i+j]+=1ll*b[i]*b[j]%mo)%=mo;
    }
  }
  for(int i=0;i<k;i++){
    res[i]=1ll*(res[i]+tmp[i])*qpow(2,mo-2)%mo;
    b[i]=0;
  }
  for(int i=0;i<k;i++){
    for(int j=0;j<k;j++)if(i + j < k){
      (b[i+j]+=1ll*tmp2[i]*res[j]%mo)%=mo;
    }
  }
  for(int i=n;i<k;i++)b[i]=0;
  
}
int fac[N],inv[N];
int rrans[N];
int main(){
    // freopen("bipartite.in", "r", stdin);
    // freopen("bipartite.out", "w",stdout);
  init();
  /*
  ans[0]=1;
  ans[1]=8596489;
  ans[2]=489489;
  ans[3]=4894;
*/
  // ans[0]=1;
  // ans[1]=6;
  // ans[2]=3;
  // ans[3]=4;
  // ans[4]=9;

  // int n=8;
  // getinv(ans,rans,n);
  // for(int i = 0; i < n; ++i) cout << rans[i] << " ";
  // cout << endl;
  // for(int i=0;i<n;i++)
  // for(int j=0;j<n;j++){
  //   rrans[i+j]=(rrans[i+j]+1ll*ans[i]*rans[j]%mo)%mo;
  // }
  // for(int i=0;i<2*n;i++)cout<<rrans[i]<<" ";
  // cout<<endl;
  int n=101;
  for(int i=0;i<n;i++)ans[i]=0;

  for(int i=1;i<n;i++){
    for(int j=0;j<=i;j++){
      (ans[i]+=1ll*C(i,j)*qpow(3,j*(i-j))%mo)%=mo;;
    }
  }
  fac[0]=1;
  for(int i=1;i<n;i++)fac[i]=1ll*fac[i-1]*i%mo;
  for(int i=0;i<n;i++)inv[i]=qpow(fac[i],mo-2);
  for(int i=0;i<n;i++){
    ans[i]=1ll*ans[i]*inv[i]%mo;
  }
  ans[0]=1;
  // for(int i=0;i<n;i++){
  //   cout<<1ll*ans[i]*fac[i]%mo<<" ";
  // }
  // cout<<endl;
  int m=1;
  while(m<n)m<<=1;
  getroot(ans,rans,m);
  // for(int i=0;i<n;i++){
  //   cout<<1ll*rans[i]*fac[i]%mo<<" ";
  // }
  while(1){
    int n;
    scanf("%d",&n);
    if(n==0)break;
    printf("%lld\n",1ll*rans[n]*fac[n]%mo);
  }
  return 0;
}
