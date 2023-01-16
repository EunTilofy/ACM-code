#include <bits/stdc++.h>
using namespace std;
int T,i,l[4];
char s[4][15];
int pro(int x) {
	if(s[x][1]=='F')return 1;
	if(s[x][1]=='B')return 3;
	if(s[x][1]=='I')return 4;
	if(s[x][1]=='H')return 8;
	if(l[x]==3)return 2;
	if(l[x]==4)return 5;
	if(l[x]==7)return 6;
	if(l[x]==10)return 7;
}
int main() {
	scanf("%d",&T);
	while(T--) {
		for(i=0; i<4; i++)scanf("%s",s[i]),l[i]=strlen(s[i]);
		if(pro(0)==pro(2)||pro(1)==pro(3))printf("None\n");
		else if(pro(0)==pro(1)||pro(2)==pro(3))printf("Cis\n");
		else if(pro(0)==pro(3)||pro(1)==pro(2))printf("Trans\n");
		else if((pro(0)>pro(2))^(pro(1)>pro(3)))printf("Entgegen\n");
		else printf("Zasamman\n");
	}
	return 0;
}