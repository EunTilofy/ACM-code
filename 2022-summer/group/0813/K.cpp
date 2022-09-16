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
#define M 205
struct node {
	int x,y;
} ans[M*M];
int T,n,i,j,k,a[M],b[M],si,id,id1,id2,id3,cnt,l,lim,fl;
bool mark[M][M];
int f;
void dfs(int x,int y) {
	if(f)return;
	if(x==y) {
		int i;
		for(i=1; i<=lim; i++)if(a[i]!=b[i])return;
		f=1;
		return;
	}
	for(int i=1; i<=lim; i++)
		for(int j=i+1; j<=lim; j++)
			if(!mark[i][j]) {
				mark[i][j]=1,ans[++si]=(node) {
					i,j
				},swap(a[i],a[j]);
				dfs(x+1,y);
				if(f)return;
				mark[i][j]=0,si--,swap(a[i],a[j]);
			}
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n),f=fl=0;
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)mark[i][j]=0;
		for(i=1; i<=n; i++)scanf("%d",&a[i]);
		for(i=1; i<=n; i++)scanf("%d",&b[i]);
		si=cnt=0;
		for(i=n; i>1; i--) {
			l=si;
			if(a[i]!=b[i]) {
				for(j=1; j<i; j++)
					if(a[j]==b[i])id=j;
					else if(!mark[i][j])ans[++si]=(node) {
						j,i
					};
				if(mark[id][i]) {
					fl=1;
					break;
				}
				ans[++si]=(node) {
					id,i
				};
			} else {
//				for(j=1; j<=n; j++)printf("%d ",a[j]);
//				puts("");
				if(i<=3) {
					lim=i;
					for(j=1; j<=i; j++)
						for(k=j+1; k<=i; k++)
							if(!mark[j][k])cnt++;
//					printf("%d %d\n",i,cnt);
					dfs(0,cnt);
					if(!f)fl=1;
					break;
				}
				id1=id2=id3=0;
				for(j=1; j<i; j++)if(a[j]==b[i-1]&&!mark[j][i])id3=j;
				for(j=1; j<i; j++)if(a[j]==b[2]&&j!=id3&&!mark[j][i])id2=j;
				for(j=1; j<i; j++)if(a[j]==b[1]&&j!=id3&&j!=id2&&!mark[j][i]&&!mark[j][id3])id1=j;
//				printf("!%d %d %d\n",id1,id2,id3);
				if(!id1||!id2||!id3) {
					fl=1;
					break;
				}
				ans[++si]=(node) {
					id3,i
				};
				for(j=1; j<i; j++)
					if(j!=id1&&j!=id2&&j!=id3&&!mark[i][j])
						ans[++si]=(node) {
						j,i
					};
				ans[++si]=(node) {
					id2,i
				};
				ans[++si]=(node) {id3,id1},mark[id3][id1]=mark[id1][id3]=1;
				ans[++si]=(node) {
					id1,i
				};
//				for(j=l+1; j<=si; j++)printf("!!%d %d\n",ans[j].x,ans[j].y);
			}
			for(j=l+1; j<=si; j++) {
				swap(a[ans[j].x],a[ans[j].y]);
//				for(k=1;k<=n;k++)printf("%d ",a[k]);
//				puts("");
			}
		}
		for(i=1; i<=n; i++)if(a[i]!=b[i])break;
		if(i<=n)fl=1;
		if(fl)printf("NO\n");
		else {
			printf("YES\n");
			for(i=1; i<=si; i++)printf("%d %d\n",ans[i].x,ans[i].y);
		}
	}
	return 0;
}