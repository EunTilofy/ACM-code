#include<bits/stdc++.h>
#define ll long long
#define int long long
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
const int N = 1e5 + 1;
int q, p;

int q_pow(int x, int y) {
	x %= p;
	int ans = 1;
	for(; y; y >>= 1) {
		if(y & 1) ans = ans * x % p;
		x = x * x % p;
	}
	return ans;
}

int get(int a, int b, int c, int d) {
	if((a + b) % p != (c + d) % p) return -1;
	if(a == c && b == d) return 0;
	int pos = 2;
	for(int i = 1; ; pos *= 2, ++i) {
		int tmp = pos * a % p;
		int t = (tmp - c + p) % p;
		int nw = t * q_pow(a + b, p - 2) % p;
//		printf("tmp = %lld, t = %lld, nw = %lld\n", tmp, t, nw);
		if(nw < pos) return i;
//		tmp = pos * b % p;
//		t = (tmp - c + p) % p;
//		nw = t * q_pow(a + b, p - 2) % p;
////		printf("tmp = %lld, t = %lld, %lld, nw = %lld\n", tmp, t,q_pow(a + b, p - 2),nw);
//		if(nw < pos) return i;
	}
}

signed main() {
	p = read(), q = read();
	for(int o = 1, a, b, c, d; o <= q; ++o) {
		a = read(), b = read(), c = read(), d = read();
		printf("%lld\n", get(a, b, c, d));
	}
	return 0;
}
