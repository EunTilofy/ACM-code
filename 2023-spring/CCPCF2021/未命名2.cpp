#include<bits/stdc++.h>
using namespace std;
#define M 200005
long long n,ans,res,p[M],x,y,now;
int m,i;
void solve(long long a,long long b) {
	long long s=b-a;
	if(s>x)ans++,s-=x+1,now+=x+1;
	if(!s) {
		now=p[i]+1;
		return;
	}
	if(i==m+1)return;
	long long t=y-s;
	if(p[i+1]-p[i]-1<=t||t>=x) {
		now=p[i]+1;
		return;
	}
	if(t<x) {
		ans--;
		return;
	}
}
int main() {
	scanf("%lld%d%lld%lld",&n,&m,&x,&y);
	for(i=1; i<=m; i++)scanf("%lld",&p[i]);
	now=1,p[m+1]=n+1;
	for(i=1; i<=m+1; i++) {
		if(n-now+1<=x)break;
		res=(p[i]-now)/(y+2);
		now+=res*(y+2),ans+=res*2;
		solve(now,p[i]);
	}
	printf("%lld\n",ans);
	return 0;
}