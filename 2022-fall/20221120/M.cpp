#include<bits/stdc++.h>
using namespace std;
int a[10],res[15],cnt,l,noww;
char s[10],ans[1<<9][15];
bool mk[1<<9];
void rdfs() {
	int i,j,k,h;
	int now[10],s[10];
	for(i=0; i<(1<<9); i++)
		if(!mk[i]) {
			bool f,fl;
			for(j=1; j<=9; j++) {
				if(i&(1<<j-1))f=1;
				else f=0;
				fl=0;
				for(k=1; k<=9; k++)now[k]=0;
				now[j]=1;
				for(k=1; k<=13; k++)now[res[k]]++;
				if(now[j]>4)
					if(f)break;
					else continue;
				for(k=1; k<=9; k++)s[k]=now[k];
				for(h=1; h<=9; h++)
					if(now[h]>=2) {
						now[h]-=2;
						for(k=1; k<=9; k++) {
							if(now[k]>=3) {
								now[k]-=3;
							}
							if(now[k]>0) {
								if(k>=8)break;
								now[k+1]-=now[k],now[k+2]-=now[k],now[k]=0;
							} else if(now[k]<0)break;
						}
						if(k==10) {
							fl=1;
							break;
						}
						for(k=1; k<=9; k++)now[k]=s[k];
					}
				if(fl!=f)break;
			}
			if(j==10) {
				mk[i]=1;
				for(j=1; j<=13; j++)ans[i][j-1]=res[j]+'0';
			}
		}
}
void dfs(int x,int now) {
	if(x==14) {
		cnt++;
		rdfs();
//		for(int i=1;i<=13;i++)printf("%d ",res[i]);
//		puts("");
		return;
	}
	for(int i=now; i<=9; i++) {
		a[i]++;
		res[x]=i;
		dfs(x+1,a[i]==4?i+1:i);
		a[i]--;
	}
}
int main() {
	freopen("M.txt","w",stdout);
	dfs(1,1);
	int i,j;
	for(i=0; i<(1<<9); i++) {
		if(!mk[i])printf("\"0\",");
		else printf("\"%s\",",ans[i]);
	}
//	printf("!!");
//	printf("%d\n",cnt);
	return 0;
}
/*
93600

*/