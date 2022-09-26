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
pii a[MN];
int n;
db chk(db x) {
    db ret = 0;
    REP(i, 1, n + 1) ret = max(ret, fabs(a[i].fi - x) + a[i].se);
    return ret;
}
signed main() {
    int T = read();
    while(T--) {
        n = read();
        REP(i, 1, n + 1) a[i].fi = read();
        REP(i, 1, n + 1) a[i].se = read();
        std::sort(a + 1, a + n + 1);
        db l = a[1].fi, r = a[n].fi;
        for(int i = 1; i <= 100; ++i) {
            db mid1=l+(r-l)/3.0;
            db mid2=r-(r-l)/3.0;
            if(chk(mid1) > chk(mid2)) l = mid1;
            else r = mid2;
        }
        printf("%.10lf\n", l);
    }
    return 0;
}
