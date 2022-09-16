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
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline void read(int &x)
{
    x = 0; int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
   	x*=f;
}

const int N = 1e5 + 10;
vector<int> g[N];
double b[N], ans = 0.0;

void dfs(int x, int fa) {
	for(auto y : g[x]) {
		if(y == fa) continue;
		if(fa) ans = max(ans, fabs(b[x] + b[fa] + b[y]) / 3.0);
		dfs(y, x);
	}
}

vector<double> qx;
int main() {
	int n; read(n);
	for(int i = 1; i <= n; ++i) scanf("%lf", &b[i]);
	ans = 0.0;
	for(int i = 1, x, y; i < n; ++i) {
		read(x), read(y);
		g[x].push_back(y), g[y].push_back(x);
		ans = max(ans, fabs(b[x] + b[y]) / 2.0);
	}
	dfs(1, 0);
	for(int u = 1; u <= n; ++u) {
		qx.clear();
		for(auto v : g[u]) qx.push_back(b[v]);
		sort(qx.begin(), qx.end());
		if(qx.size() >= 2) {
			printf("%d\n", qx.size());
			double pos = b[u];
			for(int i = 0; i < 2; ++i) pos += qx[i];
			ans = max(ans, fabs(pos) / 3.0);
			puts("???");
			pos = b[u];
			printf("%d\n", qx.size() - 1);
			int sz=qx.size();
			for(int i = sz- 1; i >= (sz - 2); --i) { 
//				printf("i = %d %d\n", i, qx.size() - 2);
				pos += qx[i];
			}
			ans = max(ans, fabs(pos) / 3.0);
			puts("????");
		}
	}
	printf("%.12f\n", ans * ans / 4.0);
	return 0;
}