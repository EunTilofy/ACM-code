#include<bits/stdc++.h>
using namespace std;
int find(int k) {
	int up=sqrt(k);
	int b[1005],si=0;
	for(int i=1; i<=up; i++)
		if(k%i==0) {
			b[++si]=i,b[++si]=k/i;
		}
	return b[rand()%si+1];
}
int main() {
	srand(time(NULL));
//	int n=rand()%1000+5;
//	int a[1005];
////	printf("%d\n",n);
//	int sum=rand()%1000*1000000+rand()%1000*1000+rand()%1000+1;
	int n=rand()%50+1;
	int a[1005];
	int sum=rand()%1000+1;

	for(int i=1; i<=n; i++) {
		int x;
		if(sum>1) {
			x=find(sum);
//			printf("!!%d %d\n",sum,x);
			sum/=x;
		} else x=1;
		a[i]=x;
	}
	int w[1000];
	for(int i=0; i<n-1; i++)w[i]=i+1;
	for(int i=1; i<n-1; i++)swap(w[i],w[rand()%i]);
	for(int i=n-1; i>0; i--)w[i]=w[i-1];
//	for(int i=1; i<=n; i++)printf("%d ",a[i]);
//	puts("");
//	for(int i=1; i<n; i++)printf("%d ",w[i]);
	sum=0;
	int i;
	for(i=1; i<=n; i++)sum+=a[i];
	int si=n;
	printf("%d\n%lld\n",n,sum);
	for(i=1; i<n; i++) {
//			printf("!%d ",w[i]);
		sum+=a[w[i]]*a[w[i]+1]-a[w[i]]-a[w[i]+1];
		a[w[i]]=a[w[i]]*a[w[i]+1];
		for(int j=w[i]+1; j<si; j++)a[j]=a[j+1];
		for(int j=i+1; j<n; j++)if(w[j]>w[i])w[j]--;
		si--;
		printf("%lld\n",sum);
	}
	return 0;
}