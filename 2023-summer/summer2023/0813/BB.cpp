#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=262144;
const int K=17;
int a[N],b[N],c[N],d[N],tmp[N],tmp2[N],res[N];
const int mo=998244353;
int fac[N],inv[N];
const int P=998244353,G=3;
int g[18],ng[28];
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
void NTT(int *a,int n,int t){
  for(int i=1,j=0;i<n-1;i++){
    for(int s=n;j^=s>>=1,~j&s;);
    if(i<j){
      int k=a[i];
      a[i]=a[j];a[j]=k;
    }
  }
  for(int d=0;(1<<d)<n;d++){
    int m=1<<d,m2=m<<1,_w=t==1?g[d]:ng[d];
    for(int i=0;i<n;i+=m2)for(int w=1,j=0;j<m;j++){
      int &A=a[i+j+m],&B=a[i+j],t=(ll)w*A%P;
      A=B-t;
      if(A<0)A+=P;
      B=B+t;
      if(B>=P)B-=P;
      w=(ll)w*_w%P;
    }
  }
  if(t==-1)for(int i=0,j=inv[n];i<n;i++)a[i]=(ll)a[i]*j%P;
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
void getinv(int *a,int *b,int n){
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
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      (c[i+j]+=1ll*tmp[i]*b[j]%mo)%=mo;
    }
  }
  for(int i=0;i<k;i++){
    c[i]=(2+mo-c[i])%mo;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      (d[i+j]+=1ll*c[i]*b[j]%mo)%=mo;
    }
  }
  for(int i=n;i<k;i++)b[i]=0;
  for(int i=0;i<k;i++)b[i]=d[i];
}
void getroot(int *a,int *b,int n){
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
  for(int i=n;i<k;i++){
    tmp[i]=b[i]=0;
  }
  NTT(tmp,k,1);
  NTT(tmp2,k,1);
  NTT(b,k,1);
  for(int i=0;i<k;i++){
    b[i]=((ll)b[i]*b[i]+tmp[i])%mo*inv[2]%mo*tmp2[i]%mo;
  }
  NTT(b,k,-1);
  for(int i=1;i<n;i++){
    cout<<b[i]<<' ';
  }
  cout<<endl;

  for(int i=n;i<k;i++)b[i]=0;
  
}
int main(){
  init();
  int i;
  for(g[K]=qpow(G,(P-1)/N),ng[K]=qpow(g[K],mo-2),i=K-1;~i;i--)
    g[i]=(ll)g[i+1]*g[i+1]%P,ng[i]=(ll)ng[i+1]*ng[i+1]%P;
  int n=10;
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
  for(int i=0;i<n;i++){
    cout<<1ll*ans[i]*fac[i]%mo<<" ";
  }
  cout<<endl;
  int m=1;
  while(m<n)m<<=1;
  getroot(ans,rans,m);
  for(int i=0;i<n;i++){
    cout<<1ll*rans[i]*fac[i]%mo<<" ";
  }
  /*
  while(1){
    int n;
    scanf("%d",&n);
    if(n==0)break;
    printf("%d\n",rans[n]);
  }
  */
}
