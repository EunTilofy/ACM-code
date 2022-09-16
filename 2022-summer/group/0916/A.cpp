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
const int MN = 5005 * 5005;
int Add(int x, int y) {return (x + y) % mod;}
int Mul(int x, int y) {return 1ll * x * y % mod;}
int fac[MN], inv[MN];
int C(int x, int y) {
	return Mul(fac[x], Mul(inv[y], inv[x - y]));
}
int main() {
	int T = read();
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	REP(i, 2, MN) {
		fac[i] = Mul(fac[i - 1], i);
		inv[i] = Mul(inv[mod % i], (mod - mod / i));
	}
	REP(i, 2, MN) inv[i] = Mul(inv[i - 1], inv[i]);
	while(T--) {
		int n = read();
		int ans = 0;
		REP(i, 1, n + 1) {
			ans = Add(ans, Mul(C(n*n-i,n-1), Mul(n, Mul(fac[n],fac[n*n-n]))));
		}
		printf("%d\n", ans);
	}
	return 0;
}