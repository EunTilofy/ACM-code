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
const int MN = 2e5 + 5;
#define int long long
int a[MN], b[MN], c[MN], n, m;
long long d[MN], ans[MN];
bool cmp(int x, int y) {return b[x] < b[y];}

signed main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read(), c[i] = i;
    for(int i = 1; i <= n; ++i) b[i] = read();
    std::sort(c + 1, c + n + 1, cmp);
    int now = c[n];
    for(int i = n; i; --i) {
        if(a[c[i]] < a[now]) now = c[i];
        // dbg1(now);
        d[i] = 1ll * (b[c[i]] - b[c[i - 1]]) * (n - i + 1);
        ans[now] += d[i];
    }
    for(int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
    return 0;
}