#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
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
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
#define M 1005
#define N 1000005
int n,m,k,u,i,j,a[M][M],id[M][M],si,sum[M*M],h[N],r[N<<1],nx[N<<1],tot,mark[N],ti,mk[M][M];
void add(int x,int y){
	r[++tot]=y,nx[tot]=h[x],h[x]=tot;
}
struct node{
	int x,y,dis;
}Q[M*M];
vector<node>b[M*M];
int rx[]={1,1,0},ry[]={1,0,1};
bool chk(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void dfs(int x,int y){
	sum[si]+=a[x][y],id[x][y]=si;
	for(int i=0;i<3;i++){
		int xx=x+rx[i],yy=y+ry[i];
		if(chk(xx,yy))
		if(a[xx][yy]>0&&!id[xx][yy]){
			dfs(xx,yy);
		}else if(a[xx][yy]<=0)b[si].push_back((node){xx,yy,1});
	}
}
void bfs(int x){
	int l=1,r=0;
	ti++;
	for(int i=0;i<b[x].size();i++)Q[++r]=b[x][i],mk[Q[r].x][Q[r].y]=ti;
	while(l<=r){
		node s=Q[l];
		l++;
		for(int i=0;i<3;i++){
		int xx=s.x+rx[i],yy=s.y+ry[i];
		if(chk(xx,yy))
		if(a[xx][yy]>0&&mark[id[xx][yy]]!=ti)mark[id[xx][yy]]=ti,add(x,id[xx][yy]);
		else if(a[xx][yy]<=0&&mk[xx][yy]!=ti&&s.dis<k)mk[Q[r].x][Q[r].y]=ti,Q[++r]=(node){xx,yy,s.dis+1};
		}
	}
}
int d[N];
std::priority_queue<pii> q;
int S,T;
int dij() {
	for(int i = 1; i <= n; ++i) d[i] = -1;
	d[S] = sum[S];
	q.push(mkp(S, d[S]));
	while(!q.empty()) {
		pii o = q.top();
		q.pop();
		int x = o.fi, dis = o.se;
		if(dis < d[x]) continue;
		for(int i = h[x];i; i=nx[i]) {
			int y=r[i];
		if(d[y] < d[x] - u + sum[y]&&d[x] - u >=0) {
			d[y] = d[x] - u + sum[y];
			q.push(mkp(y, d[y]));
		}}
	}
	return d[T];
}
int main(){
	while(scanf("%d%d%d%d",&n,&m,&k,&u)!=EOF){
		si=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&a[i][j]),id[i][j]=0;
				for(i=1;i<=n;i++)
				for(j=1;j<=m;j++)
				if(a[i][j]>0&&!id[i][j])si++,dfs(i,j);
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)printf("%d %d %d %d\n",i,j,id[i][j],sum[id[i][j]]);
		for(i=1;i<=si;i++)bfs(i);
		S=id[1][1],T=id[n][m];
		printf("%d\n",dij());
	}
	return 0;
}