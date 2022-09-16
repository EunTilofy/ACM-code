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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}

const int N = 1e5 + 10;
vector<int> g[N];
int f[N][2], q[N];

int mul(int x, int y) {
	return 1ll * x * y % mod;
}
void Mul(int &x, int y) {
	x = mul(x, y);
}
int add(int x, int y) {
	return ((x + y) % mod + mod) % mod;
}
void Add(int &x, int y) {
	x = add(x, y);
}

void dfs(int x, int fa) {
	f[x][0] = f[x][1] = 1;
	q[x] = 1;
	for(auto y : g[x]) {
		if(y == fa) continue;
		dfs(y, x);
		Mul(f[x][0], add(f[y][0], f[y][1]));
		Mul(f[x][1], add(q[y], add(f[y][0], f[y][1])));
		Mul(q[x], f[y][0]);
	}
	Add(f[x][1], -q[x]);
}
void solve() {
	int n = read();
	for(int i = 1, x, y; i < n; ++i) {
		x = read(), y = read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1, 0);
	printf("%d\n", add(f[1][0], f[1][1]));
	for(int i = 1; i <= n; ++i) {
		f[i][0] = f[i][1] = 0;
		g[i].clear();
	}
}

int main() {
	int T = read();
	for(int o = 1; o <= T; ++o) {
		solve();
	}
	return 0;
}
