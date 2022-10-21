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
const int MN = 1000 + 5;
int a[MN], b[MN], c[MN], n, m;
int f[MN][MN];
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int n = read();
    int ans = 0;
    REP(i, 1, n + 1) {
        a[i] = read();
        b[i] = read();
    }
    c[0] = c[1] = 1;
    REP(i, 2, MN) c[i] = Mul((mod - mod/i), c[mod % i]);
    REP(i, 1, n + 1) b[i] = Mul(b[i], c[100]);
    REP(i, 0, 1001) f[n + 1][i] = 0;
    DREP(j, n, 0) REP(i, 0, 1001) {
        // dbg1(j);
        if(i == a[j]) f[j][i] = Add(f[j + 1][i], 1);
        if(i > a[j]) {
            f[j][i] = Add(1, Add(Mul(f[j + 1][i - 1], b[j]), Mul(f[j+1][i], Add(1, mod - b[j]))));
        }
        if(i < a[j]) {
            f[j][i] = Add(f[j + 1][a[j]], 1 + Mul(a[j] - i, qpow(b[j], mod - 2)));
        }
    }
    printf("%d\n", f[1][0]);
    return 0;
}