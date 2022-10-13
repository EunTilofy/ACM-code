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
int a[MN], b[MN], c[MN * 10], n, m, rt;
bool has[31], in[MN];
// void add(int x, int k, int &p) {
//     if(!p) p = ++m;
//     ++c[p];
//     if(k == -1) return;
//     int _ = (x>>k)&1;
//     add(x, k - 1, b[p][_]);
// }

// int sol(int x, int k, int p) {
//     --c[p];
//     if(k == -1) return 0;
//     int ret = 0;
//     int _ = (x>>k)&1;
//     _ ^= 1;
//     if(b[p][_] && c[b[p][_]] > 0) {
//         // dbg1(k); dbg2(_);
//         ret += (1<<k) * _;
//         ret += sol(x, k - 1, b[p][_]);
//     }
//     else {
//         _ ^= 1;
//         // dbg1(k); dbg2(_);
//         ret += (1<<k) * _;
//         ret += sol(x, k - 1, b[p][_]);
//     }
//     return ret;
// }
signed main() {
    int T = read();
    while(T--) {
        n = read();
        // REP(i, 1, n + 1) a[i] = read(), add(a[i], 31, rt);
        // int now = 0;
        // REP(i, 1, n + 1) {
        //     int _ ;
        //     printf("%d ", _ = sol(now, 31, rt));
        //     now ^= _;
        // }
        // puts("");
        // REP(i, 1, m + 1) b[i][0] = b[i][1] = c[i] = 0;
        // m = 0; rt = 0;
        REP(i, 1, n + 1) a[i] = read();
        memset(has, 0, sizeof has);
        memset(in, 0, sizeof in);
        int now = 0;
        REP(i, 1, 33) {
            int ID = -1;
            REP(j, 1, n + 1) if(!in[j]) {
                if(ID == -1) ID = j;
                else if((now|a[j])>(now|a[ID])) ID = j;
            }
            if(ID != -1) {
                in[ID] = 1, printf("%d ", a[ID]);
            }
            now |= a[ID];
        }
        REP(i, 1, n + 1) if(!in[i]) printf("%d ", a[i]);
        puts("");
    }
    return 0;
}