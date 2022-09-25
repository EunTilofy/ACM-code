#include<bits/stdc++.h>
using namespace std;
#define M 105
int n,i,j,a[M],b[M];
long long dp[M][M][M],sum[M][M],ans;
void solve(int k) {
	int i,j,h;
	memset(dp,-1,sizeof(dp)),ans=0;
	dp[1][0][0]=sum[1][1],dp[1][0][1]=0;
	for(i=2; i<n; i++)
		for(j=0; j<=k; j++)
			for(h=0; h-1+j<=k; h++)
				if(dp[i-1][j][h]!=-1) {
					if(h>1) {
						dp[i][j+h-1][0]=max(dp[i][j+h-1][0],dp[i-1][j][h]+sum[i-1][h]+sum[i][1]);
						dp[i][j+h-1][1]=max(dp[i][j+h-1][1],dp[i-1][j][h]+sum[i-1][h]);
					} else if(!h)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j][0]+sum[i][1]);
					if(h-1+j<k)dp[i][j][h+1]=max(dp[i][j][h+1],dp[i-1][j][h]);
				}
	for(i=0; i<=k; i++)
		for(j=0; j-1+i<=k; j++)
			if(dp[n-1][i][j]!=-1)ans=max(dp[n-1][i][j]+sum[n-1][j],ans);
}
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	for(i=1; i<n; i++)b[i]=a[i+1]-a[i];
	for(i=1; i<n; i++) {
		for(j=1; j<=i; j++)sum[i][j]=sum[i][j-1]+b[i-j+1];
		for(j=1; j<=i; j++)sum[i][j]=sum[i][j]*sum[i][j];//,printf("%d %d %lld\n",i,j,sum[i][j]);
	}
	for(i=1; i<=(n-2)/2; i++)solve(i*2),printf("%lld\n",ans);
	for(; i<=n; i++)printf("%lld\n",1ll*(1ll*a[n]-a[1])*(a[n]-a[1]));
	return 0;
}