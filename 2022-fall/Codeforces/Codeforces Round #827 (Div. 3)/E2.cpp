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
long long lcm(long long x, long long y) {
    return 1ll * x * y / __gcd(x, y);
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        int a, b, c, d;
        a = read(), b = read(), c = read(), d = read();
        std::vector<int> _[2];
        REP(i, 1, a + 1) {
            if(1ll * i * i > a) break;
            if(a % i == 0) {
                _[0].pb(i);
                if(a / i != i) _[0].pb(a / i);
            }
        }
        REP(i, 1, b + 1) {
            if(1ll * i * i > b) break;
            if(b % i == 0) {
                _[1].pb(i);
                if(b / i != i) _[1].pb(b / i);
            }
        }
        bool fl = 0;
        for(auto x : _[0]) {
            for(auto y  : _[1]) {
                long long nm1 = x * y, nm2 = 1ll * a * b / x / y;
                nm1 = (a / nm1 + 1) * nm1;
                nm2 = (b / nm2 + 1) * nm2;
                if(nm1 <= c && nm2 <= d) {
                    fl = 1;
                    printf("%lld %lld\n", nm1, nm2);
                    break;
                }
            }
            if(fl == 1) break;
        }
        if(!fl) {puts("-1 -1");}
    }
    return 0;
}