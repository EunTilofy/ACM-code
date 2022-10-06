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
int a[MN], b[MN], c[MN], n, m;
double area(int a, int b, int c) {
    if(a >= b && a >= c) swap(a, c);
    if(b >= a && b >= c) swap(b, c);
    if(a + b < c) return 1e18;
    // dbg1(a); dbg1(b); dbg2(c);
    double p = (double)(a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
db ans = 1e18;
void dfs(int x) {
    // dbg1(x); dbg2(n);
    if(x == n) {
        int len[3][2];
        memset(len, 0, sizeof len);
        REP(i, 0, n) {
            len[b[i]/2][b[i]&1] += a[i];
        }
        ans = min(ans, area(abs(len[0][1] - len[0][0]), abs(len[1][0] - len[1][1]), abs(len[2][0] - len[2][1])));
        return ;
    }
    REP(i, 0, 6) {
        b[x] = i;
        dfs(x + 1);
    }
}
signed main() {
    freopen("polygon.out", "w", stdout);
    freopen("polygon.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read();
    REP(i, 0, n) {
        a[i] = read();
        // dbg1(i); dbg2(a[i]);
    }
    dfs(0);
    // REP(S, 0, (1<<n)) {
    //     REP(i, 0, n) {
    //         REP(j, i + 1, n) {
    //             int ss[2];
    //             ss[0] = ss[1] = 0;
    //             REP(k, 0, n) if(k != i && k != j) {
    //                 ss[S>>k&1] += a[k];
    //                 // if(k == 1) dbg2(a[k]);
    //             }
    //             // dbg1(ss[0]); dbg2(ss[1]);
    //             ans = min(ans, area(a[i], a[j], std::abs(ss[0] - ss[1])));
    //         }
    //     }
    // }
    printf("%.15lf\n", ans);
    return 0;
}