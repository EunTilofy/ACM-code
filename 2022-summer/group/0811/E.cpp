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
#define M 200005
int n,q,a[M],i,b[M],j,si,sum[M],x,k,id[30],res,r,ans,fl,mark[M],mk[M];
int main() {
	scanf("%d%d",&n,&q);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	for(i=1; i<=n; i++)scanf("%d",&b[i]),sum[i]=sum[i-1]+(!b[i]);
	for(j=29; j>=0; j--) {
		for(i=n; i>0; i--)
			if(a[i]&(1<<j)) {
				id[j]=i;
				break;
			}
		if(id[j]&&!b[id[j]]) {
			for(i=id[j]; i>0; i--)
				if(a[i]&(1<<j)) {
//					printf("%d %d %d %d\n",j,i,a[i],b[i]);
					if(b[i])mark[j]=1;
				} else if(!b[i])break;
			if(i==0)mk[j]=1;
//			printf("%d %d %d %d %d\n",j,id[j],mark[j],mk[j],i);
		}
	}
	for(i=1; i<=q; i++) {
		scanf("%d%d",&x,&k),r=n,ans=0;
		for(j=29; j>=0; j--) {
			if(id[j])res=id[j]-1;
			else if(x&(1<<j))res=0;
			else continue;
			if(r<=res) {
				ans|=1<<j;
				continue;
			}
			if(sum[r]-sum[res]-mark[j]-(mk[j]&&(x&1<<j))<=k)k-=sum[r]-sum[res]-mark[j]-(mk[j]&&(x&1<<j)),r=res+mark[j]+(mk[j]&&(x&1<<j)),ans|=1<<j;
		}
		printf("%d\n",ans);
	}
	return 0;
}