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
int T,n,k,i,si,a[65];
long long now,ans[65], bit[65];
bool chk(long long now) {
	for(int i = 0; i < n; ++i) bit[i] = 0;
	for(int i = 1; i <= si; ++i) {
		ll pos = ans[i];
		for(int j = n - 1; j >= 0; --j) {
			if((pos >> j) & 1) {
				if(!bit[j]) {
					bit[j] = pos;
					break;
				} else pos ^= bit[j];
			}
		}
	}
	ll tmp = 0;
	for(int i = n - 1; i >= 0; --i) {
		if(((now >> i) & 1) != ((tmp >> i) & 1)) {
			tmp ^= bit[i];
		}
	}
	return tmp != now;
}
bool fl;
void dfs(int x,int len) {
	if(si==n)return;
	if(fl&&i>1)return;
	if(x==i) {
		now=0;
		for(int j=1; j<=len; j++)now<<=1,now|=a[j];
		if(chk(now))fl=1,ans[++si]=now;//,printf("%d %d %lld\n",si,x,now);
		return;
	}
	int h=1,j,ct=1;
	for(j=len; j>0&&a[j]; j--)a[j+1]=a[j],ct++;
	a[j+1]=0,h=j+1;
	if(h==1)a[h]=a[h+1],a[h+1]=0,h++,ct--;
	for(j=1; j<=ct; j++) {
		dfs(x+1,len+1);
		a[h]=a[h+1],a[h+1]=0,h++;
	}
}
int main() {
	scanf("%d",&T);
	while(T--) {
//	for(n=1; n<=62; n++)
//		for(k=1; k<=n; k++){
//	printf("!%d %d\n",n,k);
		scanf("%d%d",&n,&k);
		if(k%2==0)printf("-1\n");
		else {
			si=0;
			for(i=1; i<=k; i++)a[i]=1;
			for(i=0; si<n&&i+k<=n; i++)fl=0,dfs(0,k);
			if(si<n)printf("-1\n");
			else {
				for(i=1; i<=si; i++)printf("%lld ",ans[i]);
				puts("");
			}
		}
	}
	return 0;
}