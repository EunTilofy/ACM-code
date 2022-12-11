#include<bits/stdc++.h>
using namespace std;
int n,k,now,res,i,a,id;
int main() {
	scanf("%d%d",&n,&k);
	for(i=1; i<=n; i++) {
		scanf("%d",&a);
		if(i==1)res=a,id=1;
		else {
			if(a>res)id=i,res=a,now=1;
			else now++;
		}
		if(now==k)break;
	}
	printf("%d\n",id);
	return 0;
}