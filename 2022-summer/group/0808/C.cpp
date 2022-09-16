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
bool cur1;
#define M 1000005
struct Tree {
	int l,r,lazy,mi;
} t[M<<2];
void build(int l,int r,int p) {
	t[p].l=l,t[p].r=r,t[p].mi=t[p].lazy=1e9;
	if(l==r)return;
	int mid=l+r>>1;
	build(l,mid,p<<1),build(mid+1,r,p<<1|1);
}
void up(int p) {
	t[p].mi=min(t[p<<1].mi,t[p<<1|1].mi);
}
void down(int p) {
	if(t[p].lazy<1e9) {
		t[p<<1].lazy=min(t[p].lazy,t[p<<1].lazy);
		t[p<<1|1].lazy=min(t[p].lazy,t[p<<1|1].lazy);
		t[p<<1].mi=min(t[p].lazy,t[p<<1].mi);
		t[p<<1|1].mi=min(t[p].lazy,t[p<<1|1].mi);
		t[p].lazy=1e9;
	}
}
void add(int l,int r,int p,int x) {
//	printf("!%d %d %d %d\n",l,r,p,x);
	if(t[p].l==l&&t[p].r==r) {
		t[p].mi=min(t[p].mi,x),t[p].lazy=min(t[p].lazy,x);
		return;
	}
	down(p);
	int mid=t[p<<1].r;
	if(l>mid)add(l,r,p<<1|1,x);
	else if(r<=mid)add(l,r,p<<1,x);
	else add(l,mid,p<<1,x),add(mid+1,r,p<<1|1,x);
	up(p);
}
int que(int l,int r,int p) {
//	printf("!!%d %d %d\n",l,r,p);
	if(t[p].l==l&&t[p].r==r)return t[p].mi;
	down(p);
	int mid=t[p<<1].r;
	if(l>mid)return que(l,r,p<<1|1);
	else if(r<=mid)return que(l,r,p<<1);
	else return min(que(l,mid,p<<1),que(mid+1,r,p<<1|1));
}
int n,m,l,e,f,i,x,y;
bool cur2;
int main() {
//	printf("%.10f",((&cur2)-(&cur1))/1024.0/1024);
	n=read(),m=read(),build(1,n*m,1);
	for(i=1; i<=m; i++) {
		x=read(),y=read(),l=y-x+1,e=x-1,f=(e==0)?1:-1;
		x=1+(i-1)*n,y=l+(i-1)*n;
//		printf("!%d %d %d %d\n",x,y,l,e);
		for(; y<=i*n; x++,y++) {
			if(i>1)add(x,y,1,que(x-n,y-n,1)+e);
			else add(x,y,1,e);
			e+=f;
			if(e==0)f=1;
		}
	}
	printf("%d\n",que(1+(m-1)*n,n*m,1));
	return 0;
}