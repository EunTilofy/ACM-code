#include<bits/stdc++.h>
using namespace std;
#define M 1000005
int n,i,dp[M];
char s[3][M];
int chk1(int x,int f) {
	int ans=0;
	x+=f;
	ans=(s[0][x-2]!='.')+(s[1][x-2]!='#')+(s[2][x-2]!='.')+(s[0][x-1]!='#')+(s[1][x-1]!='#')+(s[2][x-1]!='#');
	if(!f)for(int i=0; i<3; i++)ans+=(s[i][x]!='.');
	return ans;
}
int chk0(int x,int f) {
	int ans=0;
	x+=f;
	ans=(s[0][x-3]!='#')+(s[1][x-3]!='#')+(s[2][x-3]!='#')+(s[0][x-2]!='#')+(s[1][x-2]!='.')+(s[2][x-2]!='#')+(s[0][x-1]!='#')+(s[1][x-1]!='#')+(s[2][x-1]!='#');
	if(!f)for(int i=0; i<3; i++)ans+=(s[i][x]!='.');
	return ans;
}
int main() {
	scanf("%d",&n);
	for(i=0; i<3; i++)scanf("%s",s[i]+1);
	for(i=1; i<=n; i++) {
		dp[i]=1e9;
		if(i>=3)dp[i]=min(dp[i],dp[i-3]+chk1(i,0));
		if(i>=4)dp[i]=min(dp[i],dp[i-4]+chk0(i,0));
//		printf("%d %d\n",i,dp[i]);
	}
	dp[n]=1e9;
	if(n>=3)dp[n]=min(dp[n-3]+chk0(n,1),dp[n]);
	if(n>=2)dp[n]=min(dp[n-2]+chk1(n,1),dp[n]);
	printf("%d\n",dp[n]);
	return 0;
}
/*
5
.#..#
##.##
.#..#

*/
