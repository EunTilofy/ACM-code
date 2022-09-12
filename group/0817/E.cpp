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
#define mod 1000000007
#define inv2 500000004
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
int mu[MN], tot, p[MN], mi[MN];
bool v[MN];
void init() {
    reg int i, j;
    for(mu[1] = 1, i = 2; i < MN; ++i) {
        if(!v[i]) {
            p[++tot] = i, mu[i] = -1;
            mi[i] = i;
        }
        for(j = 1; 1ll * i * p[j] < MN && j <= tot; j++) {
            v[i * p[j]] = 1;
            mi[i * p[j]] = p[j];
            if(i % p[j]) {
                mu[i * p[j]] = -mu[i];
            }
            else {
                mu[i * p[j]] = 0;
                break;
            }
        }
    }
}
int get_pre(int x) {
    int _ = 1;
    while(x != 1) {
        int y = mi[x];
        int z = 0;
        while(x % y == 0) x /= y, ++z;
        if(z & 1) _ *= y;
    }
    return _;
}
int a[MN], b[MN], n, m;
long long F[MN], G[MN];
int Add(int x, int y) {return (x + y) % mod;}
int Mul(int x, int y) {return (1ll * x * y) % mod;}
int Dec(int x, int y) {return Add(x, mod - y);}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    n = read(); init();
    REP(i, 1, n + 1) a[i] = read(), a[i] = get_pre(a[i]), m = max(m, a[i]);
    REP(i, 1, n + 1) b[a[i]]++;
    // F[i] = \sum j b[ji]
    REP(i, 1, m + 1) {
        REP(j, 0, m/i) F[i] = Add(F[i], Mul(j + 1, b[(j + 1) * i]));
    }
    REP(i, 1, m + 1) F[i] = Mul(F[i], F[i]);
    // G[i] = \sum{j|i} mu[j] * j * j
    REP(i, 1, m + 1) {
        REP(j, 0, m/i) G[(j + 1) * i] = Add(G[(j + 1) * i], Mul(Mul(i, i), mu[i]));
    }
    int ans = 0;
    REP(i, 1, m + 1) {
        ans = Add(ans, Mul(F[i], G[i]));
    }
    ans = Mul(Dec(ans, n), inv2);
    printf("%lld\n", ans);
    return 0;
}