#include<bits/stdc++.h>
using namespace std;
int T;
char s[10];
bool chk() {
	scanf("%s",s);
	if(s[0]=='Y')return 1;
	return 0;
}
int main() {
	scanf("%d",&T);
	while(T--) {
		printf("2\n");
		fflush(stdout);
		if(chk())continue;
		printf("3\n");
		fflush(stdout);
		if(chk())continue;
		printf("4\n");
		fflush(stdout);
		if(chk())continue;
		printf("6\n");
		fflush(stdout);
		if(chk())continue;
		printf("16\n");
		fflush(stdout);
		if(chk())continue;
		printf("12\n");
		fflush(stdout);
		if(chk())continue;
	}
	return 0;
}