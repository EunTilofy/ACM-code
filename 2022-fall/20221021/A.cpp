#include<bits/stdc++.h>
using namespace std;
int a[5],b[5],i,j,f,k,T,e;
int main() {
	scanf("%d",&T);
	for(e=1; e<=T; e++) {
		f=0;
		for(i=0; i<4; i++)scanf("%d",&a[i]);
		swap(a[2],a[3]);
		for(i=0; i<4; i++)scanf("%d",&b[i]);
		swap(b[2],b[3]);
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				if(a[i]==b[j]) {
					for(k=0; k<4; k++)if(a[(i+k)%4]!=b[(j+k)%4])break;
					if(k==4) {
						f=1;
						break;
					}
				}
		printf("Case #%d: ",e);
		if(f)printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}