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
const int MN = 6e5 + 5;
int a[MN], n, m;
std::vector<int> d;
long long cal(long long x) {
    if(x <= 1) return 0;
    return 1ll * x * (x - 1) / 2ll;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    n = read(), m = read();
    int len = m / 2;
    REP(i, 0, n) a[i] = read();
    std::sort(a, a + n);
    REP(i, 0, n) d.pb(a[i]);
    REP(i, 0, n) d.pb(m + a[i]);
    int i = 0, j = 0;
    ll ans = 0;
    REP(i, 0, n) {
        j = max(j, i);
        while(d[j + 1] - d[i] <= len && j + 1 < i + n) ++j;
        if(d[j] - d[i] == len && len * 2 == m) {
            ans += cal(j - 1 - i);
            ans += cal(n - 1 - j + i);
        }
        else ans += cal(j - i) + cal(n - 1 - j + i);
        // dbg2(ans);
    }
    ans /= 2;
    ans = (1ll * n * (n - 1) * (n -2)) / 6 - ans;
    printf("%lld\n", ans);
    return 0;
}