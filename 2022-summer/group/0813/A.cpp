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
const int MN = 1e6 + 5;
int a[MN], b[MN][21], c[MN][21], n, m;
int q[MN], top;
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    n = read(); m = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    a[n + 1] = n + 1;
    q[top = 1] = n + 1;
    for(int i = n; i; --i) {
        while(a[i] > a[q[top]] && top > 0) --top;
        b[i][0] = q[top];
        if(q[top] > i + 1) c[i][0] = 1;
        else c[i][0] = 0;
        q[++top] = i;
    }
    // for(int i = 1; i <= n; ++i) dbg1(b[i][0]);dbg3();
    for(int k = 1; k <= 20; ++k) for(int i = 1; i <= n; ++i) {
        b[i][k] = b[b[i][k - 1]][k - 1];
        c[i][k] = c[i][k - 1] + c[b[i][k - 1]][k - 1];
    }
    while(m--) {
        int l = read();
        int r = read();
        if(l == r) {
            puts("0");
            continue;
        }
        int ans = 0;
        for(int k = 20; ~k; --k) if(b[l][k] > 0 && b[l][k] <= r) {
            ans += c[l][k];
            l = b[l][k];
        }
        if(l < r) ++ans;
        printf("%d\n", ans);
    }
    return 0;
}