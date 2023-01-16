#include<bits/stdc++.h>
using namespace std;
#define M 200005
int n,i,j,a[M],u,v,h[M],nx[M<<1],r[M<<1],tot,dp[M][5],ans;
void add(int x,int y) {
	r[++tot]=y,nx[tot]=h[x],h[x]=tot;
}
void dfs(int x,int f) {
	for(int j=2; j<=4; j++)dp[x][j]=-1e9;
	int f1[4],f2[2],f3,f4;
	for(int i=1; i<4; i++)f1[i]=-1e9;
	for(int i=1; i<2; i++)f2[i]=-1e9;
	f1[0]=f2[0]=f3=f4=-1e9;
	for(int i=h[x]; i; i=nx[i])
		if(r[i]!=f) {
			dfs(r[i],x);
			for(int j=0; j<4; j++)
				if(dp[r[i]][1]>f1[j]) {
					for(int k=3; k>j; k--)f1[k]=f1[k-1];
					f1[j]=dp[r[i]][1];
					break;
				}
			for(int j=0; j<2; j++)
				if(dp[r[i]][2]>f2[j]) {
					for(int k=1; k>j; k--)f2[k]=f2[k-1];
					f2[j]=dp[r[i]][2];
					break;
				}
			f3=max(f3,dp[r[i]][3]);
			f4=max(f4,dp[r[i]][4]);
		}
	dp[x][1]=a[x];
	dp[x][1]=max(dp[x][1],f1[0]+a[x]);
//	if(f1[0]>-1e9)dp[x][2]=max(dp[x][2],f1[0]+a[x]);
	if(f1[1]>-1e9)dp[x][2]=max(dp[x][2],f1[0]+f1[1]+a[x]);
	dp[x][2]=max(dp[x][2],f2[0]);
	if(f1[2]>-1e9) {
		int sum=0;
		for(int i=0; i<3; i++)sum+=f1[i];
		ans=max(ans,sum);
	}
	dp[x][3]=max(dp[x][3],f1[0]+f2[0]+a[x]);
//	dp[x][3]=max(dp[x][3],f2[0]+a[x]);
	dp[x][3]=max(dp[x][3],f3);
	if(f1[3]>-1e9) {
		int sum=0;
		for(int i=0; i<4; i++)sum+=f1[i];
		ans=max(ans,sum);
	}
	if(f2[1]>-1e9)dp[x][4]=max(dp[x][4],f2[0]+f2[1]+a[x]);
	dp[x][4]=max(dp[x][4],f1[0]+f3+a[x]);
//	dp[x][4]=max(dp[x][4],f3+a[x]);
	dp[x][4]=max(dp[x][4],f4);
}
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	for(i=1; i<n; i++)scanf("%d%d",&u,&v),add(u,v),add(v,u);
	dfs(1,0);
	for(j=2; j<=4; j++)ans=max(ans,dp[1][j]);
	printf("%d\n",ans);
	return 0;
}