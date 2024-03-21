#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
__int128 f[1<<20],g[1<<20];
__int128 inv2;
const __int128 mo=75161927681;

void fwt_xor(__int128 a[],int n){
    for(int k=1;k<(1<<n);k<<=1){
        for(int i=0;i<(1<<n);i+=(k<<1)){
            for(int j=0;j<k;j++){
                __int128 x=a[i+j],y=a[i+j+k];
                a[i+j]=(x+y)%mo;
                a[i+j+k]=(x-y+mo)%mo;
            }
        }
        
    }
}
void ifwt_xor(__int128 a[],int n){
    for(int k=1;k<(1<<n);k<<=1){
        for(int i=0;i<(1<<n);i+=(k<<1)){
            for(int j=0;j<k;j++){
                __int128 x=a[i+j],y=a[i+j+k];
                a[i+j]=(x+y)*inv2%mo;
                a[i+j+k]=(x-y+mo)*inv2%mo;
            }
        }
    }
}
void fwt_and(__int128 a[],int n){
    for(int k=1;k<(1<<n);k<<=1){
        for(int i=0;i<(1<<n);i+=(k<<1)){
            for(int j=0;j<k;j++){
                (a[i+j]+=a[i+j+k])%=mo;
            }
        }
    }
}

void print(__int128 x) {
    if(x<10) cout << (int)x;
    else print(x/10), cout << (int)(x%10);
}
signed main(){
    inv2=(mo+1)/2;
    int n,m,k;
    char s[30];
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        int c=0;
        for(int i=0;i<m;i++){
            if(s[i]=='A')c|=(1<<i);
        }
        f[c]++;
    }    
  //  for(int i=0;i<(1<<m);i++)cout<<f[i]<<" ";
 //   cout<<endl;
    fwt_xor(f,m);
 //   for(int i=0;i<(1<<m);i++)cout<<f[i]<<" ";
 //   cout<<endl;
    for(int i=0;i<(1<<m);i++)f[i]=f[i]*f[i]%mo;
  //  for(int i=0;i<(1<<m);i++)cout<<f[i]<<" ";
  //  cout<<endl;
    ifwt_xor(f,m);
    for(int i=0;i<(1<<m);i++)g[i]=f[((1<<m)-1)^i]%mo;
   // for(int i=0;i<(1<<m);i++)cout<<g[i]<<" ";
   // cout<<endl;
    fwt_and(g,m);
//    for(int i=0;i<(1<<m);i++) print(g[i]), cout <<" ";
//    cout<<endl;
    int ans=0;
    for(int i=1;i<(1<<m);i++){
        if((g[0]-g[i]+mo)%mo>=k*2)ans++;
    }
    printf("%lld\n",ans);
}