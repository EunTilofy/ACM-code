#include<bits/stdc++.h>
using namespace std;
#define M 300005
int n,i,a[M],b[M],c[M],si,k;
long long ans;
char s[M];
int main() {
	scanf("%d%s",&n,s + 1);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	for(i=1; i<=n; i++)
		if(s[i]!=s[i-1])b[++si]=a[i];
		else b[si]=max(b[si],a[i]);
	if(si<=2){
		printf("0\n");
		return 0;
	}
	for(i=2; i<si; i++)c[i-1]=b[i];
	sort(c+1,c+si-1),k=(si-1)/2;
	for(i=si-2; k; i--,k--)ans+=c[i];
	printf("%lld\n",ans);
	return 0;
}
