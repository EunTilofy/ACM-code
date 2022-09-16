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
int T,i,n,m,Q,fa[M],si[M],fx,fy,v[M],sz;
long long ans[M],now;
struct node {
	int x,y,k;
	bool operator<(const node&_)const {
		return _.k<k;
	}
} t[M];
int getfa(int x){
	return fa[x]==x?fa[x]:fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	now+=1ll*si[x]*si[y];
	fa[x]=y,si[y]+=si[x],si[x]=0;
}
int find(int x){
	int l=1,r=sz,mid,res=0;
	while(l<=r){
		mid=l+r>>1;
		if(v[mid]<x)r=mid-1;
		else l=mid+1,res=mid;
	}
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&Q);
		for(i=1;i<=m;i++)scanf("%d%d%d",&t[i].x,&t[i].y,&t[i].k);
		for(i=1;i<=n;i++)fa[i]=i,si[i]=1;
		sort(t+1,t+m+1),now=sz=0;
		for(i=1;i<=m;i++){
			fx=getfa(t[i].x),fy=getfa(t[i].y);
			if(fx!=fy)merge(fx,fy);
			if(t[i].k!=t[i+1].k)ans[++sz]=now,v[sz]=t[i].k;
//			printf("%d %d %d %d\n",i,sz,ans[sz],v[sz]);
		}
		for(i=1;i<=Q;i++){
			scanf("%d",&fx);
			printf("%lld\n",ans[find(fx)]);
		}
	}
	return 0;
}
/*
2
5 5 3
1 2 2
2 3 3
3 4 1
4 5 1
5 1 3
3
2
1
5 5 5
1 2 2
2 3 3
3 4 1
4 5 1
5 1 3
4
3
2
1
0
*/