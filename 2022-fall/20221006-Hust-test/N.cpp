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
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        n = read();
        if(n % 2 == 0) printf("%d %d\n", n, n * 2);
        else if(n == 1) printf("2 3\n");
        else if(n % 3 != 0) printf("%d %d\n", 2 * n, 3 * n);
        else if(n % 5 != 0) printf("%d %d\n", 4 * n, 5 * n);
        else if(n % 7 != 0) printf("%d %d\n", 6 * n, 7 * n);
        else if(n % 11 != 0) printf("%d %d\n", 10 * n, 11 * n);
        else if(n % 13 != 0) printf("%d %d\n", 12 * n, 13 * n);
        else if(n % 17 != 0) printf("%d %d\n", 16 * n, 17 * n);
        else if(n % 19 != 0) printf("%d %d\n", 18 * n, 19 * n);
        else if(n % 23 != 0) printf("%d %d\n", 22 * n, 23 * n);
        else if(n % 29 != 0) printf("%d %d\n", 28 * n, 29 * n);

    }
    return 0;
}