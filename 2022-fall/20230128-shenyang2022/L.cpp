#include<bits/stdc++.h>
using namespace std;
int n[2],i,a[2][10],b[2][10],c[2][10];
double ans[3];
void dfs(int x,double v) {
	int mi=1e9,id;
	int f=0;
	for(int i=1; i<=n[x]; i++)
		if(a[x][i]>0) {
			if(mi>c[x][i])id=i,mi=c[x][i];
			f++;
		}
	int fl=0;
	for(int i=1; i<=n[!x]; i++)if(a[!x][i]>0)fl++;
//	printf("%.10f %d %d %d\n",v,x,f,fl);
	if(!f) {
		if(fl)ans[!x]+=v;
		else ans[2]+=v;
		return;
	}
	if(!fl){
		ans[x]+=v;
		return;
	}
	c[x][id]++;
	for(int i=1; i<=n[!x]; i++)
		if(a[!x][i]>0) {
			a[!x][i]-=b[x][id],a[x][id]-=b[!x][i],dfs(!x,v/fl),a[!x][i]+=b[x][id],a[x][id]+=b[!x][i];
		}
	c[x][id]--;
}
int main() {
	scanf("%d%d",&n[0],&n[1]);
	for(i=1; i<=n[0]; i++)scanf("%d",&a[0][i]),b[0][i]=a[0][i];
	for(i=1; i<=n[1]; i++)scanf("%d",&a[1][i]),b[1][i]=a[1][i];
	if(n[0]>n[1])dfs(0,1);
	else if(n[0]<n[1])dfs(1,1);
	else dfs(0,0.5),dfs(1,0.5);
	printf("%.11f\n%.11f\n%.11f\n",ans[0],ans[1],ans[2]);
	return 0;
}
