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
const int MN = 1e5 + 5;
int a[MN];
bool b[MN];
#define lb(x) (x&(-x))
int Mul(int x, int y) {return (1ll * x * y) % mod;}
int Add(int x, int y) {return (x + y) % mod;}
int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out2.txt", "w", stdout);
	int T = read();
	while(T--) {
		int n = read();
	REP(i, 1, n + 1) {
		a[i] = read();
		b[i] = 0;
	}
	int m = read();
	while(m--) {
		int opt = read();
		int l = read();
		int r = read();
		int ans = 0;
		if(opt == 1) {
			REP(i, l, r + 1) {
				if(!b[i]) {
					a[i] = Add(a[i], lb(a[i]));
					if(a[i] == lb(a[i])) b[i] = 1;
				}
				else {
					a[i] = Mul(a[i], 2);
				}
			}
		}
		else {
			REP(i, l, r + 1) ans = Add(ans, a[i]);
			printf("%d\n", ans);
		}
	}
}
	return 0;
}