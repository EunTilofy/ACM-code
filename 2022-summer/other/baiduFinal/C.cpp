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
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return ((1ll * x * y % mod) + mod) % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 5e6 + 10;
int n, k;
int inv[MN], fac[MN];

int y[MN];
int pre[MN], suf[MN];
int Largrange()
{
    y[1] = 1;
    REP(i, 2, k + 3) y[i]=Add(y[i-1], qpow(i,k, mod));
    if(n <= k + 2)  return y[n];
    n %= mod;
    ll ans = 0;
    pre[0] = suf[k+3] = 1;
    REP(i, 1, k + 3) pre[i] = Mul(pre[i-1], (n - i));
    DREP(i, k + 2, 0) suf[i] = Mul(suf[i+1], (n - i));
    REP(i, 1, k + 3)
    {
        ll f = Mul(fac[i-1], fac[k+2-i]);
        if((k - i) & 1) f = -f;
        ans = Add(ans, Mul(Mul(y[i], f), Mul(pre[i - 1], suf[i + 1])));
    }
    return ans;
}
signed main()
{
    inv[0] = inv[1] = fac[0] = fac[1] = 1;
    REP(i, 2, MN) inv[i] = Mul(inv[mod % i], (mod - mod / i)), fac[i] = Mul(fac[i - 1], inv[i]);
    k = read() - 1;
    n = read();
    if(k <= 1000000) {
        printf("%lld\n", Mul(k + 1, Largrange()));
    }
    else {
        int ans = 0;
        REP(i, 1, n + 1) {
            ans = Add(ans, qpow(i, k, mod));
        }
        printf("%lld\n", Mul(k + 1, ans));
    }
    return 0;
}