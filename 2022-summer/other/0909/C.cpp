#include<bits/stdc++.h>
#define ll long long
#define int long long
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
inline int fpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
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
ll a[MN], b[MN], n, m, sum;
int fac[MN], inv[MN];
int C(int x, int y) {
    if(x < 0 || y < 0 || x - y < 0) return 0;
    // printf("%d %d %d\n", fac[x], inv[y], inv[x - y]);
    return Mul(fac[x], Mul(inv[y], inv[x - y]));
}
int P(int x, int y) {
    if(x < 0 || y < 0 || x - y < 0) return 0;
    return Mul(fac[x], Mul(1, inv[x - y]));
}
signed main() {
    n = read(); m = read();
    REP(i, 1, n + 1) {
        a[i] = read();
        b[i] = b[i - 1] + a[i];
    } 
    sum = b[n];
    int j = 1;
    int pr = 0;
    REP(i, 1, n) {
        while(b[j] - b[i] < sum/2 && j + 1 <= n) ++j;
        if((b[j] - b[i]) * 2ll == sum) ++pr;
    }
    int ans = 0;
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    REP(i, 2, MN) fac[i] = Mul(fac[i - 1], i), inv[i] = Mul((mod - mod / i), inv[mod % i]);
    REP(i, 2, MN) inv[i] = Mul(inv[i - 1], inv[i]);
    // assert(pr * 2 <= n);
    REP(i, 0, pr + 1) {
        ans = Add(ans, Mul(C(pr, i), Mul(Mul(P(m, i), fpow(P(m - i, 2), pr - i)), fpow(m - i, n - pr * 2))));


        // printf("%d %d %d %d\n", C(pr, i), P(m, i), fpow(P(m - i, 2), pr - i), fpow(m - i, n - pr * 2));

    }
    printf("%d\n", ans);
    return 0;
}