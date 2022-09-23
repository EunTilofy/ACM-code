#include<bits/stdc++.h>
using namespace std;
#define M 4000005
bool cur1;
int a[M],T,si,n,t,s[105],i,j,k,h,x1,x2,x3,x4,sz,f,c[2][5][M];
long long res,x[5],ans,dp[2][5][M];
int find(int v,int h) {
	if(h==1)v+=x1;
	if(h==2)v+=x2;
	if(h==3)v+=x3;
	if(h==4)v+=x4;
	if(v>T)return -1;
	return lower_bound(a+1,a+sz+1,v)-a;
}
bool cur2;
int main() {
//	printf("%.lf",((&cur2)-(&cur1))/1024.0/1024);
	scanf("%d%d",&n,&T);
	scanf("%d%d%d%d",&x1,&x2,&x3,&x4);
	for(i=1; i<=n; i++)scanf("%d",&s[i]);
	x[1]=1ll*x1;
	x[2]=1ll*x1+x2;
	x[3]=1ll*x1+x2+x3;
	x[4]=1ll*x1+x2+x3+x4;
	for(i=0; i<=50; i++)
		for(j=0; i+j<=50; j++)
			for(k=0; i+j+k<=50; k++)
				for(h=0; i+j+k+h<=50; h++) {
					res=x[1]*i+x[2]*j+x[3]*k+x[4]*h;
					if(res<=T&&i*2+3*j+4*k+5*h-1<=n)a[++si]=res;
					else break;
				}
	sort(a+1,a+si+1);
	for(i=2,sz=1; i<=si; i++)if(a[i]!=a[i-1])a[++sz]=a[i];
//	printf("%d\n",sz);
//	for(i=1; i<=sz; i++)printf("%d ",a[i]);
//	puts("");
//	printf("%d\n",find(0,4));
	for(i=0; i<=4; i++)
		for(j=1; j<=sz; j++)dp[0][i][j]=-1;
	dp[0][0][1]=0;
	for(i=1; i<=n; i++) {
		f=!f;
//		c[f][0][1]=i,dp[f][0][1]=0;
		for(j=1; j<=sz; j++)
			for(h=0; h<=4; h++) {
				if(c[!f][h][j]!=i-1)c[!f][h][j]=i-1,dp[!f][h][j]=-1;
				if(dp[!f][h][j]!=-1) {
					if(h<4) {
						k=find(a[j],h+1);
						if(k!=-1) {
							if(c[f][h+1][k]!=i)c[f][h+1][k]=i,dp[f][h+1][k]=-1;
							dp[f][h+1][k]=max(dp[f][h+1][k],dp[!f][h][j]+s[i]);
							ans=max(ans,dp[f][h+1][k]);
//							printf("%d %d %d %d %d %d\n",i,a[k],a[j],h,dp[f][h+1][k],dp[!f][h][j]);
						}
					}
					if(c[f][0][j]!=i)c[f][0][j]=i,dp[f][0][j]=-1;
					dp[f][0][j]=max(dp[f][0][j],dp[!f][h][j]);
//					printf("!%d %d %d %d %d\n",i,j,a[j],h,dp[f][0][j]);
				}
			}
	}
	printf("%lld",ans);
	return 0;
}