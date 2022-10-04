#include<bits/stdc++.h>
using namespace std;
#define M 100005
#define N 1000005
int T,m,x,y,i,j,k,ti,mark[2][M][4],l,r,ii,jj,kk,fl;
char a[2][M];
struct node {
	int i,j,k;
} Q[N],now;
void find(int i,int j,int k) {
	if(i==1&&j==y&&k==2)fl=1;
	int ii=-1,jj=-1,kk=-1;
	if(k==2&&i==0)ii=1,jj=j,kk=0;
	if(k==1&&j>0)ii=i,jj=j-1,kk=3;
	if(k==3&&j<m-1)ii=i,jj=j+1,kk=1;
	if(k==0&&i==1)ii=0,jj=j,kk=2;
	if(ii!=-1) {
//		printf("%d %d %d %d %d %d\n",i,j,k,ii,jj,kk);
		if(mark[ii][jj][kk]==ti)return;
		Q[++r]=(node) {ii,jj,kk},mark[ii][jj][kk]=ti;
	}
}
bool bfs() {
	l=0,r=1,fl=0;
	Q[1]=(node) {
		0,x,0
	},mark[0][x][0]=ti;
	while(l<r) {
		now=Q[++l];
//		printf("%d %d %d\n",now.i,now.j,now.k);
		if(a[now.i][now.j]=='L') {
			if(now.k&1) {
				for(j=0; j<=2; j+=2)find(now.i,now.j,j);
			} else for(j=1; j<=3; j+=2)find(now.i,now.j,j);
		} else {
			if(now.i == 0) {
				if(now.j == x) {
					if(now.k == 0) find(now.i,now.j,(now.k+2)%4);
				} else find(now.i,now.j,(now.k+2)%4);
			}
			if(now.i == 1) {
				if(now.j == y) {
					if(now.k == 0) find(now.i,now.j,(now.k+2)%4);
				} else find(now.i,now.j,(now.k+2)%4);
			}
		}
		if(fl)return 1;
	}
	return 0;
}
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&m,&x,&y),x--,y--,ti++;
		for(i=0; i<2; i++)scanf("%s",a[i]);
		if(bfs())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}