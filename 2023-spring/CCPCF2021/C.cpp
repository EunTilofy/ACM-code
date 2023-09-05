#include<bits/stdc++.h>
using namespace std;
#define P 998244353
#define M 200005
int n,t[M],i,ans,f[M],inv[M],finv[M];
int calc(int x,int y) {
	return 1ll*f[x]*finv[x-y]%P*finv[y]%P;
}
int main() {
	scanf("%d",&n),f[1]=inv[1]=f[0]=inv[0]=finv[1]=finv[0]=1;
	for(i=2; i<M; i++)f[i]=1ll*f[i-1]*i%P,inv[i]=(1ll*P-P/i)*inv[P%i]%P,finv[i]=1ll*finv[i-1]*inv[i]%P;
	ans=1;
	for(i=1; i<n; i++) {
		scanf("%d",&t[i]);
		if(i>1)ans=1ll*ans*calc(t[i]+1,t[i-1])%P;
	}
	printf("%d\n",ans);
	return 0;
}