#include<bits/stdc++.h>
using namespace std;
#define P 1000000007
#define M 100005
int mul(int x,int y) {
	int ans=1;
	while(y) {
		if(y&1)ans=1ll*ans*x%P;
		x=1ll*x*x%P,y>>=1;
	}
	return ans;
}
int n,m,c,i,j,a,mx,r[M],sir,l[M],sil,cntr,cntl;
bool markr[M],markl[M];
int main() {
	scanf("%d%d%d",&n,&m,&c);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++) {
			scanf("%d",&a);
			if(a>mx)r[sir=1]=i,l[sil=1]=j,mx=a;
			else if(a==mx)r[++sir]=i,l[++sil]=j;
		}
	for(i=1; i<=sir; i++)if(!markr[r[i]])markr[r[i]]=1,cntr++;
	for(i=1; i<=sil; i++)if(!markl[l[i]])markl[l[i]]=1,cntl++;
//	printf("%d %d\n",cntr,cntl);
	printf("%lld\n",((1ll*mul(c-mx+1,cntr)+mul(c-mx+1,cntl)-1)%P+P)%P);
	return 0;
}
