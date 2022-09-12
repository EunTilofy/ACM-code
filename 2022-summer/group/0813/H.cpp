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
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e6 + 5;
int a[MN], b[MN], c[MN], n, m;
int Mul(int x, int y) {return 1ll * x * y % mod;}
int Add(int x, int y) {return (x + y) % mod;}
int fac[MN], inv[MN];
int C(int x, int y) {
    if(y < 0 || y > x) return 0;
    return Mul(fac[x], Mul(inv[y], inv[x - y]));
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int A = read();
    for(int i = 1; i <= 7; ++i) a[i] = read();
    int B = read();
    for(int i = 1; i <= 7; ++i) b[i] = read();
    A = (A - 1) / 10 + 1;
    B = (B - 1) / 10 + 1;
    int ans = 0;
    int inv2 = 499122177;
    for(int i = c[0] = 1; i <= A + B; ++i) c[i] = Mul(c[i - 1], inv2);
    for(int i = fac[0] = 1; i <= A + B; ++i) fac[i] = Mul(fac[i - 1], i);
    inv[0] = inv[1] = 1;
    for(int i = 2; i <= A + B; ++i) inv[i] = Mul((mod - mod / i), inv[mod % i]);
    for(int i = 1; i <= A + B; ++i) inv[i] = Mul(inv[i - 1], inv[i]);
    for(int i = B; i < A + B; ++i) {
        ans = Add(ans, Mul(c[i], C(i - 1, B - 1)));
    }
    printf("%d\n", ans);
    return 0;
}