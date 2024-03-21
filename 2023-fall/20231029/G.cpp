#include<bits/stdc++.h>
using namespace std;
const int N=100001;
unordered_map<int,int>mp;
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
int main(){
    int n,m;
    int res=1,mx=0;
    init();
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        mp[x]++;
        res=1ll*res*inv[x]%mo;
        mx=max(x,mx);
    }
    for(int k=1;k<=m;k++){
        int ans=1ll*res*qpow(fac[k],n)%mo;
        if(k<mx){
            puts("0");
        }
        else{
            for(auto [u,v]:mp){
                ans=1ll*ans*qpow(inv[k-u],v)%mo;
            }
            printf("%d\n",ans);
        }
    }
}