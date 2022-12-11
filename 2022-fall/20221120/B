#include<bits/stdc++.h>
using namespace std;
char s[10005];
int i,n,cnt,now,ans;
int main() {
	scanf("%s",s);
	n=strlen(s);
	for(i=0; i<n; i++)
		if(s[i]=='U'||s[i]=='T')now=1;
		else if(s[i]=='S')now=2;
		else if(s[i]=='C')break;
		else if(now) {
			ans+=now;
		}
	printf("%d\n",ans);
	return 0;
}