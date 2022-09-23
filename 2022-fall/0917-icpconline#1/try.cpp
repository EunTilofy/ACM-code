#include<bits/stdc++.h>
using namespace std;
int T,a,y,x,i,l,v1,v0,ans,b[35],cnt;
bool chk(int x) {
	l=0;
	while(x)l++,b[l]=x&1,x>>=1;
	v1=v0=0;
	for(int i=1; i<=l; i++) {
		v1+=b[i];
		if(!v1)v0++;
	}
	if(v1==v0)return 1;
	return 0;
}
int main() {
	freopen("data2.txt","w",stdout);
	int mx=0,la=0,id1,id2;
	int cnt=0;
	for(i=1; i<=4e8; i++) {
		if(chk(i)) {
			printf("%d,",i);
			if(la&&i-la>mx)mx=max(i-la,mx),id1=la,id2=i;
			if(i-la>1000)cnt++;
			la=i;
		}
	}
	printf("%d\n",cnt);
//	printf("%d %d %d\n",mx,id1,id2);
	return 0;
}
/*
20480 67080192 67100672
24580 134193152 134217732
40960 268378112 268419072
24704 398434304 398459008
49168 939474944 939524112
*/