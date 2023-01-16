#include<bits/stdc++.h>
using namespace std;
#define M 1000005
int n,a,b,d[M],c[M],i,j,l1,l2,r1,r2;

bool cmp(int D, int C) {
	if(a==0||b==0) {
		if(a==0&&(D>0||C>b)) return false;
		if(b==0&&(C>0||D>a)) return false;
	} else {
		l1=D/a+(D%a>0)-1,r1=D+1,l2=C/b+(C%b>0),r2=C;
		if(l1<=l2&&l2<=r1||l1<=r2&&r2<=r1) return true;
		return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>a>>b;
	for(i=1; i<=n; i++)cin>>d[i];
	for(i=1; i<=n; i++)cin>>c[i];
	for(i=1; i<=n; i++) {
		
	}
	return 0;
}