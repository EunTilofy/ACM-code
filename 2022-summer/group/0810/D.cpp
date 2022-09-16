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
int T,i,j,r[2][10],s[2][10],rk[10],si[10],fl,cnt[15];
bool mark[10];
char a[2];
struct node {
	int r,s;
	bool operator<(const node&_)const {
		return _.r<r;
	}
} k[10];
struct Node {
	int a,b[6];
};
int suits(char c) {
	if(c=='S')return 0;
	if(c=='H')return 1;
	if(c=='C')return 2;
	return 3;
}
int ranks(char c) {
	if('2'<=c&&c<='9')return c-'0';
	if(c=='T')return 10;
	if(c=='J')return 11;
	if(c=='Q')return 12;
	if(c=='K')return 13;
	return 14;
}
Node calc(int f) {
	int i,ans[6];
	memset(ans,0,sizeof(ans));
	for(i=1; i<=5; i++)k[i]=(node) {
		r[f][i],s[f][i]
	};
	sort(k+1,k+6);
	int f1=0;//next
	for(i=1; i<5; i++)if(k[i+1].r!=k[i].r-1)break;
	if(i==5)f1=1;
	if(f1&&k[1].r==14)return (Node) {
		10,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
	};
	if(k[1].r==14&&k[2].r==5) {
		for(i=2; i<5; i++)if(k[i+1].r!=k[i].r-1)break;
		if(i==5)f1=1;
	}
	int f2=0;//same suit
	for(i=1; i<5; i++)if(k[i+1].s!=k[i].s)break;
	if(i==5)f2=1;
	if(f2&&f1) {
		ans[1]=(k[1].r==14&&k[2].r==5)?1:k[5].r;
		return (Node) {
			9,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
		};
	}
	memset(cnt,0,sizeof(cnt));
	for(i=1; i<=5; i++)cnt[k[i].r]++;
	int f22=0,f33=0,id,id1=-1,id2;//cnt
	for(i=2; i<=14; i++)
		if(cnt[i]==4) {
			ans[1]=k[2].r;
			for(int j=1;j<=5;j++)if(k[j].r!=i)ans[2]=k[j].r;
			return (Node) {
				8,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
			};
		} else if(cnt[i]==2) {
			f22++;
			if(id1==-1)id1=i;
			else id2=i;
		} else if(cnt[i]==3)f33++,id=i;
	if(f22&&f33) {
		ans[1]=id,ans[2]=id1;
		return (Node) {
			7,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
		};
	}
	if(f2) {
		for(i=1; i<=5; i++)ans[i]=k[i].r;
		return (Node) {
			6,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
		};
	}
	if(f1) {
		ans[1]=(k[1].r==14&&k[2].r==5)?1:k[5].r;
		return (Node) {
			5,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
		};
	}
	if(f33) {
		ans[1]=id;
		int j=2;
		for(i=1; i<=5; i++)
			if(k[i].r!=id) {
				ans[j]=k[i].r;
				j++;
			}
		return (Node) {
			4,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
		};
	}
	if(f22==2) {
		ans[1]=id2,ans[2]=id1;
		for(i=1;i<=5;i++)if(k[i].r!=id1&&k[i].r!=id2)ans[3]=k[i].r;
		return (Node) {
			3,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
		};
	}
	if(f22) {
		ans[1]=id1;
		int j=2;
		for(i=1; i<=5; i++)
			if(k[i].r!=id1) {
				ans[j]=k[i].r;
				j++;
			}
		return (Node) {
			2,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
		};
	}
	for(i=1; i<=5; i++)ans[i]=k[i].r;
	return (Node) {
		1,ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]
	};
}
int chk() {
	Node a=calc(0),b=calc(1);
	int i;
//	printf("!!!\n");
//	for(i=1; i<=5; i++)printf("!%d %d ",s[0][i],r[0][i]);
//	puts("");
//	for(i=1; i<=5; i++)printf("%d ",a.b[i]);
//	puts("");
	if(a.a>b.a)return 1;
	if(a.a<b.a)return -1;
	for(i=1; i<=5; i++)
		if(a.b[i]>b.b[i])return 1;
		else if(a.b[i]<b.b[i])return -1;
	return 0;
}
int dp[1<<6][1<<6],noww;
int dfs(int x,int y) {
	if(x==6) {
		return chk();
	}
	int now=0;
	for(int i=1; i<=6; i++)if(!mark[i])now|=1<<i-1;
	if(dp[noww][now]!=2)return dp[noww][now];
	int f1=0,f2=0,fl,fx,fy;
	if(x==y)fx=1,fy=0;//y
	else fx=0,fy=1;//x
	for(int i=1; i<=6; i++)
		if(!mark[i]) {
			if(x>y)noww|=1<<i-1;
			mark[i]=1,r[fx][x]=rk[i],s[fx][x]=si[i],fl=dfs(x+fx,y+fy),mark[i]=0;
			if(fl==-1)f1=1;
			if(!fl)f2=1;
			if(x>y)noww-=1<<i-1;
		}
//	int ans=0;
//	if(f1)ans=1;
//	else if(f2)ans=0;
//	else ans=-1;
//	if(noww==9&&now==48) {
//		printf("!!%d %d %d\n",noww,now,ans);
//	if(dp[noww][now]!=2&&ans!=dp[noww][now])printf("!!!!!!!%d %d\n",ans,dp[noww][now]);
//	}
	if(f1)return dp[noww][now]=1;
	if(f2)return dp[noww][now]=0;
	return dp[noww][now]=-1;
}
int main() {
	scanf("%d",&T);
	while(T--) {
//		for(i=1; i<=5; i++)scanf("%s",a),r[0][i]=ranks(a[0]),s[0][i]=suits(a[1]);
//		Node q=calc(0);
//		printf("%d\n",q.a);
//		for(i=1;i<=5;i++)printf("%d ",q.b[i]);
		for(j=0; j<(1<<6); j++)
			for(i=0; i<(1<<6); i++)dp[j][i]=2;
		scanf("%s",a);
		r[0][1]=ranks(a[0]),s[0][1]=suits(a[1]);
		scanf("%s",a);
		r[0][2]=ranks(a[0]),s[0][2]=suits(a[1]);
		scanf("%s",a);
		r[1][1]=ranks(a[0]),s[1][1]=suits(a[1]);
		scanf("%s",a);
		r[1][2]=ranks(a[0]),s[1][2]=suits(a[1]);
		for(i=1; i<=6; i++)scanf("%s",a),rk[i]=ranks(a[0]),si[i]=suits(a[1]);
//		for(i=1;i<=6;i++)printf("%d %d\n",rk[i],si[i]);
		fl=dfs(3,2);
		if(fl==1)printf("Alice\n");
		if(fl==-1)printf("Bob\n");
		if(fl==0)printf("Draw\n");
	}
	return 0;
}