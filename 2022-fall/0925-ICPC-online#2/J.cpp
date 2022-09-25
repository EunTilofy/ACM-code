#include<bits/stdc++.h>
using namespace std;
#define M 100005
int n,i,a[M],st[M],ed[M],l,r,f,fl,x;
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	ed[1]=1;
	for(i=2; i<=n; i++)
		if(a[i-1]>a[i])ed[i]=ed[i-1]+1;
		else ed[i]=1;
	st[n]=1;
	for(i=n-1; i>0; i--)
		if(a[i]<a[i+1])st[i]=st[i+1]+1;
		else st[i]=1;
	l=1,r=n;
	while(l<=r) {
		fl=!fl;
		if(x>=a[l]) {
			if(ed[r]&1)f=fl;
			else f=!fl;
			break;
		}
		if(x>=a[r]) {
			if(st[l]&1)f=fl;
			else f=!fl;
			break;
		}
		if(a[l]==a[r]) {
			if(ed[r]&1||st[l]&1)f=fl;
			else f=!fl;
			break;
		} else if(a[l]>a[r]) {
			if(st[l]&1) {
				f=fl;
				break;
			} else x=a[r],r--;
		} else if(ed[r]&1) {
			f=fl;
			break;
		} else x=a[l],l++;
		if(l>r)f=fl;
//		printf("%d %d\n",l,r);
	}
	if(f)printf("Alice");
	else printf("Bob");
	return 0;
}