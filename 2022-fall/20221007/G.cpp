#include<bits/stdc++.h>
using namespace std;
bool cur1;
int dp[1<<24],fa[1<<24],dg[1<<24],i,j,h,k,n,l,lim,mk[10],ex[26][4],now[26][4],ti,now1,ans[30],st;
char s[10];
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
//	freopen("questionable.in", "r", stdin);
//	freopen("questionable.out", "w", stdout);
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%s",s),l=strlen(s);
		for(j=0; j<l; j++)mk[chg(s[j])]=i;
		for(j=0; j<4; j++)if(mk[j]!=i)ex[i][j]=1;
		if(l==4)now1++;
		else now1=0;
		lim=max(lim,now1+1);
	}
	if(lim==1) {
		for(i=0; i<4; i++) {
			for(j=1; j<=n; j++)if(!ex[j][i])break;
			if(j>n)break;
		}
		if(i<4) {
			printf("%c",cha(i));
			return 0;
		}
		lim++;
	}
	for(i=lim; i<n; i++) {
		memset(now,0,sizeof(now));
		for(j=1; j+i-1<=n; j++) {
			for(k=1; k<=i; k++) {
				for(h=0; h<4; h++)
					if(ex[j+k-1][h])now[k][h]|=1<<j-1;
			}
		}
		ti++,dp[0]=ti,st=ti;
		now1=(1<<(n-i+1))-1;
		for(j=1; j<=i; j++) {
			for(h=now1; h>=0; h--)
				if(dp[h]==ti) {
					for(k=0; k<4; k++)
						if(dp[h|now[j][k]]<st&&(h|now[j][k])!=h)
							dp[h|now[j][k]]=ti+1,fa[h|now[j][k]]=h,dg[h|now[j][k]]=j;
					dp[h]=ti+1;
				}
			ti++;
		}
		if(dp[now1]==ti) {
//			printf("%d\n",i);
			while(now1) {
//				printf("%d %d %d\n",now1,fa[now1],dg[now1]);
				for(k=0; k<4; k++)
					if((now[dg[now1]][k]|fa[now1])==now1) {
						ans[dg[now1]]=k;
						break;
					}
				now1=fa[now1];
			}
			for(j=1; j<=i; j++)printf("%c",cha(ans[j]));
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

25
ACG
AGT
AGT
AG
ACG
ACT
A
CGT
AGT
ACG
AGT
C
ACT
AGT
AGT
T
AG
AGT
CGT
A
AGT
AGT
ACT
ACT
ACG
*/