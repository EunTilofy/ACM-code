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
int b[MN], c[MN], n, m;
std::bitset<1005> all1, a[1005], base[1005];
bool has[1005];
inline void calc()
{
    register int i,j,k;
    for(i=0;i<=n;++i) for(j=n;~j;--j)
        if(a[i][j])//Scan every bit of a[I] from top to bottom
        {
            if(has[j]) a[i]^=base[j];
            else
            {
                //There's no vector for this bit
                base[j]=a[i];
                has[j] = 1;
                /*Maintain a diagonal matrix
                for(k=j-1;~k;--k) 
                    if(base[k]&&(base[j]>>k&1)) base[j]^=base[k];
                for(k=j+1;k<=n;++k) 
                    if(base[k]>>j&1) base[k]^=base[j];
                */
                break;
            }
        }
}

void print(std::bitset<1005> x) {
    DREP(i, n, -1) printf("%d", x[i] == 1);puts("");
}

signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    m = read(), n = read() - 1;
    REP(i, 1, m + 1) b[i] = read();
    REP(i, 0, n + 1) all1[i] = 1;
    REP(i, 0, n + 1) {
        a[i][i] = 1;
        // print(a[i]);
        REP(j, 1, m + 1) {
            if(b[j] >= 0) a[i] ^= a[i] << b[j];
            else a[i] ^= a[i] >> (-b[j]);
            a[i] &= all1;
            // print(a[i]);
        }
        a[i][i] = a[i][i] ^ 1;
        // print(a[i]);
        // dbg3();
    }
    calc();
    int ans = 0;
    REP(i, 0, n + 1) ans += has[i];
    printf("%d\n", qpow(2, n + 1 - ans));
    return 0;
}