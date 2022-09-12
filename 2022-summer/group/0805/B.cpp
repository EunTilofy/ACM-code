#include<bits/stdc++.h>
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
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353

bool cur1;
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
long long n,a[M],i,j,k,h,b[M],rt,res,num[M],si;
long long nowl,nowr,ll,rr,mid,as[M];
struct Tree {
	long long sum[M];
	void clear() {
		memset(sum,0,sizeof(sum));
	}
	void add(int x,int d) {
		while(x<=n)sum[x]+=d,x+=x&-x;
	}
	long long que(int x) {
		long long res=0;
		while(x)res+=sum[x],x-=x&-x;
		return res;
	}
} l,ans;
struct Tree2 {
	int rt[M],ls[M*20],rs[M*20];
    long long sum[M*20],tot;
	void add(int l,int r,int od,int &p,int x) {
		p=++tot,sum[p]=sum[od]+1,ls[p]=ls[od],rs[p]=rs[od];
//		printf("%d %d %d %d\n",i,l,r,sum[p]);
		if(l==r)return;
		int mid=l+r>>1;
		if(mid>=x)add(l,mid,ls[od],ls[p],x);
		else add(mid+1,r,rs[od],rs[p],x);
	}
	int quel(int l,int r,int r1,int r2,int k) { //(r1,r2] <k
//		printf("%d %d %d %d %d %d %d %d %d %d\n",l,r,sum[ls[r1]],sum[ls[r2]],sum[r1],sum[r2],ls[r1],ls[r2],r1,r2);
		if(l==r)return sum[r2]-sum[r1];
		int mid=l+r>>1;
//		printf("!!%d %d %d %d\n",l,r,b[mid],k);
		if(mid>=k)return quel(l,mid,ls[r1],ls[r2],k);
//		printf("%d %d %d %d\n",l,r,sum[ls[r2]]-sum[ls[r1]],quel(mid+1,r,rs[r1],rs[r2],k));
		return sum[ls[r2]]-sum[ls[r1]]+quel(mid+1,r,rs[r1],rs[r2],k);
	}
	void build(int l,int r,int &p) {
		p = ++tot, sum[p] = 0;
		if(l == r) return ;
		int mid = (l + r) >> 1;
		build(l, mid, ls[p]), build(mid + 1, r, rs[p]);
	}
} s1,s2;
bool chkl(int x) {
	return s1.quel(1,n,s1.rt[i],s1.rt[x],a[i])>=nowl;
}
bool chkr(int x) {
	return x-i-s1.quel(1,n,s1.rt[i],s1.rt[x],a[i])>=nowl;
}
struct node {
	int w,a;
	bool operator<(const node&_)const {
		return _.w>w;
	}
} w[M];
bool cur2;
int main() {
//	printf("%.10f",((&cur2)-(&cur1))/1024.0/1024);
    n = read();
	for(i=1; i<=n; i++) a[i] = read(),b[i]=a[i];
	sort(b+1,b+n+1);
	for(i=1; i<=n; i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b,num[a[i]]=i;
	s1.build(1,n,s1.rt[0]);
	for(i=1; i<=n; i++)s1.add(1,n,s1.rt[i-1],s1.rt[i],a[i]);
	//min
//	printf("!!!!%d\n",s1.quel(1,n,s1.rt[4],s1.rt[6],a[4]));
	for(i=1; i<=n; i++) {
		nowl=l.que(a[i]),l.add(a[i],1),ll=i,rr=n,res=n+1;
//		printf("!!%d %d\n",a[i],nowl);
		while(ll<=rr) {
			mid=ll+rr>>1;
			if(chkl(mid))res=mid,rr=mid-1;
			else ll=mid+1;
		}
		w[i].w=res,ans.add(res,nowl),w[i].a=a[i];
//		printf("%d %d %d %lld\n",i,res,s1.quel(1,n,s1.rt[i],s1.rt[res],a[i]),nowl);
//		printf("%d %d\n",i,res);
	}
	sort(w+1,w+n+1),j=1;
	l.clear(),nowl=si=0;
	for(i=1; i<=n; i++) {
		nowl+=si-l.que(a[i]),l.add(a[i],1),si++,as[i]=nowl;//,nowl-=ans.que(i);
		while(w[j].w==i)l.add(w[j].a,-1),j++,si--;
//		printf("%d %d %lld\n",i,j,as[i]);
	}
	//max
	l.clear(),nowl=0,ans.clear();
	for(i=1; i<=n; i++) {
		nowl=i-1-l.que(a[i]),l.add(a[i],1),ll=i,rr=n,res=n+1;
		while(ll<=rr) {
			mid=ll+rr>>1;
			if(chkr(mid))res=mid,rr=mid-1;
			else ll=mid+1;
		}
		w[i].w=res,ans.add(res,nowl),w[i].a=a[i];
//		printf("%d %d %d %lld\n",i,res,res-i-s1.quel(1,n,s1.rt[i],s1.rt[res],a[i]),nowl);
	}
	sort(w+1,w+n+1),j=1;
	l.clear(),nowl=0;
	for(i=1; i<=n; i++) {
		nowl+=l.que(a[i]),l.add(a[i],1),as[i]=min(as[i],nowl);//,nowl-=ans.que(i);
		while(w[j].w==i)l.add(w[j].a,-1),j++;
//		printf("%d %d %lld\n",i,j,nowl);
		printf("%lld\n",as[i]);
	}
	return 0;
}
