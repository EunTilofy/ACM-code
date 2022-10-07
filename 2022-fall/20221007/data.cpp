#include<bits/stdc++.h>
using namespace std;
bool mark[1005][1005];
int mk[100005];
int main() {
	srand(time(NULL));
	int n=rand()%1000+1,m=rand()%min(10000,n*(n-1)/2)+1;
	printf("%d %d\n",n,m);
	for(int i=1; i<=n; i++)mark[i][i]=1;
	for(int i=1; i<=m; i++) {
		int a=rand()%n+1;
		int b=rand()%n+1;
		while(mark[a][b])a=rand()%n+1,b=rand()%n+1;
		mark[a][b]=mark[b][a]=1,printf("%d %d\n",a,b);
	}
	int k=rand()%10000+1;
	printf("%d\n",k);
	for(int i=1; i<=k; i++) {
		int c=rand()%4+1;
		printf("%d ",c);
		for(int j=1; j<=c; j++) {
			int a=rand()%m+1;
			while(mk[a]==i)a=rand()%m+1;
			mk[a]=i,printf("%d ",a);
		}
		puts("");
	}
	return 0;
}