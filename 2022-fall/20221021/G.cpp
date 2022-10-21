#include<bits/stdc++.h>
using namespace std;
int T,e,i,j,mark[10][10],cnt,t,y;
char s[10][10];
bool f;
int rx[]= {1,0,-1,0},ry[]= {0,1,0,-1};
bool chk(int x,int y) {
	return x<0||y<0||x>=9||y>=9;
}
void dfs(int x,int y) {
//	printf("%d %d %c\n",x,y,s[x][y]);
	if(mark[x][y]==t)return;
	mark[x][y]=t;
	if(s[x][y]=='.') {
		cnt++;
		return;
	}
	if(s[x][y]=='x')return;
	int nx,ny;
	for(int i=0; i<4; i++) {
		nx=x+rx[i],ny=y+ry[i];
		if(!chk(nx,ny))dfs(nx,ny);
	}
}
int main() {
	scanf("%d",&T);
	for(e=1; e<=T; e++) {
		f=0,y=t;
		for(i=0; i<9; i++)scanf("%s",s[i]);
		for(i=0; i<9; i++)
			for(j=0; j<9; j++)
				if(s[i][j]=='o'&&mark[i][j]<=y) {
					cnt=0;
					t++,dfs(i,j);
					if(cnt==1) {
						f=1;
						break;
					}
				}
		printf("Case #%d: ",e);
		if(f)printf("Can kill in one move!!!\n");
		else printf("Can not kill in one move!!!\n");
	}
	return 0;
}
/*
1
......ox.
..xxx..o.
.xooox...
.xo.ox...
.xooox...
..xxx....
.......o.
...x.....
........o
*/