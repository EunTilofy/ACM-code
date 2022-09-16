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
#define M 200005
int n,q,i,op,l,r;
struct Tree {
	int sum[M];
	void add(int x,int d) {
		while(x<=n)sum[x]+=d,x+=x&-x;
	}
	int que(int x) {
		int ans=0;
		while(x)ans+=sum[x],x-=x&-x;
		return ans;
	}
} a,b;
struct node {
	int x,y;
} c,d;
node query(int x) {
	node s;
	s.x=x,s.y=0;
	int res=a.que(x)+b.que(x)*x;
	s.x-=res,s.y+=res;
	return s;
}
int main() {
	scanf("%d%d",&n,&q);
	for(i=1; i<=q; i++) {
		scanf("%d",&op);
		if(op==1) {
			scanf("%d%d",&l,&r);
			c=query(l),d=query(r);
			if(c.x==d.x) {
				a.add(l,l),a.add(r+1,-l),b.add(l,-1),b.add(r+1,1);
			}else {
				a.add(l,-l),a.add(r+1,l),b.add(l,1),b.add(r+1,-1);
			}
		} else {
			scanf("%d",&l),c=query(l),printf("%d %d\n",c.x,c.y);
		}
	}
	return 0;
}