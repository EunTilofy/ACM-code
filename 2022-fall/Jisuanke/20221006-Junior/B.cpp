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
int ch[MN][2];
int mxdep = 0;
void dfs(int x, int d) {
    // dbg1(x); dbg2(d);
    b[x] = d;
    mxdep = max(mxdep, d);
    if(ch[x][0]) dfs(ch[x][0], d + 1);
    if(ch[x][1]) dfs(ch[x][1], d + 1);
}
int sol(int x, int d) {
    if(b[x] == d) return a[x];
    int l = 0, r = 0;
    if(ch[x][0]) l = sol(ch[x][0], d);
    if(ch[x][1]) r = sol(ch[x][1], d);
    return abs(l - r);
}
signed main() {
    freopen("end.out", "w", stdout);
    freopen("end.in", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read(), m = read();
    REP(i, 1, n + 1) ch[i][0] = read(), ch[i][1] = read();
    // REP(i, 1, n + 1) dbg1(ch[i][0]), dbg2(ch[i][1]);
    REP(i, 1, m + 1) {
        int x = read();
        a[x] = read();
    }
    dfs(1, 1);
    int ans = 0;
    REP(d, 1, mxdep + 1) {
        ans = abs(sol(1, d) - ans);
    }
    printf("%d\n", ans);
    return 0;
}