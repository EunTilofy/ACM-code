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
const int MN = 355;
int a[MN][MN], b[MN], c[MN], n, m;
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read();
    REP(i, 1, n + 1) b[i] = a[i][i] = read();
    REP(i, 1, n + 1) {
        //0-n-1
        REP(i, 1, n + 1) {
            if(i == 1) a[2][1] = a[1][1];
            else if (i == 2) {a[1][2] = (a[2][2] + 1) % n;}
            else a[1][i] = i - 1;
        }
        REP(i, 3, n + 1) {
            int _1 = (a[i - 1][i] - a[i][i] + n) % n;
            int _2 = (a[i - 2][i] - a[i - 1][i] + n) % n;
            int nm = (_2 - _1 + n) % n;
            REP(j, 1, n + 1) if(i != j) {
                int _3 = (a[i - 2][j] - a[i - 1][j] + n) % n;
                int _4 = (_3 - nm) % n;
                a[i][j] = (a[i - 1][j] - _4 + n) % n;
            }
        }
        REP(j, 1, n + 1) printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}