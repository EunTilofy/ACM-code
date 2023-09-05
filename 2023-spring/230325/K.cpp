#include<bits/stdc++.h>
using namespace std;
map<string,int>p;
int id,n,i,j,k,le[1005],ri[1005],an[1005],ans,fl;
string c,f;
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		cin>>c>>f>>k;
		if(!p[c])p[c]=++id;
		if(f[0]=='a') {
			if(k>=2)fl=1;
			an[p[c]]=1;
		} else if(f[0]=='l')le[p[c]]=k;
		else ri[p[c]]=k;
	}
	for(i=1; i<=id; i++)
		if(!an[i]) {
			if(le[i]&&ri[i]) {
				fl=1,ans+=max(le[i],ri[i]);
			} else if(le[i])ans+=le[i];
			else ans+=ri[i];
		} else ans+=max(1,max(le[i],ri[i]));
	if(!fl)printf("impossible\n");
	else printf("%d\n",ans+1);
	return 0;
}