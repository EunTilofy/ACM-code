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
#define M 1000005
int n,a[105],i,j,s[M],si,dp[M],mx,b[M],l,r;
long long ans;
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	dp[0]=1;
	for(i=1; i<=n; i++)
		for(j=M-1; j>=0; j--)if(dp[j])dp[a[i]+j]=1,mx=max(mx,a[i]+j);
	ans=mx*2+1;
	for(i=1; i<M; i++)if(dp[i])ans+=mx-i,s[++si]=i;
	for(i=1; i<M; i++)if(dp[i])ans+=mx-i-(upper_bound(s+1,s+si+1,mx-i)-s-1);
	printf("%lld\n",ans);
	return 0;
}