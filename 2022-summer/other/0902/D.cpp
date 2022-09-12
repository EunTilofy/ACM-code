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
#define mod 1000000007
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
int a[MN], b[MN], c[MN], n, m;
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read(), m = read();
    if(m >= n) return 0 * printf("%d\n", qpow(2, n));
    a[0] = a[1] = b[0] = 1;
    REP(i, 1, n + 1) b[i] = Mul(b[i - 1], i);
    REP(i, 2, n + 1) a[i] = Mul((mod - mod / i), a[mod % i]);
    REP(i, 1, n + 1) a[i] = Mul(a[i - 1], a[i]);
    int ans = 0;
    REP(i, 0, m + 1) {
        // if(i) now = Mul(now, Mul(inv[i])
        // dbg1(n); dbg1(i); dbg2(Mul(b[n], Mul(a[i], a[n - i])));
        ans = Add(ans, Mul(b[n], Mul(a[i], a[n - i])));
    }
    printf("%d\n", ans);
    return 0;
}