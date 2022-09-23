#include<bits/stdc++.h>
using namespace std;
int T,n,i,u,v,deg[1000005],ans;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n),ans=0;
		for(i=1; i<n; i++)scanf("%d%d",&u,&v),deg[u]++,deg[v]++;
		for(i=1; i<=n; i++) {
			ans+=(deg[i]==1);
			deg[i]=0;
		}
		if(n==1)ans=1;
		printf("%d\n",ans);
	}
	return 0;
}