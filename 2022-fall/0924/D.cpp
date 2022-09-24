#include<bits/stdc++.h>
using namespace std;
#define M 1005
int n,m,i,x,y,d[M],Q[M],l,r,mark[M],dp[M];
vector<int>a[M],b[M];
void bfs() {
	Q[++r]=1,d[1]=1;
	while(l<r) {
		l++,x=Q[l];
		for(int i=0; i<a[x].size(); i++) {
			if(!d[a[x][i]])Q[++r]=a[x][i],d[a[x][i]]=d[x]+1;
			if(d[a[x][i]]>d[x])b[x].push_back(a[x][i]);
		}
	}
}
void dfs(int x) {
	mark[x]=1;
	if(!b[x].size())dp[x]=0;
	for(int i=0; i<b[x].size(); i++) {
//		printf("!%d %d\n",x,b[x][i]);
		if(!mark[b[x][i]])dfs(b[x][i]);
		dp[x]|=(!dp[b[x][i]]);
	}
//	printf("%d %d\n",x,dp[x]);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d",&n,&m);
	for(i=1; i<=m; i++)scanf("%d%d",&x,&y),a[x].push_back(y),a[y].push_back(x);
	bfs();
//	printf("!");
	dfs(1);
	if(!dp[1])puts("Nikolay");
	else puts("Vladimir");
	return 0;
}