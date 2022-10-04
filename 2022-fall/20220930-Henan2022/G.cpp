#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,ans;
char s[1005][4005];
int main() {
	scanf("%d%d",&n,&m);
	for(i=0; i<n; i++)scanf("%s",s[i]);
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++)if(s[j][i]=='0')break;
		if(j==n)ans++;
	}
	printf("%d\n",ans);
	return 0;
}