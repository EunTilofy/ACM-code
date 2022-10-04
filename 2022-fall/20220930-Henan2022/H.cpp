#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define N 1000005
int T,m,x,y,i,j,k,st,ed,mark[N],ti,id[2][M][4],mk[2][M][4],tot,l,r,ii,jj,kk;
char a[2][M];
struct node {
	int i,j,k;
} Q[N],now,n[N][2];
void find(int i,int j,int k) {
	int ii=-1,jj=-1,kk=-1;
	if(k==2&&i==0)ii=1,jj=j,kk=0;
	if(k==1&&j>1)ii=i,jj=j-1,kk=3;
	if(k==3&&j<m)ii=i,jj=j+1,kk=1;
	if(k==0&&i==1)ii=0,jj=j,kk=2;
//	printf("%d %d %d %d %d %d\n",i,j,k,ii,jj,kk);
	Q[++r]=(node) {i,j,k},mark[id[i][j][k]]=ti;
	if(ii!=-1)Q[++r]=(node) {ii,jj,kk},mark[id[ii][jj][kk]]=ti;
}
bool bfs() {
	l=0,r=1;
	Q[1]=(node) {
		0,x,0
	},mark[id[0][x][0]]=ti;
	while(l<r) {
		now=Q[++l];
//		printf("%d %d %d\n",now.i,now.j,now.k);
		if(a[now.i][now.j]=='L') {
			if(now.k&1) {
				for(j=0; j<=2; j+=2)if(mark[id[now.i][now.j][j]]!=ti)find(now.i,now.j,j);
			} else for(j=1; j<=3; j+=2)if(mark[id[now.i][now.j][j]]!=ti)find(now.i,now.j,j);
		} else if(mark[id[now.i][now.j][(now.k+2)%4]]!=ti)find(now.i,now.j,(now.k+2)%4);
		if(mark[id[1][y][2]]==ti)return 1;
	}
	return 0;
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&m,&x,&y),x--,y--,tot=0,ti++;
		for(i=0; i<2; i++)scanf("%s",a[i]);
		for(i=0; i<2; i++)
			for(j=0; j<m; j++)
				for(k=0; k<4; k++) {
					ii=-1;
					if(k==2&&i==0)ii=1,jj=j,kk=0;
					if(k==1&&j>0)ii=i,jj=j-1,kk=3;
					if(k==3&&j<m-1)ii=i,jj=j+1,kk=1;
					if(k==0&&i==1)ii=0,jj=j,kk=2;
					if(mk[i][j][k]!=ti&&(ii==-1||mk[ii][jj][kk]!=ti))mk[i][j][k]=ti,id[i][j][k]=++tot;
					else if(ii!=-1&&mk[i][j][k]!=ti)mk[i][j][k]=ti,id[i][j][k]=id[ii][jj][kk];
				}
		if(bfs())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}