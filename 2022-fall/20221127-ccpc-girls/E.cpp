#include<bits/stdc++.h>
using namespace std;
#define M 100005
int T,i,j,x,t,k,n,d,a[M],now,sum,fl,mx;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>T;
	while(T--) {
		cin>>x>>t>>k>>n>>d,sum=fl=now=mx=0;
		for(i=1; i<=n; i++) {
			cin>>a[i];
			a[i]=((a[i]<=d)?-1:1);
			sum+=a[i];
			mx=max(sum,mx);
			if(x+sum<=k)now++;
			else now=0;
			if(now==t)fl=1;
		}
		if(fl)printf("YES\n");
		else if(sum>0) {
			printf("NO\n");
		} else if(sum==0) {
			if(x+mx<=k)printf("YES\n");
			else {
				for(i=1; i<=n; i++) {
					sum+=a[i];
					mx=max(sum,mx);
					if(x+sum<=k)now++;
					else now=0;
					if(now==t) {
						fl=1;
						break;
					}
				}
				if(fl)printf("YES\n");
				else printf("NO\n");
			}
		} else {
			printf("YES\n");
		}
	}
	return 0;
}