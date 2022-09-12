#include<bits/stdc++.h>
using namespace std;
#define M 12
int n,k,m,i,j,c[M],a[M][M],r[M],ans,s[M],si,p[M],y[M];
bool mark[M],mk[M],ms[M];
void dfs(int x,int la,int score) {
//	printf("!!%d %d %d\n",x,la,score);
//	for(int i=1; i<=si; i++)printf("%d ",s[p[i]]);
//	puts("");
	if(x==n+1) {
//		printf("!%d\n",score);
//		for(int i=1; i<=si; i++)printf("%d ",s[p[i]]);
//		puts("");
		for(int i=0; i<m; i++)if(la&(1<<i))score++;
		ans=min(ans,score);
		return;
	}
	int sc;
	int z[M],cnt=0;
	for(int i=1; i<=n; i++) {
		z[i]=y[i];
		if(c[i]==s[p[x]]&&y[i]!=s[p[x]])cnt++;
	}
	if(!cnt) {
		ms[s[p[x]]]=1,dfs(x+1,la,score),ms[s[p[x]]]=0;
		return;
	}
	for(int now=0; now<1<<m; now++) {
		sc=score;
		for(int i=1; i<=n; i++)mk[i]=0;
		for(int i=0; i<m; i++) {
			sc+=((now&(1<<i))>=1)^((la&(1<<i))>=1);
//			printf("!!!!!%d %d %d %d %d %d\n",score,sc,la,now,i,(now&(1<<i))^(la&(1<<i)));
			if(now&(1<<i)) {
				for(j=1; j<=r[i]; j++)mk[a[i][j]]=1;
			}
		}
		int i;
		for(i=1; i<=n; i++) {
			if(c[i]==s[p[x]]&&y[i]!=s[p[x]]&&mk[i])break;
			if(!mk[i]&&ms[c[i]])break;
			if(!mk[i])y[i]=s[p[x]];
		}
//		printf("!!!%d %d %d\n",mk[1],ms[c[1]],i);
		if(i>n) {
			sc++;
			ms[s[p[x]]]=1;
//			printf("%d %d\n",x,s[p[x]]);
			dfs(x+1,now,sc);
			ms[s[p[x]]]=0;
		}
		for(int i=1; i<=n; i++)y[i]=z[i];
	}
}
int main() {
	scanf("%d%d%d",&n,&k,&m),ans=1e9;
	for(i=1; i<=n; i++)scanf("%d",&c[i]),mark[c[i]]=y[i]=1;
	for(i=0; i<m; i++) {
		scanf("%d",&r[i]);
		for(j=1; j<=r[i]; j++)scanf("%d",&a[i][j]);
	}
	for(i=1; i<=k; i++)if(mark[i])s[++si]=i,p[si]=si;
	while(1) {
		dfs(1,0,0);
		for(i=si; p[i]<p[i-1]&&i>0; i--);
		if(i==1)break;
		for(j=si; p[j]<p[i-1]; j--);
		swap(p[j],p[i-1]),sort(p+i,p+si+1);
	}
	if(ans==1e9)printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
/*
10 10 10
1 2 3 4 5 6 7 8 9 10
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
*/
