#include<bits/stdc++.h>
using namespace std;
#define M 2000005
int read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}
int n,v[M],si[M],res,i,f,j,x,y,ans,h[M],nx[M],r[M],tot,sum[M],id[M],L[M],R[M],top;
void add(int x,int y) {
	r[++tot]=y,nx[tot]=h[x],h[x]=tot;
}
void dfs(int x) {
	L[x]=++top,si[x]=1;
	for(int i=h[x]; i; i=nx[i]) {
		dfs(r[i]),si[x]+=si[r[i]];
	}
	R[x]=top;
}
void add(int x) {
	while(x<=n)sum[x]++,x+=x&-x;
}
int que(int x) {
	int ans=0;
	while(x)ans+=sum[x],x-=x&-x;
	return ans;
}
int main() {
	n = read();
	for(i=1; i<=n; i++)v[i] = read(),id[v[i]]=i;
	for(i=2; i<=n; i++)f = read(),add(f,i);
	dfs(1);
	for(i=0; i<n; i++) {
//		printf("%d\n",i);
		x=id[i],ans=res=0;
		for(j=h[x]; j; j=nx[j]) {
			y=r[j],f=que(R[y])-que(L[y]-1),res+=f;
			if(f==i)ans=max(ans,si[y]);
			else if(f)break;
		}
		if(!res)ans=max(ans,n-si[x]);
		printf("%d ",ans);
		add(L[x]);
	}
	printf("%d\n",n);
	return 0;
}