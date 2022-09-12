#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
#define M 4005
int n,a[M][M],i,j,dp[M][M],mi[M][M];
int cnt1,cnt2;
bool mark[M][M];
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void fz(int l,int r) {
//	if(l>r)return;
	if(l+1==r) {
		dp[l][r]=a[l][r],mark[l][r]=1;
		return;
	}
//	if(mark[l][r])return;
	dp[l][r]=1e9,mark[l][r]=1;
	for(int i=l; i<r; i++)
		if(!((i-l)&1)&&mi[l][i-1]<dp[l][r]&&mi[i+1][r-1]<dp[l][r]&&a[i][r]<dp[l][r]){
//			cnt1++;
			if(l<=i-1&&!mark[l][i-1])fz(l,i-1);
			if(i+2<=r&&!mark[i+1][r-1])fz(i+1,r-1);
			dp[l][r]=min(dp[l][r],max(dp[l][i-1],max(dp[i+1][r-1],a[i][r])));
		}
//		else cnt2++;
//	printf("%d %d %d\n",l,r,dp[l][r]);
}
int main() {
	n=read();
	for(i=1; i<=n; i++)
		for(j=i+1; j<=n; j+=2)a[i][j]=read(),a[j][i]=a[i][j];
//	n=2000;
//	int m=0;
//	for(i=1; i<=n; i++)
//		for(j=i+1; j<=n; j+=2)a[i][j]=++m,a[j][i]=a[i][j];
//	printf("%d ",m);
	for(i=1; i<n; i++)
		for(mi[i][i+1]=a[i][i+1],j=i+3; j<=n; j+=2)mi[i][j]=min(mi[i][j-2],a[i][j]);
	fz(1,n);
//	printf("%d %d\n",cnt1,cnt2);
	printf("%d\n",dp[1][n]);
	return 0;
}