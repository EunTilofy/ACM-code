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
inline int mul(int x,ll y,int m=mod) {
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
#define M 40005
#define P 78294349
int mi[M],pr[M],tot,T,r,c,e,i,j,h,ans,num,now,cc,a[205][205],b[205][205],cnt[M],l,x;
bool mk[M],vis[M];
char s[205][205];
pair<int,int>pos[M],pos2[M];
void init() {
	for(int i = 2; i < M; ++i) {
		if(!mk[i]) {
			pr[++tot] = i;
			mi[i] = i;
		}
		for(int j = 1; j <= tot && 1ll * pr[j] * i < M; ++j) {
			mk[pr[j] * i] = 1;
			mi[pr[j] * i] = pr[j];
			if(i % pr[j] == 0) break;
		}
	}
}
void cp() {
	for(i=1; i<=r; i++)
		for(j=1; j<=c; j++)a[i][j]=b[i][j];
}
void left() {
	cp();
	int j,h;
	for(i=1; i<=r; i++) {
		for(h=j=1; j<=c&&h<=c; j++) {
			while(h<=c&&!a[i][h])h++;
			if(h>c)break;
			b[i][j]=a[i][h],h++;
		}
		for(; j<=c; j++)b[i][j]=0;
	}
}
void right() {
	int j,h;
	cp();
	for(i=1; i<=r; i++) {
		for(j=h=c; j>0&&h>0; j--) {
			while(h>0&&!a[i][h])h--;
			if(!h)break;
			b[i][j]=a[i][h],h--;
		}
		for(; j>0; j--)b[i][j]=0;
	}
}
void down() {
	int j,h;
	cp();
	for(i=1; i<=c; i++) {
		for(j=h=r; j>0&&h>0; j--) {
			while(h>0&&!a[h][i])h--;
			if(!h)break;
			b[j][i]=a[h][i],h--;
		}
		for(; j>0; j--)b[j][i]=0;
	}
}
void up() {
	int j=h=1;
	cp();
	for(i=1; i<=c; i++) {
		for(h=j=1; j<=r&&h<=r; j++) {
			while(h<=r&&!a[h][i])h++;
			if(h>r)break;
			b[j][i]=a[h][i],h++;
		}
//		printf("!!%d %d\n",j,i);
		for(; j<=r; j++)b[j][i]=0;
//		for(j=1;j<=r;j++)printf("%d ",b[j][i]);
//		puts("");
	}
}
void Print() {
	for(i=1; i<=r; i++,puts(""))
		for(j=1; j<=c; j++)printf("%d ",b[i][j]);
	puts("");
}
void solve() {
//	Print();
	for(i=1; i<=r; i++)
		for(j=1; j<=c; j++)pos[b[i][j]]=mkp(i,j);
	up();
//	Print();
	right();
//	Print();
	down();
//	Print();
	left();
//	Print();
	for(i=1; i<=num; i++) {
		if(vis[i])continue;
		now=b[pos[i].fi][pos[i].se],cc=1;
//		printf("!!!%d\n",i);
		while(now!=i) {
//			printf("%d ",now);
			cc++,vis[now]=1,now=b[pos[now].fi][pos[now].se];
		}
//		printf("!!%d\n",cc);
		while(cc>1) {
			l=0,x=mi[cc];
			while(cc%x==0)cc/=x,l++;
			cnt[x]=max(cnt[x],l);
		}
	}
	for(i=2; i<M; i++)if(cnt[i])ans=1ll*ans*mul(i,cnt[i],P)%P,cnt[i]=0;
}
int main() {
	scanf("%d",&T),init();
	for(e=1; e<=T; e++) {
		scanf("%d%d",&r,&c),num=0;
		for(i=1; i<=r; i++) {
			scanf("%s",s[i]+1);
			for(j=1; j<=c; j++)
				if(s[i][j]=='#')b[i][j]=++num,vis[num]=0;
				else b[i][j]=0;
		}
//		for(i=1; i<=r; i++,puts(""))
//			for(j=1; j<=c; j++)printf("%d ",b[i][j]);
//		up();
//		right(),down(),left();
//		for(i=1; i<=r; i++,puts(""))
//			for(j=1; j<=c; j++)printf("%d ",b[i][j]);
		ans=1,right(),left();
		printf("Case %d: ",e),solve(),printf("%d\n",ans);
	}
	return 0;
}
/*
1
4 4
#...
###.
####
####
*/