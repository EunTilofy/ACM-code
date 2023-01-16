#include<bits/stdc++.h>
using namespace std;
#define M 10005
int i,a[M],n,j,dp[2][M][3];
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	memset(dp,-0x3f,sizeof(dp));
	for(i=0; i<=n; i++)dp[0][i][2]=0;
	for(i=1; i<=n; i++) {
//		dp[i-1][i-1][2]=0;
//		dp[i&1][j-1][0]=dp[i&1][j-1][1]=dp[i&1][j-1][2]=-1e9;
		memset(dp[i&1],-0x3f,sizeof(dp[i&1]));
		for(j=i; j<=n; j++) {
			dp[i&1][j][2]=dp[i&1][j-1][1]-a[j];
			dp[i&1][j][2]=max(dp[i&1][j][2],dp[i&1][j-1][0]+a[j]);
			dp[i&1][j][2]=max(dp[i&1][j][2],dp[i&1][j-1][2]);
			dp[i&1][j][2]=max(dp[i&1][j][2],dp[i-1&1][j-1][2]);
			dp[i&1][j][1]=dp[i-1&1][j-1][2]+a[j];
			dp[i&1][j][1]=max(dp[i&1][j][1],dp[i&1][j-1][1]);
			dp[i&1][j][0]=dp[i-1&1][j-1][2]-a[j];
			dp[i&1][j][0]=max(dp[i&1][j][0],dp[i&1][j-1][0]);
//			printf("%d %d %d %d %d\n",i,j,dp[i][j][0],dp[i][j][1],dp[i][j][2]);
		}
		printf("%d\n",dp[i&1][n][2]);
	}
	return 0;
}