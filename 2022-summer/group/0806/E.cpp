#include<bits/stdc++.h>
#define db double
#define int long long
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
int T,si[2],i,j,e,sz;
long long k,ll,rr,l,r,a[2][80],c[80],now,mx,mi,ans;
void divide(int f,long long l) {
	memset(a[f],0,sizeof(a[f]));
	long long x=l;
	while(x)x/=k,si[f]++;
	int i=0;
	while(l)a[f][si[f]-i]=l%k,l/=k,i++;
}
long long calc() {
	long long ans=0;
	for(int i=1; i<=si[1]; i++)ans*=k,ans+=c[i];
	return ans;
}
void dfs(int x,long long now,int up, int lim) {
	if(x==si[1]+1) {
		long long z=calc();
		now+=si[1];
//		printf("%lld %lld %d\n",now,z,si[1]);
//		for(int i=1; i<=si[1]; i++)printf("!%lld ",c[i]);
//		puts("");
//		for(int i=si[1];i>0&&!c[i];i--)now--;
		if(now>ans) {
			ans=now,mx=mi=z;
		} else if(now==ans) {
			if(mx<z)mx=z;
			if(mi>z)mi=z;
		}
		return;
	}
	if(up) {
		if(lim && a[1][x])c[x]=a[1][x]-1,dfs(x+1,now+(a[1][x]-1),0, lim);
		c[x]=a[1][x];
        if(!lim) {
            if(a[1][x] > a[0][x]) dfs(x + 1, now + a[1][x], 1, 1);
            else dfs(x + 1, now + a[1][x], 1, 0);
        }
        else dfs(x + 1, now + a[1][x], 1, 1);
	} else c[x]=k-1,dfs(x+1,now+k-1,0, 1);
}
signed main() {
	scanf("%lld",&T);
	for(e=1; e<=T; e++) {
		scanf("%lld%lld%lld",&k,&l,&r),si[0]=si[1]=mx=mi=ans=0;
		divide(0,l),divide(1,r);
		if(si[0]<si[1]) {
			ans=si[1]-1;
			for(i=1; i<=si[1]-1; i++)mi*=k,mi+=k-1,ans+=k-1;
//			printf("!!%lld %lld\n",mi,ans);
			mx=mi,memset(a[0],0,sizeof(a[0])),a[0][1]=1;
		}
		dfs(1,0,1,0);
		printf("Case #%lld: %lld %lld %lld\n",e,ans-2,mi,mx);
	}
	return 0;
}