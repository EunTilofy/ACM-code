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
const int MN = 3000 + 5;
int a[MN], n, p, cc;
ll f[MN][MN], g[MN][MN];
signed main() {
//    freopen("arithmetic.out", "w", stdout);
//    freopen("arithmetic.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read();
    cc = read();
    p = read();
    REP(i, 1, n + 1) a[i] = read();
    REP(k, 3, n + 1) REP(i, 1, n - k + 2) {
		f[i][j]=min(f[i+1][j],f[i][j-1])+1;
		
	}
	REP(i, 1, n + 1) g[i][i] = p;
	REP(k, 2, n + 1) REP(i, 1, n - k + 2) {
		g[i][i+k-1] = f[i][i+k-1] * cc + p;
		REP(jj,i,i+k-1) g[i][i+k-1]=min(g[i][jj]+g[jj+1][i+k-1], g[i][i+k-1]);
	}
	printf("%lld\n", g[1][n]);
    return 0;
}