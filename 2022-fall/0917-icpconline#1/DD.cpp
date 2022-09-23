#include<bits/stdc++.h>
using namespace std;
int T,a,y,x,i,l1,l2,v1,v2,ans,b[35],cnt;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&a,&y),ans=-1;
		l1=l2=0;
		x=a;
		while(x)l1++,b[l1]=x&1,printf("%d",x&1),x>>=1;
		puts("");
		x=y;
		while(x)l2++,printf("%d",x&1),x>>=1;
		puts("");
		if(l1==l2) {
			if(!(l1&1)) {
				v2=l1/2;
				for(i=1; i<=l1; i++)cnt+=b[i];
				if(cnt>v2) {
					for(i=1; i<=l1; i++) {
						cnt-=b[i];
						if(!b[i]&&cnt<=v2) {
							b[i]=1;
							break;
						}
						b[i]=0;
					}
				}
				for(i=1; i<=l1&&cnt<v2; i++) {
					if(!b[i])b[i]=1,cnt++;
				}
				v1=0;
				for(i=1; i<=l1; i++)v1<<=1,v1+=b[i];
				if(a<=v1&&v1<=y)ans=v1;
			}
		} else if(!(l1&1)) {
			v1=0;
			for(i=1; i<=l1/2; i++)v1<<=1,v1++;
			for(i=1; i<=l1/2; i++)v1<<=1;
			if(a<=v1&&v1<=y)ans=v1;
		} else if(l1+1<=l2) {
			v1=1;
			for(i=1; i<=(l1+1)/2; i++)v1<<=1;
			for(i=1; i<=l1/2; i++)v1<<=1,v1++;
			if(a<=v1&&v1<=y)ans=v1;
		}
		printf("%d %d\n",v1,ans);
	}
	return 0;
}