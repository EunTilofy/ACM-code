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
//	return 1;
}
void dfs(int x, int len) {
	if(si == n || x < 0 || len < 0) return ;
	if(x == len) {
		ll pos = 0;
		for(int i = 0; i < x; ++i) pos += (1ll << i);
		for(int i = x; i < n; ++i) if(a[i]) pos += (1ll << i);
		if(chk(pos))
			ans[++si] = pos;
		return ;
	} else if(x < len) return ;
	if(!len) {
		ll pos = 0;
		for(int i = x; i < n; ++i) if(a[i]) pos += (1ll << i);
		if(chk(pos))
			ans[++si] = pos;
		return ;
	}
	a[x - 1] = 0;
	dfs(x - 1, len);
	a[x - 1] = 1;
	dfs(x - 1, len - 1);
}
//map<long long,int>pos;
//void dfs(int x,int len) {
//	if(si==n)return;
////	if(pos[now])return;
////	pos[now]=1;
////	printf("%d %d %d %d\n",x-1,k,len,n);
//	if(x>n+1)return;
//	if(x+k-len==n+1) {
//		now=0;
//		for(int j=1; j<=n; j++)now<<=1,now|=a[j];
//		if(chk(now))ans[++si]=now;
////		printf("!!!%d %d %lld %d\n",x,len,now,si);
//		return;
//	}
//	a[x]=0;
//	dfs(x+1,len);
//	a[x]=1;
//	dfs(x+1,len+1);
////	for(int j=len; j>0; j--)a[j+1]=a[j];
////	a[1]=0;
////	int h=1;
////	for(int j=1; j<=k; j++) {
////		while(!a[h+1])a[h]=a[h+1],h++;
////		a[h]=a[h+1],a[h+1]=0,h++;
//////		printf("%d %d %d\n",x,len,h);
//////		for(int s=1; s<=len+1; s++)printf("%d",a[s]);
//////		puts("");
////		dfs(x+1,len+1);
////	}
//}
int main() {
//	scanf("%d",&T);
//	while(T--) {
	for(n=1; n<=62; n++)
		for(k=1; k<=n; k+=2) {
			printf("!%d %d\n",n,k);
//	scanf("%d%d",&n,&k);
//	if(!(k&1))printf("-1\n");
//	else {
			si=0;
			for(i=1; i<=n; i++)a[i]=1;
			dfs(n,k);
//		for(i=0; si<n&&i+k<=n; i++)pos.clear(),dfs(0,k);
			if(si<n)printf("-1\n");
			else {
				for(i=1; i<=si; i++)printf("%lld ",ans[i]);
				puts("");
			}
		}
	return 0;
}