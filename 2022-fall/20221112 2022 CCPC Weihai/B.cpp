#include<bits/stdc++.h>
using namespace std;
#define M 100005
int n,i,s[M],fa[M],ans[M],w[M],id[M],si,res[M],res1[M],res2[M];
bool fl;
map<int,int>pos;
void dfs(int x) {
	if(fl)return;
	if(x==1) {
		fl=1;
		return;
	}
	int k=s[x-1]-s[x];
	if(k==1) {
		dfs(x-1);
		if(fl)res[++si]=-1;
		return;
	}
	k=1-k;
	int up=sqrt(k);
	for(int i=1; i<=up; i++)
		if(k%i==0) {
			int y1=i+1,y2=k/i+1;
			int ss=y1*y2;
//			printf("%d %d %d %d\n",x,ss,y1,y2);
			if(pos.count(ss)&&pos[ss]!=0) {
//				printf("!");
				pos[ss]--;
				pos[y1]++,pos[y2]++;
				dfs(x-1);
				pos[y1]--,pos[y2]--,pos[ss]++;
				if(fl) {
					res[++si]=ss,res1[si]=y1,res2[si]=y2;
					return;
				}
			}
		}
}
void rdfs(int x) {
	if(x==0) {
		return;
	}
	int ss=res[x],y1=res1[x],y2=res2[x];
	if(ss!=-1) {
		for(int i=1; i<=si; i++)
			if(ans[i]==ss) {
				for(int j=si+1; j>i+1; j--)ans[j]=ans[j-1];
				for(int j=1; j<=si; j++)if(w[id[j]]>=i)w[id[j]]++;
				ans[i]=y1,ans[i+1]=y2,w[x]=i;
			}
		si++,id[si]=x;
	}
	rdfs(x-1);
}
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&s[i]);
	pos[s[n]]=1,dfs(n);
	if(!fl) {
//		printf("-1\n");
		printf("%d\n",n);
		for(i=1; i<=n; i++)printf("%d\n",s[i]);
	} else {
		ans[si=1]=s[n],rdfs(n-1);
		for(i=si+1; i<=n; i++)ans[i]=1;
		for(i=1; i<n; i++)if(!w[i])w[i]=si,si++;
//		for(i=1; i<=n; i++)printf("%d ",ans[i]);
//		puts("");
//		for(i=1; i<n; i++)printf("%d\n",w[i]);
		int sum=0;
		for(i=1; i<=n; i++)sum+=ans[i];
		si=n;
		printf("%d\n%lld\n",n,sum);
		for(i=1; i<n; i++) {
//			printf("!%d ",w[i]);
			sum+=ans[w[i]]*ans[w[i]+1]-ans[w[i]]-ans[w[i]+1];
			ans[w[i]]=ans[w[i]]*ans[w[i]+1];
			for(int j=w[i]+1; j<si; j++)ans[j]=ans[j+1];
			for(int j=i+1; j<n; j++)if(w[j]>w[i])w[j]--;
			si--;
			printf("%lld\n",sum);
		}
	}
	return 0;
}