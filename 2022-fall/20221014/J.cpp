#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infL 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define y1 y11111111111
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
//int a[MN], b[MN], c[MN], n, m;
int T[MN], K[MN], n;
std::vector<pii> G[MN];
long long f[MN], SumT[MN], SumK[MN];
bool cmp(std::pair<std::pair<ll, ll>, int> x, std::pair<std::pair<ll, ll>, int> y) {
	__int128 num1 = x.fi.fi; num1 *= y.fi.se;
	__int128 num2 = x.fi.se; num2 *= y.fi.fi;
	return num1 > num2;
}
std::vector<int> vis[MN];
void dfs(int x, int fa) {
	SumT[x] = T[x];
	SumK[x] = K[x];
	f[x] = T[x] * K[x];
	for(auto son : G[x]) {
		if(son.fi == fa) continue;
		dfs(son.fi, x);
		SumT[son.fi] += 2ll * son.se;
		SumT[x] += SumT[son.fi];
		SumK[x] += SumK[son.fi];
		f[son.fi] += son.se * SumK[son.fi];
		f[x] += f[son.fi];
	}
	// dbg1(x); dbg2(f[x]);
	std::vector<std::pair<std::pair<long long, long long>, int> > Q;
	for(auto son : G[x]) {
		if(son.fi == fa) continue;
		Q.pb(mkp(mkp(SumK[son.fi], SumT[son.fi]), son.fi));
	} 
	Q.pb(mkp(mkp(K[x], T[x]), x));
	std::sort(Q.begin(), Q.end(), cmp);
	long long Temp = 0;
	for(auto o : Q) {
		// dbg1(o.fi.fi);
		// dbg1(o.fi.se);
		// dbg2(o.se);
		f[x] += Temp * o.fi.fi;
		// dbg1(x); dbg2(f[x]);
		Temp += o.fi.se;
		vis[x].pb(o.se);
	}
	// dbg1(x); dbg2(f[x]);
}
void dfs_print(int x) {
	for(auto y : vis[x]) {
		if(y == x) printf("P %d\n", x);
		else {
			printf("M %d\n", y);
			dfs_print(y);
			printf("M %d\n", x);
		}
	}
}
signed main() {
    freopen("beetles.out", "w", stdout);
    freopen("beetles.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read();
    REP(i, 1, n + 1) T[i] = read();
    REP(i, 1, n + 1) K[i] = read();
    REP(i, 1, n) {
		int x = read();
		int y = read();
		int d = read();
		G[x].pb(mkp(y,d));
		G[y].pb(mkp(x,d));
	}
	dfs(1, 0);
	// REP(i, 1, n + 1) dbg1(f[i]), dbg1(SumT[i]), dbg2(SumK[i]);
	printf("%lld\n", f[1]);
	dfs_print(1);
    return 0;
}