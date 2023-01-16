#include<bits/stdc++.h>
using namespace std;
double a[6],k;
int t,m,s,h,i;
const double eps=1e-7;
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&m,&s,&h);
		a[1]=h,a[2]=h,a[3]=m*3-h*2;
		k=5.0*s*s+m*m*3-a[1]*a[1]-a[2]*a[2]-a[3]*a[3];
		k/=2,k=sqrt(k),a[4]=k+m,a[5]=m-k;
		sort(a+1,a+5+1);
		if(fabs(a[3]-h)>eps)printf("-1\n");
		else if(a[1]<-eps||a[5]>100+eps)printf("-1\n");
		else {
			for(i=1; i<=5; i++)printf("%.8f ",a[i]);
			puts("");
		}
	}
	return 0;
}