#include<bits/stdc++.h>
#define ll long long
#define db double
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
#define pb push_back
#define mk make_pair
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
const int MN = 1e6+ 55;
ll sum = 0;
int a[MN];

void Min(ll &x, ll y) {
    if(y >= 0 && y % 2 == 0) x = min(x, y);
}

ll cal(ll x, ll y) {
    if(!x) return y;
    ll pos = 1e18;
    ll tmp = -y / x;
    for(ll i = tmp - 5; i <= tmp + 5; ++i) {
        Min(pos, i * x + y);
    }
    return pos;
}

int main() {
    int n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        sum += a[i];
    }
    ll ans = 1e18;
    for(int i = 1; i <= n; ++i) {
        Min(ans, cal(a[i], sum - a[i]));
    }
    if(ans == 1e18) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}