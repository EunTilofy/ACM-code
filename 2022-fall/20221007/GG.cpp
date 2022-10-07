#include<bits/stdc++.h>
using namespace std;
bool cur1;
int dp[1<<24],fa[1<<24],id[1<<24],i,j,h,k,n,l,lim,mk[5],ex[26][4],now[26][4],ti,now1;
char s[5];
bool f;
int chg(char s) {
	if(s=='A')return 0;
	if(s=='C')return 1;
	if(s=='G')return 2;
	return 3;
}
char cha(int x) {
	if(x==0)return 'A';
	if(x==1)return 'C';
	if(x==2)return 'G';
	return 'T';
}
bool cur2;
int main() {
//	printf("%.10f\n",((&cur2)-(&cur1))/1024.0/1024);
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%s",s),l=strlen(s);
		for(j=0; j<l; j++)mk[chg(s[j])]=i;
		for(j=0; j<4; j++)if(mk[j]!=i)ex[i][j]=1;
		if(l==4)now1++;
		else now1=0;
		lim=max(lim,now1+1);
	}
	for(i=lim; i<n; i++) {
		for(j=1; j+i-1<=n; j++) {
			for(k=1; k<=i; k++) {
				for(h=0; h<4; h++)
					if(ex[j+k-1][h])now[k][h]|=1<<j-1;
			}
		}
		f=0,ti++,dp[0][0]=ti;
		for(j=1; j<=i; j++) {
			f=!f;
			for(k=0; k<4; k++)
				for(h=0; h<(1<<(n-i+1)); h++)
					if(dp[!f][h]==ti) {
						dp[f][h|now[j][k]]=ti+1,fa[h|now[j][k]]=h;
					}
			ti++;
		}
		if(dp[f][(1<<(n-i+1))-1]==ti) {
			printf("%d\n",i);
			break;
		}
	}
	if(lim==n+1) {
		for(i=1; i<=n+1; i++)printf("A");
	} else if(i==n) {
		for(i=1; i<=n; i++) {
			for(j=0; j<4; j++)
				if(ex[i][j]) {
					printf("%c",cha(j));
					break;
				}
			if(j==4)printf("A");
		}
	}
	return 0;
}
/*
25
ACG
AGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
ACGT
*/