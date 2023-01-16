#include<bits/stdc++.h>
using namespace std;
#define M 1005
int r,c,i,j,ans;
char s[M][M];
bool chk(int x,int y) {
	if(s[x][y]=='/'&&s[x][y+1]=='\\'&&s[x+1][y]=='\\'&&s[x+1][y+1]=='/')return 1;
	return 0;
}
int rx[]= {0,1,0,-1},ry[]= {1,0,-1,0};
bool mark[M][M];
bool check(int x,int y) {
	return x>0&&y>0&&x<=r&&y<=c&&s[x][y]=='.'&&!mark[x][y];
}
void dfs(int x,int y) {
//	printf("!%d %d\n",x,y);
	mark[x][y]=1;
	for(int i=0; i<4; i++) {
		int nx=x+rx[i],ny=y+ry[i];
		if(check(nx,ny))dfs(nx,ny);
	}
	int nx=x-1,ny=y-1;
	if(check(nx,ny)&&(s[x-1][y]!=s[x][y-1]||s[x][y-1]!='/'))dfs(nx,ny);
	nx=x-1,ny=y+1;
	if(check(nx,ny)&&(s[x-1][y]!=s[x][y+1]||s[x][y+1]!='\\'))dfs(nx,ny);
	nx=x+1,ny=y-1;
	if(check(nx,ny)&&(s[x+1][y]!=s[x][y-1]||s[x][y-1]!='\\'))dfs(nx,ny);
	nx=x+1,ny=y+1;
	if(check(nx,ny)&&(s[x+1][y]!=s[x][y+1]||s[x][y+1]!='/'))dfs(nx,ny);
}
int main() {
	scanf("%d%d",&r,&c);
	for(i=1; i<=r; i++)scanf("%s",s[i]+1);
	for(i=1; i<=r; i++) {
		if(s[i][1]=='.'&&!mark[i][1])dfs(i,1);
		if(s[i][c]=='.'&&!mark[i][c])dfs(i,c);
	}
	for(i=1; i<=c; i++) {
		if(s[1][i]=='.'&&!mark[1][i])dfs(1,i);
		if(s[r][i]=='.'&&!mark[r][i])dfs(r,i);
	}
	for(i=1; i<=r; i++)
		for(j=1; j<=c; j++)
			if(chk(i,j))ans++;//,printf("!%d %d\n",i,j);
			else if(s[i][j]=='.'&&!mark[i][j])ans++,dfs(i,j);//,printf("%d %d\n",i,j);
	printf("%d\n",ans);
	return 0;
}
/*
8 20
/\/\/\/\/\/\/\/\/\/\
\../\.\/./././\/\/\/
/./\.././\/\.\/\/\/\
\/\/\.\/\/./\/..\../
/\/./\/\/./..\/\/..\
\.\.././\.\/\/./\.\/
/.../\../..\/./.../\
\/\/\/\/\/\/\/\/\/\/
*/