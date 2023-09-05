#include<bits/stdc++.h>
using namespace std;
int w,n,i,j,x,si,sz;
char s[20][1005];
struct node {
	char op;
	int a,x;
} a[10000],b[10000];
int main() {
//	scanf("%d%d",&w,&n);
//	for(i=1; i<=n; i++)scanf("%s",s[i]+1);
//	for(i=1; i<=n&&!x; i++) {
//		for(j=1; j<=w&&!x; j++)if(s[i][j]=='#')x=j;
//	}
//	if(x+2>w)x=w-2;
//	if(!x)x=1;
w=7,x=2;
	a[++si]=(node) {
		'T',2,x
	};
	if(w==4) {
		if(x==1)a[++si]=(node) {'T',1,3},a[++si]=(node) {'L',1,1};
		else a[++si]=(node) {'T',3,1},a[++si]=(node) {'J',3,2};
	} else if(w==5&&x==2){
		a[++si]=(node){'Z',1,1},a[++si]=(node){'T',1,4},a[++si]=(node){'S',0,3},a[++si]=(node){'L',1,1};
	}else{
	int lf=0,rf=0;
	for(i=x-1; i>0;) {
		if(i==1) {
			i--,lf=1;
		} else {
			a[++si]=(node) {
				'S',0,i-1
			};
			if(x<=2||i!=x-1)b[++sz]=(node) {
				'S',0,i
			};
			i-=2;
		}
	}
	for(i=x+3; i<=w;) {
		if(i==w) {
			i++,rf=1;
		} else {
			a[++si]=(node) {
				'Z',0,i-1
			};
			if(x>2||i!=x+3)b[++sz]=(node) {
				'Z',0,i-2
			};
			i+=2;
		}
	}
		if(x>2)a[++si]=(node) {'T',2,x-1};
		else a[++si]=(node) {'T',2,x+1};
	for(i=1; i<=sz; i++)a[++si]=b[i];
		if(!lf)a[++si]=(node) {'J',2,1};
		else a[++si]=(node) {'Z',1,1},a[++si]=(node) {'L',1,1};
		if(!rf)a[++si]=(node) {'L',2,w-1};
		else a[++si]=(node) {'S',1,w-1},a[++si]=(node) {'J',3,w-2};
	}
	printf("%d\n",si);
	for(i=1;i<=si;i++)printf("%c %d %d\n",a[i].op,a[i].a,a[i].x);
	return 0;
}