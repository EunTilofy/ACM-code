#include<bits/stdc++.h>
using namespace std;
int T,s,c,i;
long long dp[180005];
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&s,&c);
		for(i=1; i<=c; i++)dp[i]=max(dp[i-1]+i,1ll*c*i);
		for(i=c+1; i<=s; i++)dp[i]=max(dp[i-1]+i,dp[i-c-1]+1ll*c*i);
		printf("%lld\n",dp[s]);
	}
	return 0;
}