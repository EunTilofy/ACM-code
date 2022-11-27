#include<bits/stdc++.h>
using namespace std;
int a,b,ans;
int main() {
	scanf("%d%d",&a,&b);
	while(a!=b) {
		if(a<b)ans+=b-a,a=b;
		else if(a&1)a++,ans++;
		else a/=2,ans++;
	}
	printf("%d\n",ans);
	return 0;
}