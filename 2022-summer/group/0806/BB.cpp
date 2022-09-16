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
#define int long long
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e6+ 55;
int m, a, c, X[MN], l1, r1, l2, r2;
int cnt[MN], tot;
bool in[MN];
ll cal(int l, int r, int L, int R) {

    // dbg1(l); dbg1(r); dbg1(L); dbg2(R);

    if(l>r||L>R) return 0;
    for(int i = 0; i <= m; ++i) cnt[i] = 0;
    long long ret = 0;
    for(int i = l; i <= r; ++i) ret += 1ll * X[i%tot] * (R - L + 1), ++cnt[X[i%tot]];
    for(int i = m - 1; i >= 0; --i) cnt[i] += cnt[i + 1];

    // dbg2(ret);

    for(int i = L; i <= R; ++i) {
        long long num = 0;
        for(int k = 1; k * (X[i%tot]+1) <= m; ++k) {
            num += cnt[k * (X[i%tot]+1)];
        }
        // dbg1(num); dbg2(X[i%tot] + 1);
        ret -= 1ll * num * (X[i%tot] + 1);
    }
    return ret;
}
signed main() {
    int T = read();
    for(int o = 1; o <= T; ++o) {
        m = read(), a = read(), c = read();
        X[0] = read(), l1 =read(), r1 = read(), l2 = read(), r2 = read();
        for(int i = 1; i <= r1 || i <= r2; ++i) {
            X[i] = (1ll * a * X[i - 1] % m + 1ll * c) % m;
        }

        for(int i = 0; i <= 10; ++i) dbg1(X[i]);

        long long ans = 0;
        for(int i = l1; i <= r1; ++i)
        for(int j = l2; j <= r2; ++j) ans += X[i] % (X[j] + 1);
        printf("Case #%lld: %lld\n", o, ans);
    }
}
//m,a,c,X0,l1,r1,l2,r2
/*
2
7 1 4 1 2 3 4 5
10 3 6 1 2 3 1 2

1
7 1 4 1 0 8 7 10

1
9633 9607 3998  3902 7 13 25 31

*/