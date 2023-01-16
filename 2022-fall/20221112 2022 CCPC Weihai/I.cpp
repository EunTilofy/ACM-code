#include<bits/stdc++.h>
using namespace std;
#define M 50005
int T,i,n,k,a[M],b[M],j,R[25];
long long l,r,ans,mid,c[M];
bool chk(long long x,int n) {
	for(int i=1; i<=n; i++)c[i]=x*a[i];
	for(int i=k; i>=0; i--) {
		int now=b[i];
		for(int j=n; j>0&&now; j--) {
			long long cnt=c[j]/R[i];
			if(!cnt)break;
			if(cnt>now)cnt=now;
			c[j]-=cnt*R[i];
			now-=cnt;
		}
		sort(c+1,c+n+1);
		if(now) {
			for(int j=n; j>0&&now; j--)now--,c[j]=0,n--;
		}
		if(!c[n])return 1;
	}
	return 0;
}
int main() {
	scanf("%d",&T),R[1]=1;
	for(i=2; i<=20; i++)R[i]=R[i-1]*2;
	while(T--) {
		scanf("%d%d",&n,&k),r=0;
		long long mx=0;
		for(i=1; i<=n; i++)scanf("%d",&a[i]),mx+=a[i];
		sort(a+1,a+n+1);
		for(i=1; i<=k; i++)scanf("%d",&b[i]),r+=1ll*b[i]*R[i];
		l=0,r/=mx,ans=0;
		while(l<=r) {
			mid=(l+r)/2;
			if(chk(mid,n))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}