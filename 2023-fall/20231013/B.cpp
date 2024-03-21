#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
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
    return 1ll*fac[n]*inv[m]%mo*inv[n-m]%mo;
}
int solve(int n,int m){
    int res2=0;
   // if(n<m)swap(n,m);
    for(int i=0;i<=m;i++){
        (res2+=1ll*(!(i&1)?1:mo-1)*binom(m,i)%mo*qpow(m-i,n)%mo)%=mo;
        //cout<<((i&1)?1:mo-1)<<" "<<binom(m,i)<<" "<<qpow(m-i,n)<<" "<<1ll*(!i&1?1:mo-1)*binom(m,i)%mo*qpow(m-i,n)%mo<<endl;
    }
    //cout<<n<<"    "<<m<<" "<<res2<<endl;
    return res2;

}
int main(){
    init();
    int n,m,T;
    scanf("%d%d%d",&n,&m,&T);
    int res1=1ll*qpow(n,m-1)*qpow(m,n-1)%mo;
    int res2=0;
    if(n==m){
        res2=1ll*solve(n-1,m-1)*n%mo*m%mo;
    }
    else {
        if(n<m)swap(n,m);
        res2=(1ll*solve(n-1,m-1)%mo*n%mo*m%mo+1ll*solve(n-1,m)*n%mo)%mo;
    }


    while(T--){
        int x;
        scanf("%d",&x);
        if(x==0){
            printf("%d\n",res1);
        }
        else if(x==1){
            printf("%d\n",res2);
        }
        else puts("1");
    }
}