#include<bits/stdc++.h>
using namespace std;
#define M 1000005
int m,i;
long long n,ans,l,r,mid,sum,b[M],L[M],R[M],a[M];
bool chk(long long len) {
	sum=0;
	long long ed=0,st;
	for(int i=1; i<=m; i++) {
		st=ed+1;
		ed=min(st+len-1,a[i+1]-1);
		L[i]=st,R[i]=ed;
		if(ed<a[i])sum+=a[i]-ed,b[i+1]=a[i]-ed,ed=a[i];
		else b[i+1]=0;
	}
//	printf("!%lld\n",len);
//	for(int i=1;i<=m;i++)printf("%d %d\n",L[i],R[i]);
	for(int i=1; i<=m; i++) {
		sum-=b[i];
		L[i]+=sum,R[i]+=sum;
		if(L[i]>a[i]||R[i]<a[i])return 0;
	}
	if(ed<n||L[1]>1) {
		long long xx=n-ed+L[1]-1;
		if(R[m]-L[m]+1<len) {
			xx-=len-(R[m]-L[m]+1);
			if(xx<=0)return 1;
			R[m]=L[m]+len-1;
		}
		for(int i=1; i<=m; i++) {
			L[i]-=xx;
//			if(i>1&&L[i]<=a[i-1])return 0;
			if(R[i]-L[i]+1>len) {
				long long y=R[i]-L[i]+1-len;
				R[i]-=y,xx=y;
				if(R[i]<a[i])return 0;
			} else {
				xx=0;
				break;
			}
		}
		if(xx)return 0;
	}
	return 1;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	cin>>n>>m;
	for(i=1; i<=m; i++)cin>>a[i];
	l=1,r=n;
	a[m+1]=n+1;
	while(l<=r) {
		mid=l+r>>1;
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}