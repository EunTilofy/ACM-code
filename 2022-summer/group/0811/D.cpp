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
#define M 300005
#define P 1000000007
int n,i,si,l[M],r[M],dp[M],len,mark[M],f;
char a[M],b[M];
int main() {
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1),si++,l[1]=1,mark[1]=(a[1]!=b[1]);
	for(i=2; i<=n; i++)
		if(a[i]!=b[i]&&a[i]!=a[i-1]&&a[i-1]!=b[i-1]);
		else r[si]=i-1,si++,l[si]=i,mark[si]=(a[i]!=b[i]);
	r[si]=n,dp[0]=1;
	for(i=1; i<=si; i++) {
		if(!mark[i]) {
			dp[i]=dp[i-1];
			continue;
		}
		len=r[i]-l[i]+1;
		if(len&1) {
			dp[i]=1ll*dp[i-1]*((len+1)/2)%P;
			if(i>2&&mark[i-2]&&(r[i-2]-l[i-2]+1)&1&&r[i-2]+2==l[i]&&a[r[i-2]]!=a[l[i]])dp[i]=(1ll*dp[i]+2ll*dp[i-3]%P)%P;
		} else dp[i]=dp[i-1];
//		printf("%d %d %d\n",l[i],r[i],dp[i]);
	}
	printf("%d\n",dp[si]);
	return 0;
}
/*
9
110101001
011010110
*/