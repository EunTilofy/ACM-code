#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N][N], A[N], b[N][N];
int q[N][N];
int cal(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
       //     cout<<a[i][j]<<" ";
            q[i][j]=0;
        }
    //    cout<<endl;
    }
    for(int j = 1; j <= n; ++j) {
        for(int i = 1; i <= n; ++i) A[i] = a[i][j];
        for(int i = n; i >= 1; --i) if(A[i]) {
            if(q[i][i]) {
                for(int k = i; k >= 1; --k) A[k] ^= q[i][k];
            }
            else {
                for(int k = i; k >= 1; --k) q[i][k] = A[k];
                break;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) cnt += q[i][i];
  //  cout<<cnt<<endl;
    return cnt;
}
const int mo=998244353;
int qpow(int a,int b){
    int res=1;
    for(;b;b>>=1,a=1ll*a*a%mo){
        if(b&1)res=1ll*res*a%mo;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    int ans=1;
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++)
            if(b[i][j])a[i][i]^=1;

        int rnk=cal(n);
    //    cout<<j<<" "<<rnk<<endl;
        ans=1ll*ans*qpow(2,(n-rnk))%mo;
        
        for(int i=1;i<=n;i++)
            if(b[i][j])a[i][i]^=1;
    }
    cout<<ans<<endl;
}