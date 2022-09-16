#include<bits/stdc++.h>
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod) {
	int r=1;
	for(; y; y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;
	return r;
}
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n;
int a[5];
void change(int x) {
//	printf("!!!%d\n",x);
//	for(int i=0; i<3; i++)printf("%d ",a[i]);
//	puts("");
	int k=a[x];
	for(int i=x; i>0; i--)a[i]=a[i-1];
	a[0]=k;
//	for(int i=0; i<3; i++)printf("%d ",a[i]);
//	puts("");
}
void retur(int x) {
	int k=a[0];
	for(int i=0; i<=x-1; i++)a[i]=a[i+1];
	a[x]=k;
}
int f[6];
void dfs(int x) {
//	for(int i=0; i<3; i++)printf("%d ",a[i]);
//	puts("");
	if(x==10) {
		if(a[0]==1&&a[1]==2&&a[2]==3)f[0]++;
		if(a[0]==1&&a[1]==3&&a[2]==2)f[1]++;
		if(a[0]==2&&a[1]==1&&a[2]==3)f[2]++;
		if(a[0]==2&&a[1]==3&&a[2]==1)f[3]++;
		if(a[0]==3&&a[1]==1&&a[2]==2)f[4]++;
		if(a[0]==3&&a[1]==2&&a[2]==1)f[5]++;
		return;
	}
	for(int i=0; i<4; i++) {
		int k=i<3?i:0,g;
		for(g=0;g<3;g++)if(a[g]==k+1)break;
		change(g),dfs(x+1),retur(g);
	}
}
int main() {
	a[0]=1,a[1]=2,a[2]=3;
	dfs(0);
	for(int i=0; i<=5; i++)printf("%d ",f[i]);
	return 0;
}