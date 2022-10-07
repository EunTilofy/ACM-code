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
int c[MN], n, m;
bool d[MN];
signed main() {
     freopen("strictly-off.out", "w", stdout);
     freopen("strictly-off.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read(); int a = read(); int b = read();
    if(a * 2 > n) return 0 * puts("-1");
    int r = n % (2 * a);
    int o = n / (2 * a);
    int RR = r % o;
    int nm1 = r / o, nm2 = r / o + 1;
    int s1 = o - RR, s2 = RR;
    if(b + b < a * 2 + nm1 + (s2 > 0)) return 0 * puts("-1");
    int pos = 0;nm1 += a * 2;nm2 += a * 2;
    int tot = 0;
	REP(j, 0, s1) {
		int A = nm1 / 2;
		REP(i, nm1 - A + 1, nm1 + 1) c[++tot] = i + pos; //printf("%d ", i + pos);
		REP(i, 1, nm1 - A + 1) c[++tot] = i + pos; //printf("%d ", i + pos);
		pos += nm1;
	}
	REP(j, 0, s2) {
		int A = nm2 / 2;
		REP(i, nm2 - A + 1, nm2 + 1) c[++tot] = i + pos; //printf("%d ", i + pos);
		REP(i, 1, nm2 - A + 1) c[++tot] = i + pos; //printf("%d ", i + pos);
		pos += nm2;
	}
	
	REP(i, 1, n + 1) assert(abs(c[i]-i)>=a&&abs(c[i]-i)<=b);
	REP(i, 1, n + 1) d[c[i]] = 1;
	int nm = 0;
	REP(i, 1, n + 1) nm += d[i];
	assert(nm == n);
	REP(i, 1, n + 1) printf("%d ", c[i]);
    return 0;
}