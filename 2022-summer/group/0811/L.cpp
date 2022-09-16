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
#define M 100005
int n,q,i,s[M],op,l,r,x;
long long a[M];
struct tree {
	int l,r,si;
	long long sum,lazy;
} t[M<<2];
void up(int p) {
	t[p].si=t[p<<1].si+t[p<<1|1].si;
	t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}
void build(int l,int r,int p) {
	t[p].l=l,t[p].r=r;
	if(l==r) {
		if(s[l])t[p].sum=a[l],t[p].si=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,p<<1),build(mid+1,r,p<<1|1),up(p);
}
void down(int p){
	if(t[p].lazy){
		t[p<<1].sum+=t[p].lazy*t[p<<1].si,t[p<<1|1].sum+=t[p].lazy*t[p<<1|1].si;
		t[p<<1].lazy+=t[p].lazy,t[p<<1|1].lazy+=t[p].lazy,t[p].lazy=0;
	}
}
void add(int l,int r,int p,int x){
	if(t[p].l==l&&t[p].r==r){
		t[p].sum+=1ll*x*t[p].si,t[p].lazy+=x;
		return;
	}
	down(p);
	int mid=t[p<<1].r;
	if(mid<l)add(l,r,p<<1|1,x);
	else if(mid>=r)add(l,r,p<<1,x);
	else add(l,mid,p<<1,x),add(mid+1,r,p<<1|1,x);
	up(p);
}
void add(int x,int p,int f){
	if(t[p].l==t[p].r){
		if(f)t[p].si++,t[p].sum=a[x];
		else t[p].si--,a[x]=t[p].sum,t[p].sum=0;
		return;
	}
	down(p);
	int mid=t[p<<1].r;
	if(mid<x)add(x,p<<1|1,f);
	else add(x,p<<1,f);
	up(p);
}
long long que(int l,int r,int p){
	if(t[p].l==l&&t[p].r==r)return t[p].sum;
	down(p);
	int mid=t[p<<1].r;
	if(mid<l)return que(l,r,p<<1|1);
	else if(mid>=r)return que(l,r,p<<1);
	else return que(l,mid,p<<1)+que(mid+1,r,p<<1|1);
}
struct Tree {
	long long res[M];
	void add(int x,long long d) {
		while(x<=n)res[x]+=d,x+=x&-x;
	}
	long long sum(int x) {
		long long ans=0;
		while(x)ans+=res[x],x-=x&-x;
		return ans;
	}
} d;
int main() {
	scanf("%d%d",&n,&q);
	for(i=1; i<=n; i++)scanf("%lld",&a[i]);
	for(i=1; i<=n; i++) {
		scanf("%d",&s[i]);
		if(!s[i])d.add(i,a[i]);
	}
	build(1,n,1);
	for(i=1; i<=q; i++) {
//		printf("!!%lld %lld\n",d.sum(n),que(1,n,1));
		scanf("%d",&op);
		if(op==1) {
			scanf("%d",&x),add(x,1,0);
			d.add(x,a[x]);
		} else if(op==2) {
			scanf("%d",&x),d.add(x,-a[x]);
			add(x,1,1);
		} else if(op==3) {
			scanf("%d%d%d",&l,&r,&x),add(l,r,1,x);
		} else scanf("%d%d",&l,&r),printf("%lld\n",que(l,r,1)+d.sum(r)-d.sum(l-1));
	}
	return 0;
}