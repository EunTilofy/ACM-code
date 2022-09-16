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
#define M 2000005
int z,x,y,i,j,h,l,r,dis[105][105][105],w[105][105][105],L,R,mid,res,si;
char s[105];
struct node {
	int x,y,z,dis;
	bool operator<(const node&_)const {
		return _.dis>dis;
	}
} a[M];
struct Node {
	int x,y,z;
} Q[M];
int rx[]= {0,1,0,-1,0,0,0},ry[]= {1,0,-1,0,0,0},rz[]= {0,0,0,0,1,-1};
bool chk(int xx,int yy,int zz) {
	return xx>=1&&xx<=x&&yy>=1&&yy<=y&&zz>=1&&zz<=z&&dis[xx][yy][zz]==-1;
}
void bfs() {
	while(l<=r) {
		Node s=Q[l];
		l++;
//		printf("%d %d %d %d\n",s.x,s.y,s.z,l);
		for(int i=0; i<6; i++) {
			int xx=s.x+rx[i],yy=s.y+ry[i],zz=s.z+rz[i];
			if(chk(xx,yy,zz)) {
				dis[xx][yy][zz]=dis[s.x][s.y][s.z]+1,Q[++r]=(Node) {
					xx,yy,zz
				};
				if(w[xx][yy][zz]==1)R=max(R,dis[xx][yy][zz]),a[++si]=(node) {
					xx,yy,zz,dis[xx][yy][zz]
				};
			}
		}
	}
}
//void dfs(int zz,int dis,int x,int y,int lim,int ndis) {
//	if(zz==0||zz==z+1)return;
//	for(int i=lim; i<=si; i++) {
//		node b=a[i];
//
//	}
//	dfs(zz-1,dis-1,x,y,lim);
//	dfs(zz+1,dis-1,x,y,lim);
//}

const int N = 1010;
int qz[N][N];
int updx(int i) {
	return i + 2 * y + x;
}
int updy(int i) {
	return i + x + y;
}
int chk() {
	puts("???");
	int mx = 0;
	for(int i = 1; i < N; ++i) qz[i][0] += qz[i - 1][0];
	for(int j = 1; j < N; ++j) qz[0][j] += qz[0][j - 1];
	for(int i = 1; i < N; ++i)
		for(int j = 1; j < N; ++j) {
			qz[i][j] += qz[i - 1][j] + qz[i][j - 1] - qz[i - 1][j - 1];
//			if(qz[i][j] < 0) printf("qz%d\n", qz[i][j]);
		}
	for(int i = 1; i <= x; ++i)
		for(int j = 1; j <= y; ++j) {
			int nx = updx(i - j), ny = updy(i + j);
			printf("%d %d %d\n", i - j, i + j, qz[nx][ny]);
			mx = max(mx, qz[nx][ny]);
		}
	puts("?????");
	memset(qz, 0, sizeof qz);
	return mx;
}

void add(int x1, int y1, int x3, int y3, int pls) {
	printf("%d %d %d %d\n", x1, y1, x3, y3);
	qz[x1][y1] += pls, qz[x3 + 1][y3 + 1] += pls;
	qz[x3 + 1][y1] -= pls, qz[x1][y3 - 1] -= pls;
}

bool check(int dis) {
	int Y=si + 1;
	for(int i = 1; i <= si; ++i) if(a[i].dis > dis) {
			Y = i;
			break;
		}
	printf("Y = %d\n", Y);
	if(Y == si + 1) return true;
	int i,j,h, pos = si - y + 1;
//	dfs(a[y].z,dis,a[y].x,a[y].y,y+1,dis);
	for(int i = 1; i <= z; ++i) {
		printf("i = %d\n", i);
		int flg = 1;
		for(int j = Y; j <= si; ++j) {
			int x = a[j].x, y = a[j].y, len = min(x + y, dis - abs(i - a[j].z));
			if(len < 0) flg = 0;
			else {
				int mx = x - y, my = x + y;
				int x1 = mx - len, y1 = my + len;
				int x3 = mx + len, y3 = my - len;
				printf("mx = %d, my = %d, x1 = %d, y1 = %d, x3 = %d, y3 =%d\n", mx, my, x1, y1, x3, y3);
				add(updx(x1), updy(y1), updx(x3), updy(y3), 1);
			}
		}
		printf("i = %d\n", i);
		if(flg && chk() == pos) return true;
	}
	return false;
}
int main() {
	while(scanf("%d%d%d",&z,&x,&y)!=EOF) {
		l=1,r=si=0,memset(dis,-1,sizeof(dis));
		for(i=1; i<=z; i++)
			for(j=1; j<=x; j++) {
				scanf("%s",s+1);
				for(h=1; h<=y; h++) {
					if(s[h]=='@')Q[++r]=(Node) {j,h,i},w[j][h][i]=2,dis[j][h][i]=0;
					else if(s[h]=='*')w[j][h][i]=1;
					else w[j][h][i]=3;
				}
			}
		R=0,bfs(),sort(a+1,a+si+1);
		for(int i = 1; i <= si; ++i)
			printf("x = %d, y = %d, z = %d, dis = %d\n", a[i].x, a[i].y, a[i].z, a[i].dis);
		printf("???%d\n", check(2));
//		L=1,res=R;
//		while(L<=R) {
//			mid=L+R>>1;
//			printf("mid = %d\n", mid);
//			if(check(mid))res=mid,r=mid-1;
//			else l=mid+1;
//		}
		printf("%d\n",res);
	}
	return 0;
}