#include<bits/stdc++.h>
using namespace std;
int qpow(int a,int b,int mo){
    int res=1;
    for(;b;b>>=1,a=1ll*a*a%mo){
        if(b&1)res=1ll*res*a%mo;
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        if(qpow(i,(n-1)/2,n)==1){
            cout<<"0 ";
        }
        else cout<<"1 ";
    }
}