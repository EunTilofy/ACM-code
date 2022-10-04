#include<bits/stdc++.h>
using namespace std;
int n,i;
int main() {
	scanf("%d",&n);
	if(n==1)printf("1");
	else if(n<=10) {
		printf("10");
		for(i=2; i<n; i++)printf("%d",i);
	} else printf("-1");
	return 0;
}