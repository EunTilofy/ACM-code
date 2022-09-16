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
int i,n,a[M],x,y,id[M],sl[M],sil,sir,sr[M];
vector<int>b[M];
bool fl,mark[M];
void dfs(int x,int f) {
	int Sil=sil,Sir=sir,v=0;
	if(x!=1) {
		if(!sil&&!sir) {
			if(a[1]>a[x])sl[++sil]=1,sl[++sil]=x,mark[1]=1;
			else sr[++sir]=1,sr[++sir]=x,mark[1]=1;
		} else if(sir&&a[sr[sir]]<a[x])mark[sr[sir]]=1,sr[++sir]=x;
		else if(sil&&a[sl[sil]]>a[x])mark[sl[sil]]=1,sl[++sil]=x;
		else if(!sir) {
			if(!mark[sl[sil]]) {
				v=sr[++sir]=sl[sil],sil--;
				mark[v]=1;
			}
			sr[++sir]=x;
		} else if(!sil) {
			if(!mark[sr[sir]]) {
				v=sl[++sil]=sr[sir],sir--;
				mark[v]=1;
			}
			sl[++sil]=x;
		} else {
			fl=1;
			return;
		}
	}
	for(int i=0; i<b[x].size(); i++)if(b[x][i]!=f)dfs(b[x][i],x);
	sil=Sil,sir=Sir;
	if(x!=1) {
		if(!sil&&!sir) {
			if(a[1]>a[x])mark[1]=0;
			else mark[1]=0;
		} else if(sir&&a[sr[sir]]<a[x])mark[sr[sir]]=0;
		else if(sil&&a[sl[sil]]>a[x])mark[sl[sil]]=0;
		else if(!sir) {
			sl[sil]=v,mark[v]=0;
		} else if(!sil) {
			sr[sir]=v,mark[v]=0;
		}
	}
}
int main() {
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%d",&a[i]);
	for(i=1; i<n; i++)scanf("%d%d",&x,&y),b[x].push_back(y),b[y].push_back(x);
	dfs(1,0);
	if(fl)printf("NO\n");
	else printf("YES\n");
	return 0;
}