#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;++i)
using namespace std;
int read(){
	int x=0,fh=1; char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') fh=-1;
	for (;isdigit(ch);ch=getchar()) x=x*10+(ch^48);
	return x*fh;
}
int main(){
	int n=read(); printf("! -1\n"); fflush(stdout);
	return 0;
}
