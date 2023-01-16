#include <bits/stdc++.h>
using namespace std;
#define M 10005
int n,a[M],ans[M],i,j,l[M],r[M],fa[M];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&a[i]),l[i]=r[i]=a[i],fa[i]=i+1;
	for(i=n-1; i>0; i--) {//printf("!%d ",i);
		int mx=-1e9,id=1;
		for(j=1; fa[j]<n+1; j=fa[j]) {//printf("%d ",j);
			if((max(r[fa[j]],r[j])-min(l[fa[j]],l[j]))-(r[fa[j]]-l[fa[j]])-(r[j]-l[j])>mx)mx=(max(r[fa[j]],r[j])-min(l[fa[j]],l[j]))-(r[fa[j]]-l[fa[j]])-(r[j]-l[j]),id=j;
		}
		ans[i]=ans[i+1]+mx,l[id]=min(l[id],l[fa[id]]),r[id]=max(r[id],r[fa[id]]),fa[id]=fa[fa[id]];
	}
	for(i=1; i<=n; i++)printf("%d\n",ans[i]);
	return 0;
}