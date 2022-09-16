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
#define N 20000005
#define M 1000005
int n,m,a[M],b[M],i,j,id1[N],id2[N],A[M],sa,B[M],sb,Id1[M],Id2[M],idd1,v1,idd2,v2;
bool mark1[N],mark2[N],cnt[N];
int main() {
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(!mark1[a[i]])A[++sa]=a[i],Id1[sa]=i,mark1[a[i]]=1;
		else idd1=i,v1=a[i];
	}
	for(i=1; i<=m; i++) {
		scanf("%d",&b[i]);
		if(!mark2[b[i]])B[++sb]=b[i],Id2[sb]=i,mark2[b[i]]=1;
		else idd2=i,v2=b[i];
	}
	if(idd1&&idd2) {
		for(i=1; i<=n; i++)
			if(v1==a[i]) {
				printf("%d %d ",i,idd1);
				break;
			}
		for(i=1; i<=m; i++)
			if(v2==b[i]) {
				printf("%d %d\n",i,idd2);
				return 0;
			}
	}
//	printf("!");
	for(i=1; i<=sa; i++)
		for(j=1; j<=sb; j++) {
			if(cnt[A[i]+B[j]]) {
//				printf("!%d %d\n",i,j);
				printf("%d %d %d %d\n",id1[A[i]+B[j]],Id1[i],id2[A[i]+B[j]],Id2[j]);
				return 0;
			}else cnt[A[i]+B[j]]=1,id1[A[i]+B[j]]=Id1[i],id2[A[i]+B[j]]=Id2[j];//,printf("!!!%d %d %d\n",i,j,A[i]+B[j]);
		}
	printf("-1\n");
	return 0;
}