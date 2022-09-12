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
//#define inf 0x3f3f3f3f
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

map<ll, int> mp;
int pr[4] = {2, 3, 5, 7};
int nm[10][4];
ll inf = 1e18;
pair<ll, int> a[70010];
int p[70010][4];
int res = 0;

int get(ll x) {
	if(x < 10) return x;
	ll pos = 1;
	for(; x; x /= 10) pos *= (x % 10);
	return get(pos);
}

void dfs(int dep, ll now) {
	if(dep == 4) {
		a[++res] = make_pair(now, get(now));
		for(int i = 0; i < 4; ++i) p[res][i] = p[0][i];
		return ;
	}
	ll pos = 1;
	for(int i = 0; inf / pos >= now; ++i) {
		p[0][dep] = i;
		dfs(dep + 1, now * pos);
		pos *= pr[dep];	
	}
}

void init() {
	for(int i = 1; i <= 9; ++i) {
		int x = i;
		for(int j = 0; j < 4; ++j) {
			for(; x % pr[j] == 0; x /= pr[j]) nm[i][j]++;
		}
	}
	dfs(0, 1);
}

int b[20], cnt = 0;

ll f[20][55][37][20][20];

void initf() {
	f[0][0][0][0][0] = 1;
	for(int i = 1; i <= cnt; ++i)
		for(int j = 0; j < 55; ++j)
			for(int k = 0; k < 37; ++k)
				for(int u = 0; u < 20; ++u)
					for(int v = 0; v < 20; ++v) {
						for(int w = 1; w <= 9; ++w) {
							f[i][j + nm[w][0]][k + nm[w][1]][u + nm[w][2]][v + nm[w][3]] += f[i - 1][j][k][u][v];
						}
					}
}

int qq;
ll dp(int len, int n2, int n3, int n5, int n7, int lim, int qz) {
	if(n2 < 0 || n3 < 0 || n5 < 0 || n7 < 0) return 0ll;
//	if(qq == 2) printf("%d %d %d %d %d %d %d\n", len, n2, n3, n5, n7, lim);
	if(!len) return f[len][n2][n3][n5][n7]; //?f
	if(!lim) {
		ll tmp = f[len][n2][n3][n5][n7];
		if(!qz) {
			for(int i = 1; i < len; ++i) tmp += f[i][n2][n3][n5][n7];
		}
		return tmp;
	}
	ll pos = 0;
	for(int i = max(qz, 0); i <= b[len]; ++i) {
		pos += dp(len - 1, n2 - nm[i][0], n3 - nm[i][1], n5 - nm[i][2], n7 - nm[i][3], lim && (i == b[len]), qz | (i > 0));
	}
	return pos;
}

int main() {
	init();
//	printf("res = %d\n", res);
	
	ll n;
	scanf("%lld", &n);
	if(n <= 9) {
		printf("%lld\n", n * (n + 1) / 2);
		return 0;
	}
	for(; n; n /= 10) b[++cnt] = n % 10;
	initf();
	ll ans = 0, sum = 0;
	for(int i = 1; i <= res; ++i) {
		qq = a[i].first;
		ll tmp = dp(cnt, p[i][0], p[i][1], p[i][2], p[i][3], 1, 0);
		ans += 1ll * a[i].second * tmp;
//		if(tmp && a[i].second) printf("%d %lld\n", a[i].second, tmp);
		sum += tmp;
	}
//	printf("sum = %lld\n", sum);
	printf("%lld\n", ans);
	return 0;
}
