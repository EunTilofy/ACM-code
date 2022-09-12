#include<bits/stdc++.h>
using namespace std;
#define M 100005
struct node {
	long long w;
	int k,id;
	bool operator<(const node &_) const {
		return _.w>w;
	}
} a;
int n,c[M],f[M],d[M],g[M],e[M],i,res,all,mark[M],mk[M];
long long sum,ans;
priority_queue<node>Q;
priority_queue<node>QB;
int main() {
	scanf("%d",&n),memset(mark,-1,sizeof(mark)),memset(mk,-1,sizeof(mk));
	for(i=1; i<=n; i++)scanf("%d%d%d",&c[i],&f[i],&d[i]);
	for(i=1; i<n; i++)scanf("%d%d",&e[i],&g[i]);
	for(i=1; i<=n; i++) {
		res=0;
		while(d[i]&&Q.size()) {
			a=Q.top(),Q.pop();
//			printf("%d %d %d %d\n",i,a.k,a.id,mark[a.id]);
			if(!mark[a.id])continue;
			else if(mark[a.id]!=-1)a.k=mark[a.id],mark[a.id]=-1;
//			printf("%d %d %d %d\n",i,a.w+sum,a.k,a.id);
			if(!res&&a.w+sum>=f[i]) {
				res=max(c[i],d[i]),ans+=1ll*f[i]*res,d[i]-=res;
				if(!d[i]) {
					Q.push(a);
					break;
				}
			}
			if(a.k<=d[i]) {
				d[i]-=a.k,ans+=(a.w+sum)*a.k,all-=a.k,mk[a.id]=0;
			} else {
				a.k-=d[i],ans+=(a.w+sum)*d[i],all-=d[i],d[i]=0,mk[a.id]=a.k,Q.push(a);
			}
		}
		if(d[i]) {
			if(c[i]-res<d[i])break;
			ans+=1ll*f[i]*d[i],res+=d[i],d[i]=0;
		}
		if(c[i]>res)Q.push((node) {
			f[i]-sum,c[i]-res,i
		}),QB.push((node) {
			-f[i]+sum,c[i]-res,i
		});
		sum+=g[i],all+=c[i]-res;
		while(all>e[i]) {
			a=QB.top(),QB.pop();
			if(!mk[a.id])continue;
			else if(mk[a.id]!=-1)a.k=mk[a.id],mk[a.id]=-1;
			if(all-a.k>=e[i])all-=a.k,mark[a.id]=0;
			else a.k-=all-e[i],mark[a.id]=a.k,all=e[i],QB.push(a);
		}
//		printf("%lld %lld\n",ans,c[i]-res);
	}
	if(i<=n)printf("-1\n");
	else printf("%lld\n",ans);
	return 0;
}
