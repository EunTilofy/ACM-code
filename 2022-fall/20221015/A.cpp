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
signed main() {
    freopen("graph.out", "w", stdout);
    freopen("graph.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read();
    m = read();
    if(m * 2 < n) puts("NO");
    else {
        puts("YES");
        if(n == m && n == 1) {
            printf("%d %d\n", n + 1, n);
            REP(i, 1, m + 1) {
                printf("%d %d\n", i, i + 1);
            }
            return 0;
        }
        if(m == (n + 1) / 2) {
            printf("%d %d\n", n + 1, n);
            REP(i, 1, n + 1) {
                printf("%d %d\n", i, i + 1);
            }
            return 0;
        }
        printf("%d %d\n", m + n, m + n);
        REP(i, 1, m * 2) printf("%d %d\n", i, i + 1);
        printf("%d %d\n", m * 2, 1);
        REP(i, m * 2 + 1, m + n + 1) printf("%d %d\n", i - 1, i);
    }
    return 0;
}