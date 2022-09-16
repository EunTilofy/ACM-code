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

int n;
int a[21], mk[11], b[21];

int mx = 0, c[21];
bool check(int dep) {
	return a[b[1]] != a[b[2 * dep]];
}

void dfs(int dep) {
	if(dep > mx && check(dep)) {
		mx = dep;
		for(int i = 1; i <= 2 * dep; ++i) c[i] = b[i];
	}
	if(dep == n) return ;
	for(int i = 1; i <= n; ++i) {
		if(mk[i]) continue;
		b[dep * 2 + 1] = i * 2 - 1, b[dep * 2 + 2] = i * 2;
		mk[i] = 1;
		if(a[b[dep * 2]] != a[i * 2 - 1]) dfs(dep + 1);
		b[dep * 2 + 1] = i * 2, b[dep * 2 + 2] = i * 2 - 1;
		if(a[b[dep * 2]] != a[i * 2]) dfs(dep + 1);
		mk[i] = 0;
	}
}

int main() {
	n = read();
	for(int i = 1; i <= n; ++i) {
		a[i * 2 - 1] = read();
		a[i * 2] = read();
	}
	dfs(0);
	printf("%d\n", mx);
	for(int i = 1; i <= 2 * mx; ++i)
		printf("%d ", c[i]);
	puts("");
	return 0;
}
