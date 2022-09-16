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
int n,m,i,k,j,h,t,a,b,c,s[305];
long long ti[305],d[305][305],z;

int f[305];
int find(int k) {
	return f[k] == k ? f[k] : f[k] = find(f[k]);
}

struct node {
	int x,y;
	ll w;
} E[305 * 305];

bool cmp(node xx, node yy) {
	return xx.w < yy.w;
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)if(i!=j)d[i][j]=1e18;
	for(i=1; i<=n; i++)ti[i]=1e18;
	scanf("%d",&t);
	for(i=1; i<=m; i++)scanf("%d%d%d",&a,&b,&c),d[a][b]=d[b][a]=c;
	for(i=1; i<=k; i++)scanf("%d",&s[i]);
	for(h=1; h<=n; h++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				d[i][j]=min(d[i][h]+d[j][h],d[i][j]);
	for(i=1; i<=k; i++)
		for(j=1; j<=k; j++)
			for(h=1; h<=n; h++)
				ti[h]=min(ti[h],d[s[i]][h]+d[h][s[j]]);
	for(z=0,i=1; i<=n; i++)z=max(z,ti[i]);
	
	int cnt = 0;
	for(int i = 1; i <= k; ++i)
		for(int j = i + 1; j <= k; ++j) {
			E[++cnt] = (node){s[i], s[j], d[s[i]][s[j]]};	
		}
	sort(E + 1, E + 1 + cnt, cmp);
	
	ll mx = 0;
	for(int i = 1; i <= n; ++i) f[i] = i;
	for(int i = 1; i <= cnt; ++i) {
		int u = E[i].x, v = E[i].y;
		int fu = find(u), fv = find(v);
		if(fu != fv) {
			f[fu] = fv;
			mx = max(mx, E[i].w);
		}
	}
	for(int i = 2; i <= k; ++i) if(find(s[i]) != find(s[i - 1])) mx = 1e18;
	z = max(z, mx);
//	printf("z = %lld\n", z);
	if(z==1e18 || t == 0)printf("-1\n");
	else printf("%lld\n",z/t+(z%t>0));
	return 0;
}

/*
4 5 1
3
1 2 2
2 3 4
3 4 3
1 4 2
2 4 3
2
*/