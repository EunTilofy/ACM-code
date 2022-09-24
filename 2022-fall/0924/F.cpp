#include<bits/stdc++.h>
using namespace std;
#define M 105
int n,f,i,j,fl,a[M],ans[M],si;
bool mark[M];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d",&n,&f);
	for(i=1; i<=n; i++)scanf("%d",&a[i]),markn[a[i]]=1;
	for(i=1; i<=n; i++)
		if(mark[a[i]]) {
			if(f<a[i]) {
				for(j=f; j<=a[i]; j++)
					if(mark[j])mark[j]=0,ans[++si]=j;
			} else {
				for(j=f; j>=a[i]; j--)
					if(mark[j])mark[j]=0,ans[++si]=j;
			}
		}
	for(i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}