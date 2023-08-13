#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
const int mo=1e9+7;
int sz[N],c[N][2],a[N],st[N];
int fa[N];
int fac[N],inv[N];
int qpow(int a,int b){
  int res=1;
  for(;b;b>>=1,a=1ll*a*a%mo){
    if(b&1)res=1ll*res*a%mo;
  }
  return res;
}
void init(){
  fac[0]=1;
  for(int i=1;i<N;i++){
    fac[i]=1ll*fac[i-1]*i%mo;
  }
  for(int i=0;i<N;i++){
    inv[i]=qpow(fac[i],mo-2);
  }
}
int C(int n,int m){
  return 1ll*fac[n]*inv[n-m]%mo*inv[m]%mo;
}
int solve(int x){
  if(!x)return 1;
  sz[x]=1;
  int res=1ll*solve(c[x][0])*solve(c[x][1])%mo;
  sz[x]+=sz[c[x][0]];
  sz[x]+=sz[c[x][1]];
  res=1ll*res*C(sz[x]-1,sz[c[x][0]])%mo;
 // cout<<"C "<<sz[x]-1<<" "<<sz[c[x][0]]<<endl;
 // cout<<x<<" "<<sz[x]<<" "<<res<<endl;
  return res;
}
int tp;
int main(){
  int T;
  scanf("%d",&T);
  init();
  while(T--){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)st[i]=fa[i]=c[i][0]=c[i][1]=0;
    tp=0;
    for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
      st[tp+1]=0;
      while(tp&&(a[st[tp]]<a[i]))--tp;
      c[c[st[tp]][1]=i][0]=st[tp+1];
      st[++tp]=i;
    }
    for(int i=1;i<=n;i++){
      fa[c[i][0]]=i;
      fa[c[i][1]]=i;
    }
    int rt=0;
    for(int i=1;i<=n;i++){
      if(!fa[i])rt=i;
    }
    int ans=solve(rt);
    ans=1ll*ans*inv[n]%mo;
    ans=1ll*ans*n%mo*qpow(2,mo-2)%mo;
    printf("%d\n",ans);
  }
}
