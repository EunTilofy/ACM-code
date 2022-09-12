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
// inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
// inline int Add(int x, int y){return (x + y) % mod;}
// inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
int b[MN], c[MN], d[MN], n, m;
pair<int, int> a[MN];
bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.fi - x.se > y.fi - y.se;
}
//ax + by == gcd(a, b)
int Exgcd(int a,int b,int &x,int &y)
{
    if (!b) 
    {
        x=1;y=0;
        return a;
    }
    int d=Exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
void solve(int a, int b, int n, int &x, int &y) {
    int d = Exgcd(a, b, x, y);
    x *= n/d;
    y *= n/d;
}
signed main() {
    int T = 1;
    while(T --) {
        n = read();
        REP(i, 1, n + 1) {
            a[i].fi = read();
            a[i].se = read();
        }
        std::sort(a + 1, a + n + 1, cmp);
        REP(i, 1, n + 1) {
            b[i] = a[i].fi;
            c[i] = a[i].se;
        }
        REP(i, 1, n + 1) b[i] = b[i - 1] + b[i];
        c[n + 1] = d[n + 1] = 0;
        DREP(i, n, 0) c[i] = c[i + 1] + c[i];
        REP(i, 0, n + 1) d[i] = b[i] + c[i + 1];
        int m = read();
        while(m --) {
            int x = read();
            int y = read();
            int g = __gcd(x, y);
            if(n % g != 0) {puts("-1"); continue;}
            int adda = y/g, addb = x/g;
            int xa, xb;
            solve(x, y, n, xa, xb);
            if(xa > 0) {
                int _ = xa / adda;
                xa -= _ * adda;
                xb += _ * addb;
            }
            if(xa < 0) {
                int _ = (-xa + adda - 1) / adda;
                xa += _ * adda;
                xb -= _ * addb;
            }
            if(xa < 0 || xb < 0) {puts("-1"); continue;}
        //     // dbg1(xa); dbg2(xb);
            int l = xa;
            int r = xa + adda * (xb / addb);
            // dbg1(l); dbg2(r);
            while(l + adda * 2 < r) {
                // dbg1(l); dbg2(r);
                int xx = (r - l) / adda / 3;
                int x1 = d[(l + adda * xx) * x], x2 = d[(r - adda * xx) * x];
                if(x1 == x2) {l += adda * xx; r -= adda * xx;}
                if(x1 < x2) {l += adda * xx;}
                if(x1 > x2) {r -= adda * xx;}
            }
        //     // dbg1(l); dbg2(r);
            int ans = d[l * x];
            for(int i = l; i <= r; i += adda) {
                ans = max(ans, d[i * x]);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}