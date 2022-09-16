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
#define M 43000
int n,m,i,j,h,o,num[M],si,now,cnt[M],id,dig[M];
struct node {
	int x,y;
} w[205];
long long dp[M],ans;
int main() {
	scanf("%d%d",&n,&m),num[si=1]=0,dig[1]=0,ans=1;
	for(i=1; i<=m; i++)scanf("%d%d",&w[i].x,&w[i].y);
	for(i=1; i<(1<<n); i++) {
		now=i;
		while(now)cnt[i]+=(now&1),now>>=1;
	}
	for(j=1; j<=n; j++) {
		ans=ans*j;
		for(i=1; i<(1<<n); i++) {
			if(cnt[i]==j)num[++si]=i,dig[si]=j;
		}
	}
	dp[0]=1;
	for(o=1; o<=si; o++) {
		i=num[o];
		for(j=1; j<=n; j++)
			if(((1<<j-1)&i)==0) {
				now=i,id=j;
				for(h=1; h<=m; h++)
					if(w[h].x!=w[h].y) {
						if(((1<<w[h].x-1)&now)==0&&(((1<<w[h].y-1)&now)||w[h].y==id)) {
							if(id!=w[h].y)now+=(1<<w[h].x-1),now-=(1<<w[h].y-1);
							if(id==w[h].x)id=w[h].y;
							else if(id==w[h].y)id=w[h].x;
						}
					}
				if(id==dig[o]+1)dp[(1<<j-1)|i]+=dp[i];
			}
	}
	printf("%lld\n",ans-dp[(1<<n)-1]);
	return 0;
}