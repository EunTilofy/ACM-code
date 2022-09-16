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
char a[1005];
int l,i,r,d;
long long ans,mx;
int main() {
	scanf("%s",a);
	l=strlen(a);
	printf("%d\n",l),ans=1;
	for(i=0; i<l; i++) {
		if(a[i]=='D')ans*=2,d++;
		else if(a[i]=='R')ans+=2,r++;
		else if(a[i]=='L') {
			if(ans<=1)printf("-1");
			ans-=2,r--;
		} else {
			if(ans&1)printf("-1");
			ans/=2,d--;
		}
		mx=max(mx,ans);
	}
	printf("%d %d\n",r,d);
	printf("%lld\n",mx);
	printf("%lld\n",ans);
}