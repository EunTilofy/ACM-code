#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename typC> bool cmin(typC &x,const typC &y) { if (x>y) { x=y; return 1; } return 0; }
template<typename typC> bool cmax(typC &x,const typC &y) { if (x<y) { x=y; return 1; } return 0; }
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
// void inc(ui &x,const ui &y) { if ((x+=y)>=p) x-=p; }
// void dec(ui &x,const ui &y) { if ((x+=p-y)>=p) x-=p; }
const int N=1e6+5;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<double> range(0, 1);
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
int n,i,e,k,a[105],now[105],g;
double p[105],sum[105],q;
void change(int x) {
//	printf("!!!%d\n",x);
//	for(int i=0; i<3; i++)printf("%d ",a[i]);
//	puts("");
	int k=a[x];
	for(int i=x; i>0; i--)a[i]=a[i-1],now[a[i]]=i;
	a[0]=k,now[k]=0;
//	for(int i=0; i<3; i++)printf("%d ",a[i]);
//	puts("");
}
void dfs(int x) {
//	for(int i=0; i<3; i++)printf("%d ",a[i]);
//	puts("");
	if(x==1000) {
		return;
	}
	int k=i<3?i:0,g;
	for(g=0; g<3; g++)if(a[g]==k+1)break;
	dfs(x+1);
}
double ans,res;
int f[5];
int main() {
	srand(time(NULL));
	scanf("%d",&n);
	for(i=1; i<=n; i++)scanf("%lf",&p[i]),sum[i]=sum[i-1]+p[i];
	for(e=1; e<=100000; e++) {
		for(i=0; i<n; i++)a[i]=i+1,now[i+1]=i;
		int cnt1=0,cnt2=0;
		for(i=1; i<=100; i++) {
//			for(int j=0;j<n;j++)printf("%d ",a[j]);
//			puts("");
			q=range(rnd);
			k=lower_bound(sum+1,sum+n+1,q)-sum;
//			printf("!%d %d\n",k,now[k]);
//			if(k==3)cnt1++;
//			else if(k==2)cnt2++;
			change(now[k]);
		}
//		printf("%d %d\n",cnt2,cnt1);
//		for(int j=0; j<n; j++)printf("%d ",a[j]);
//		puts("");
		res=0;
		for(i=0; i<n; i++)res+=p[a[i]]*i;
		ans+=res/100000;
		if(a[0]==1&&a[1]==2&&a[2]==3)f[0]++;
		if(a[0]==1&&a[1]==3&&a[2]==2)f[1]++;
		if(a[0]==2&&a[1]==1&&a[2]==3)f[2]++;
		if(a[0]==2&&a[1]==3&&a[2]==1)f[3]++;
		if(a[0]==3&&a[1]==1&&a[2]==2)f[4]++;
		if(a[0]==3&&a[1]==2&&a[2]==1)f[5]++;
	}
	printf("%.7f ",ans);
	for(int i=0; i<=5; i++)printf("%d ",f[i]);
	return 0;
}