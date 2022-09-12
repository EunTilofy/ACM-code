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
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
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
    ios::sync_with_stdio(0); cin.tie(0);
    int T = read();
    while(T--) {
        int a, b, h;
        a = read(), b = read();
        n = read(), m = read();
        h = read();
        int ans = n + m;
        long long  num = 1ll * (h - a) * (n / b);
        if(num >= m - 1) {
            ans = min(ans, n + 1);
        }
        else {
            m -= num;
            ans = min(ans, n + m);
            if(h > b) {
                int _ = h - b, L = (n / b) * b;
                int l = n + 1, r = n + m;
                int _ans = n + m;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(1ll * _ * ((mid - L) / b) + mid - n >= m) r = mid - 1, _ans = mid;
                    else l = mid + 1;
                }
                ans = min(ans, _ans);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}