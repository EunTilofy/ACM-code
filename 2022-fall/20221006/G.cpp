#include<bits/stdc++.h>
using namespace std;
#define M 2100
//bool cur1;
int a[M][M],i,j,h,k,n,si,cnt,mx,N;
//int mark[M*M],cnt1;
int main() {
bool cur2;
//	printf("%.10f",((&cur2)-(&cur1))/1024.0/1024);
	scanf("%d",&n),N=1<<n;
	for(i=1; i<=N; i++)a[i][i]=1,a[i*2-1][i*2]=2,a[i*2][i*2-1]=N+1;
	for(cnt=3,i=mx=2; cnt<=N; i++,cnt+=2) {
		si=0;
		for(k=0; k<=N; k+=mx) {
			for(j=1,h=i; j<=mx/2; j++,h=(h-mx/2)%(mx/2)+mx/2+1) {
				a[j*2-1+k][h*2-1+k]=cnt,a[j*2+k][h*2+k]=cnt;
				a[j*2-1+k][h*2+k]=cnt+1,a[j*2+k][h*2-1+k]=cnt+1;
				a[h*2-1+k][j*2-1+k]=cnt+N-1,a[h*2+k][j*2+k]=cnt+N-1;
				a[h*2+k][j*2-1+k]=cnt+N,a[h*2-1+k][j*2+k]=cnt+N;
			}
		}
		if(mx==i)mx*=2;
	}
	for(i=1; i<=N; i++,puts(""))
		for(j=1; j<=N; j++)printf("%d ",a[i][j]);
//	for(i=1; i<=N; i++) {
//		cnt1=0;
//		mark[a[i][i]]=i;
//		for(j=1; j<=N; j++)
//			if(j!=i) {
//				if(mark[a[i][j]]==i)cnt1++;
//				mark[a[i][j]]=i;
//				if(mark[a[j][i]]==i)cnt1++;
//				mark[a[j][i]]=i;
//			}
//		if(cnt1)printf("!");
//	}
	return 0;
}