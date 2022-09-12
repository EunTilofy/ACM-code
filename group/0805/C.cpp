#include<bits/stdc++.h>
#define ll long long
#define db double
#define LL __int128
#define DB __float128
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
#define int long long
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
    return x * f;
}
int Mul(int x, int y) {return (1ll * x * y) % mod;}
int Add(int x, int y) {return (x + y) % mod;}
int f[65][65][65 * 65], n, k, t;
const int MN = 70, P = 998244353;
int fac[MN], inv[MN], _inv[MN], C[MN];
int get_C(int nn, int mm) {
    if(mm == 0) return 1;
    return Mul(fac[nn], Mul(_inv[mm], _inv[nn - mm]));
}
signed main() {
    n = read(), k = read(), t = read();
    for(int i = inv[0] = inv[1] = fac[0] = 1; i <= 65; ++i) fac[i] = Mul(fac[i - 1], i);
    for(int i = 2; i <= 65; ++i) inv[i] = Mul((P - P / i), inv[P % i]);
    for(int i = _inv[0] = 1; i <= 65; ++i) _inv[i] = Mul(_inv[i - 1], inv[i]);
    C[0] = C[1] = 0;
    for(int i = 2; i <= n + 2; ++i) C[i] = Mul(Mul(i , i - 1), inv[2]);
    for(int i = 0; i <= n; ++i) f[1][i][C[i + 1]] = _inv[i];
    for(int o = 1; o < k; ++o) for(int i = 0; i <= n; ++i) for(int _ = 0; _ <= t; ++_) if(f[o][i][_]) {
        for(int j = 1; j <= n - i; ++j) if(_ + C[j] <= t) {
            f[o + 1][j + i][_ + C[j]] = Add(f[o + 1][j + i][_ + C[j]], Mul(f[o][i][_], _inv[j]));
        }
    }
    int ans = 0;
    for(int o = 1; o <= k; ++o) {
        // printf("%d\n", get_C(k - 1, o - 1));
        ans = Add(ans, Mul(get_C(k - 1, o - 1), Mul(fac[n], f[o][n][t])));
    }
    printf("%lld\n", ans);
    return 0;
}
//2 5 1sdf