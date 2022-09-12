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
#define mod 1000000007
inline int qpow(int x,ll y,int m=mod) {
	if(y<0)return 0;
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
long long n,k,l,r,mid,res,w,ans;
int T,i;
int f;
#define M 1000005
vector<long long>a[M];
void init(int x) {
	long long res=0;
	__int128 now=1,sum=0,L=1,R=x,lim=1e18;
	int i;
//	for(i=1;i<=18;i++)lim*=10;
//	printf("!%d\n",x);
	a[x].push_back(0);
	for(i=x; ; i++) {
//		printf("!%d\n",x);
		sum+=now,now=now*R/L,L++,R++;
//		res=(long long)sum;
//		if(x==1)printf("!!%lld ",res);
		if(sum>lim)return;
		res=(long long)sum;
//		if(x==2)printf("!!%lld ",res);
		a[x].push_back(res);
	}
//	if(a[x].size()>100)printf("%d ",x);
}
void find(int x,long long k) {
//	printf("!!%d %lld\n",x,k);
	if(x==2) {
		long long l=0,r=2e9,mid,res=0;
		while(l<=r) {
			mid=(l+r)/2;
			if(mid*(mid+1)/2<k)res=mid+1,l=mid+1;
			else r=mid-1;
		}
//		if((res-1)*res/2>k)printf("!%lld\n",res);
		k-=(res-1)*res/2;
		ans+=qpow(2,res);
		if(ans>=mod)ans-=mod;
		find(x-1,k);
		return;
	}
	if(x==1) {
		ans+=qpow(2,k-1);
		if(ans>=mod)ans-=mod;
		return;
	}
	if(x==0)return;
	int i;
	__int128 now=1,L=1,R=x;
	if(x>=M) {
		for(i=x;; i++) {
//		printf("!!%d %d\n",i,k);
			if(k<=now) {
				ans+=qpow(2,i-1);
				if(ans>=mod)ans-=mod;
				find(x-1,k);
				return;
			} else {
				k-=now,now=now*R/L,L++,R++;
			}
		}
		return;
	}
//	int K=k;
//	if(x>=3&&x<M) {
	int l=0,r=a[x].size()-1,mid,res=0;
//	printf("!%d %d\n",l,r);
	while(l<=r) {
		mid=l+r>>1;
//		printf("!!%d %d %d\n",l,r,mid);
		if(a[x][mid]<k)res=mid,l=mid+1;
		else r=mid-1;
	}
//	printf("%d %d %lld %lld\n",x,res,a[x][res],a[x][res+1]);
	i=res+x;
	k-=a[x][res];
	ans+=qpow(2,i-1);
	if(ans>=mod)ans-=mod;
	find(x-1,k);
//	}
//	k=K;
//	int j=i;
//	long long sum=0;
//	for(i=x;; i++) {
////		printf("!!%d %d\n",i,k);
//		if(k<=now) {
////			ans+=qpow(2,i-1);
////			if(ans>=mod)ans-=mod;
//			if(j!=i)printf("!!%d %d %d %d\n",j,i,sum,a[x][res]);
//			return;
//		} else {
//			sum+=now;
//			k-=now,now=now*R/L,L++,R++;
//		}
//	}
}
void solve(int l,long long k) {//[0,l]
	int i,j;
	__int128 now=1,L=1,R=l+1;
	for(i=0;; i++) {
//		printf("!%d %d %d\n",i,k,now);
		if(k<=now) {
//			printf("!%d %d\n",i,k);
			find(i,k);
			return;
		} else {
			if(R<=0) {
				f=1;
				return;
			}
			k-=now,now=now*R/L,R--,L++;//>long long
		}
	}
}
int main() {
	for(i=3; i<M; i++)init(i);
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%lld",&n,&k),l=res=0,r=2e9,f=0;
		if(n==1) {
			if(k==1)printf("1\n");
			else printf("-1\n");
			continue;
		}
		while(l<=r) {
			mid=l+r>>1;
			if(mid*(mid+1)/2<n)res=mid,l=mid+1;
			else r=mid-1;
		}
		n-=(res+1)*res/2,res++;//len:res
		w=res-n;//[w,res-1]
//		printf("!%d %d %d\n",n,w,res);
		if(w<0||w>=res) {
			printf("-1\n");
			continue;
		}
		if(k<=w) {
			printf("%lld\n",(((qpow(2,res)-qpow(2,w))%mod+mod)%mod+qpow(2,k-2))%mod);
			continue;
		}
		ans=((qpow(2,res)-qpow(2,w))%mod+mod)%mod;
		solve(w-2,k);//mul(2,res)-mul(2,w)
		if(f)printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}