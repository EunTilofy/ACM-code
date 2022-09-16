#include<bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod) {
	int r=1;
	for(; y; y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;
	return r;
}
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
#define M 5005
int k,n,r,dp[M][M],g[M][M],l,i,j,h,a[M],q;
void add(int &x,int y) {
	x+=y;
	if(x>=mod)x-=mod;
}
int main() {
	scanf("%d%d%d",&n,&k,&r);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	dp[1][1]=g[1][1]=1;
	for(i=2; i<=n; i++) {
		while(l<=n&&a[l+1]+r<=a[i])l++;
		for(j=min(k,i); j>=i-l; j--) {
			
			
			
			q=j-(i-l)+1,dp[j][i]=dp[j-1][i-1];
			for(h=1; h<=l; h++)add(dp[j][i],g[j][h]),printf("!%d %d\n",h,g[j][h]),g[j][h]=1ll*g[j][h]*(q-1)%mod+g[j-1][h];
			for(h=l+1; h<i; h++)printf("!!%d %d\n",h,g[j][h]),g[j][h]=1ll*g[j][h]*q%mod+g[j-1][h];
			g[j][i]=dp[j][i];
			printf("!!!%d %d %d %d\n",q,i,j,dp[j][i]);
		}
		for(j=1; j<i-l; j++) {
			for(h=1; h<i; h++)g[j][h]=0;
		}
	}
	printf("%d\n",dp[k][n]);
	return 0;
}
/*
dp[i] [1,i]的方案数
f[i] [1,i]所有方案中以[1,i]为结尾的方案数

dp[k][i+1]=f[k][j]+dp[k-1][i]
f[k][i+1]=k*dp[k][i+1] (a[j]+r<=a[i+1])

dp[1][1]=f[1]=1
*/