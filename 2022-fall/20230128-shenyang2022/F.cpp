#include<bits/stdc++.h>
using namespace std;
int T,i,n,m,ans[1000005];
long long a[1000005];
void putno() {
	puts("No");
}
void solve() {
	if(1ll*n*(n+1)*m*(m+1)%8) {
		putno();
		return;
	}
	int f=0;
	if(1ll*(n+1)*n%4)swap(n,m),f=1;
	vector<int>b;
	int i=n+1;
	long long sum=1ll*n*(n+1)/4-n;
	long long cnt=0;
	while(sum) {
		while(a[i]>sum)i--;
		int v=sum/a[i];
		for(int j=1; j<=v; j++)b.push_back(i+1),cnt+=i+1;
		sum%=a[i];
	}
	for(int j=1; j<=n-cnt; j++)b.push_back(1);
	puts("Yes");
	if(f) {
		swap(n,m);
		int now=1;
		int h=1;
		for(int j=0; j<b.size(); j++,now=!now) {
			for(int k=1; k<=b[j]; k++)ans[h++]=now;
		}
		for(int j=1; j<=n; j++) {
			for(h=1; h<m; h++)printf("%d ",ans[h]);
			printf("%d\n",ans[m]);
		}
	} else {
		int now=1;
		for(int j=0; j<b.size(); j++,now=!now) {
			for(int k=1; k<=b[j]; k++) {
				for(int h=1; h<m; h++)printf("%d ",now);
				printf("%d\n",now);
			}
		}
	}
}
int main() {
	for(i=1; i<=1000001; i++)a[i]=1ll*i*(i+1)/2;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		solve();
	}
	return 0;
}
