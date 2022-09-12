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
#define M 5005
int n,i,j,k,a[M],b[M],cnt,f,si,h[M],sz,id1,id2,l,r;
map<int,int>pos;
void solve(int v,int x) {
	if(x>2) {
		f=1;
		return;
	}
	l=0,r=sz;
	int i;
	for(i=1; i<=si&&l<=r; i++)
		if(pos.count(h[i]-v+h[i])) {
			id1=pos[h[i]],id2=pos[-v+2*h[i]];
//			printf("%d %d %d %d %d %d\n",v,h[i],id1,id2,l,r);
			if(id1<id2) {
				if(r<id1) {
					f=1;
					return;
				}
				if(b[id1+1]!=h[i])l=max(l,id1);
				else l=max(l,id1+1);
			} else {
				if(l>=id1) {
					f=1;
					return;
				}
				r=min(r,id1-1);
			}
		}
	if(l>r) {
		f=1;
		return;
	}
//	printf("!!%d %d\n",l,r);
	for(i=sz; i>r; i--)b[i+x]=b[i],pos[b[i]]=i+x;
	sz+=x;
	b[r+1]=v,pos[v]=r+1;
	if(x==2)b[r+2]=v;
//	for(i=1;i<=sz;i++)printf("!%d ",b[i]);
//	puts("");
}
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1),cnt=1;
	for(i=2; i<=n&&(!f); i++)
		if(a[i]!=a[i-1])solve(a[i-1],cnt),h[++si]=a[i-1],cnt=1;
		else cnt++;
	solve(a[n],cnt);
	if(f)printf("NO\n");
	else {
		printf("YES\n");
		for(i=1; i<n; i++)printf("%d ",b[i]);
		printf("%d\n",b[n]);
	}
	return 0;
}