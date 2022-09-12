#include<bits/stdc++.h>
using namespace std;
#define M 1005
int n,m,q,i,j,op,r,c,y,l,mid,res,f;
long long sum[M][M],a[M][M],z;
void add(int i,int x,int d) {
	while(x<=m)sum[i][x]+=d,x+=x&-x;
}
long long que(int i,int x) {
	long long ans=0;
	while(x)ans+=sum[i][x],x-=x&-x;
	return ans;
}
int main() {
	scanf("%d%d",&n,&m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)scanf("%lld",&a[i][j]);
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&op);
		if(op==1) {
			scanf("%d",&y),f=0;
//			printf("!%d %d %d\n",quen(2),quem(3),a[2][3]+quen(2)-quem(3));
			for(i=1; i<=n&&!f; i++) {
				l=res=1,r=m;
				while(l<=r) {
					mid=l+r>>1;
					if(a[i][mid]+que(i,mid)<=y)res=mid,l=mid+1;
					else r=mid-1;
				}
//				printf("%d\n",res);
				if(a[i][res]+que(i,res)==y)f=1;
			}
			if(f)printf("1\n");
			else printf("0\n");
		} else {
			scanf("%d%d%d",&r,&c,&y);
			for(i=r; i<=n; i++)add(i,c,y);
//			printf("!!%d %d %d\n",quen(2),quem(3),a[2][3]+quen(2)-quem(3));
		}
	}
	return 0;
}
