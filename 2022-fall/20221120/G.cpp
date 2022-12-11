#include<bits/stdc++.h>
using namespace std;
#define M 2000005
int L,R,mid,ans,i,n,t,A[M],B[M],h[M],nx[M<<1],tot,r[M<<1],now[M],si,deg[M],que[M],ll,rr;
bool mark[M],mk[M];
struct node {
	int a,b;
	bool operator<(const node&_)const {
		return _.a>a;
	}
} w[M];
void add(int x,int y) {
	r[++tot]=y,nx[tot]=h[x],h[x]=tot;
}
void adds(int x,int y) {
	add(x,y),add(y,x);
}
bool chk(int n) {
	int cnt=0;
	int i,j;
	tot=0;
	for(i=1; i<=n; i++)h[i]=deg[i]=mk[i]=0;
	ll=1,rr=0;
	for(i=1; i<=t&&w[i].a<=n; i++)
		if(w[i].b<=n) {
			if(mark[w[i].a]||mark[w[i].b]) {
				if(mark[w[i].a]&&!mk[w[i].a])mk[w[i].a]=1,cnt++;
				if(mark[w[i].b]&&!mk[w[i].b])mk[w[i].b]=1,cnt++;
				if(!mark[w[i].a])que[++rr]=w[i].a,mk[w[i].a]=1,cnt++;
				if(!mark[w[i].b])que[++rr]=w[i].b,mk[w[i].b]=1,cnt++;
			} else adds(w[i].a,w[i].b),deg[w[i].a]+=2,deg[w[i].b]+=2;
		}
	while(ll<=rr) {
		if(cnt==n)return 1;
		int x=que[ll];
		ll++;
		for(i=h[x]; i; i=nx[i]) {
			int y=r[i];
			deg[x]--,deg[y]--;
			if(!mk[y])que[++rr]=y,mk[y]=1,cnt++;
		}
	}
	ll=1,rr=0;
	for(i=1; i<=n; i++)
		if(!mk[i]&&deg[i]==2) {
			que[++rr]=i,mk[i]=1,cnt++;
		}
	while(ll<=rr) {
		if(cnt==n)return 1;
		int x=que[ll];
		ll++;
		for(i=h[x]; i; i=nx[i]) {
			int y=r[i];
			deg[y]--,deg[x]--;
			if(deg[y]<2)return 0;
			if(deg[y]==2)que[++rr]=i,mk[i]=1,cnt++;
		}
	}
	if(cnt==n)return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>t;
	for(i=1; i<=t; i++) {
		cin>>A[i]>>B[i];
		if(A[i]>B[i])swap(A[i],B[i]);
		now[++si]=A[i],now[++si]=B[i];
	}
	sort(now+1,now+si+1),si=1;
	for(i=2; i<=2*t; i++)if(now[i]!=now[i-1])now[++si]=now[i];
	for(i=1; i<=si; i++)if(now[i]!=i) {
			R=i;
			break;
		}
	if(i>si)R=now[si]+1;
	for(i=1; i<=t; i++) {
		w[i].a=lower_bound(now+1,now+si+1,A[i])-now,w[i].b=lower_bound(now+1,now+si+1,B[i])-now;
//		printf("%d %d\n",a,b);
		if(w[i].a==w[i].b)mark[w[i].a]=1;
	}
	while(L<=R) {
		mid=L+R>>1;
		if(chk(mid))ans=mid,L=mid+1;
		else R=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}