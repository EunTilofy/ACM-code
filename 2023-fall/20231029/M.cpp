#include<bits/stdc++.h>
using namespace std;
const int N=200001;
const int mo=998244353;
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
    for(int i=1;i<N;i++)fac[i]=1ll*fac[i-1]*i%mo;
    for(int i=0;i<N;i++)inv[i]=qpow(fac[i],mo-2);
}
int binom(int n,int m){
  if(n<m)return 0;
    return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;
}
int f(int n,int m,int k){
    int ans=0;
    for(int i=0;i*k<=n;i++){
        (ans+=1ll*(!(i&1)?mo-1:1)*binom(n-i*k,n-m)%mo*binom(n-m+1,i)%mo)%=mo;
    }
    return ans;
}
int main(){
    int n,m,k;
    init();
    scanf("%d%d%d",&n,&m,&k);
    if(m==0||k==0){
        if(m==0&&k==0){
            puts("1");
        }
        else{
            puts("0");
        }
    }
    else{
        int res=(f(n,m,k)+mo-f(n,m,k+1))%mo;
        printf("%d\n",res);
    }
    
}
