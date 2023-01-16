#include<bits/stdc++.h>
using namespace std;
#define M 1005
int r,c,i,j,ans,a[M][M],si[M];
char s[M][M];
bool mark[M][M];
bool chk(int x,int y) {
	if(s[x][y]=='/'&&s[x][y+1]=='\\')return 1;
	return 0;
}
int findl(int x,int y) {
	if(s[x][y]=='\\'&&s[x+1][y+1]=='\\')return y+1;
	if(s[x][y]=='\\'&&s[x+1][y]=='/')return y;
	if(s[x][y]=='\\')return 0;
	int t=upper_bound(a[x+1]+1,a[x+1]+si[x+1]+1,y)-a[x+1];
	t--;
	if(!t||t>si[x+1])return 0;
	int k=a[x+1][t],q;
	if(s[x+1][k]=='/')q=k+1;
	else q=k;
	int i;
	for(i=q; i<y; i+=2) {
		if(!chk(x,i))return 0;
		mark[x][i]=1;
	}
	if(i!=y)return 0;
	return k;
}
int findr(int x,int y) {
	if(s[x][y]=='/'&&s[x+1][y-1]=='/')return y-1;
	if(s[x][y]=='/'&&s[x+1][y]=='\\')return y;
	if(s[x][y]=='/')return 0;
	int t=lower_bound(a[x+1]+1,a[x+1]+si[x+1]+1,y)-a[x+1];
	if(!t||t>si[x+1])return 0;
	int k=a[x+1][t],q;
	if(s[x+1][k]=='\\')q=k-1;
	else q=k;
	int i;
	for(i=q; i>y; i-=2) {
		if(!chk(x,i))return 0;
		mark[x][i]=1;
	}
	if(i!=y)return 0;
	return k;
}
bool check(int x,int y) {
	int i,j,k,l=y,r=y+1,L,R;
	for(i=x; i<r; i++) {
		L=findl(i,l),R=findr(i,r);
		if(!L||!R)return 0;
		if(s[i+1][L]=='\\'&&s[i+1][R]=='/') {
			for(j=L+1; j<R; j+=2) {
				if(!chk(x+1,j))break;
				mark[x+1][j]=1;
			}
			if(j==R)return 1;
		}
		l=L,r=R;
	}
	return 0;
}
int main() {
	scanf("%d%d",&r,&c);
	for(i=1; i<=r; i++) {
		scanf("%s",s[i]+1);
		for(j=1; j<=c; j++)if(s[i][j]!='.')a[i][++si[i]]=j;
	}
	for(i=1; i<=r; i++)
		for(j=1; j<=c; j++)
			if(chk(i,j)&&!mark[i][j]) {
				mark[i][j]=1;
				if(check(i,j))ans++,printf("%d %d\n",i,j);
			}
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