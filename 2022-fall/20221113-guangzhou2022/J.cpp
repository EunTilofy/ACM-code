#include<bits/stdc++.h>
using namespace std;
#define P 998244353
#define M 20000005
int n,mm,m,i,q[M],inv[M],p[M],sum[M];
int calc(int x,int y) {
	return 1ll*p[x]*q[y]%P*q[x-y]%P;
}
int f(int n) {
	if(sum[n])return sum[n];
	int s=0;
	for(int i=0; i<=(n-4)/2; i++) {
		s=(1ll*s+1ll*f(n-4-i)*calc(3+2*i,i)%P)%P+1ll*f(n-m-2-i)*calc(m+1+2*i,i)%P;
		s%=P;
	}
	return sum[n]=s;
}
int main() {
	inv[0]=inv[1]=p[1]=p[0]=q[1]=q[0]=1;
	for(i=2; i<M; i++)p[i]=1ll*p[i-1]*i%P,inv[i]=(1ll*P-P/i)*inv[P%i]%P,q[i]=1ll*q[i-1]*inv[i]%P;
	scanf("%d%d",&n,&mm);
	sum[0]=sum[1]=1,m=(mm+1)/2,printf("%d\n",f(n));
	for(i=0;i<=n;i++)printf("%d %d\n",i,sum[i]);
	return 0;
}