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
const int MN = 1e6 + 5;
int a[MN], b[MN], c[MN], n, m;

struct BigInt {
    int _[1000];
    int len;
    #define XXX 100000000
    void init() {
        REP(i, 0, 1000) _[i] = 0;
        len = 1;
    }
    void get(int x) {
        // BigInt ret;
        (*this).init();
        (*this).len = 1;
        (*this)._[0] = x;
        // *this = ret;
    }
    BigInt add(BigInt o) {
        BigInt ret;
        ret.init();
        ret.len = max((*this).len, o.len);
        int xx = 0;
        REP(i, 0, ret.len) {
            ret._[i] = (*this)._[i] + o._[i] + xx;
            xx = ret._[i] / XXX;
            ret._[i] %= XXX;
        }
        if(xx) ret._[ret.len++] = xx;
        return ret;
    }
    void print() {
        printf("%d", (*this)._[(*this).len - 1]);
        DREP(i, (*this).len - 2, -1) {
            printf("%08d", (*this)._[i]);
        }
        return ;
    }
}dp[1005];

signed main() {
    freopen("tiling.in", "r", stdin);
    freopen("tiling.out", "w", stdout);
    n = read(), m = read();
    if(n % 2 == 1 && m % 2 == 1) return 0 * puts("0");
    if(n == 1 || m == 1) return 0 * puts("1");
    if(n > m) swap(n, m);
    REP(i, 0, m + 3) dp[i].init();
    if(n == 2) {
        dp[0].get(1);
        dp[1].get(1);
        dp[2].get(2);
        REP(i, 3, m + 1) dp[i] = dp[i - 1].add(dp[i - 3]);
        dp[m].print();
        return 0;
    }
    dp[0].get(1);
    REP(i, n - 1, m + 2) {
        dp[i] = dp[i - n + 1];
        if(i >= n + 1) dp[i] = dp[i].add(dp[i - n - 1]);
    }
    if(n % 2 == 1) {
        BigInt ans = dp[m].add(dp[m]);
        ans.print();
        return 0;
    }
    // dp[m].print();puts("");
    // dp[m - 1].print();puts("");
    // dp[m + 1].print();puts("");
    BigInt ans = (dp[m].add(dp[m])).add(dp[m - 1].add(dp[m + 1]));
    ans.print();
    return 0;
}
