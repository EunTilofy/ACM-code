#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

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
#define mod 1000000007
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
const int MN = 5e4 + 5;
int f[MN][26][21], n, m, k, h[26][21], hh[26][21], preh[26][21];
std::vector<int> G[MN];
void dfs(int x, int F) {
    REP(i, 0, G[x].size()) if(G[x][i] != F) dfs(G[x][i], x);
    memset(h, 0, sizeof h);
    memset(preh, 0, sizeof preh);
    h[1][0] = preh[1][0] = 1;
    REP(i, 0, G[x].size()) {
        int y = G[x][i];
        if(y == F) continue;
        For(siz, 1, m) For(len, 0, min(k, siz - 1)) {
            int _ = 0;
            For(sizz, 0, siz) {
                _ = Add(_, Mul(h[siz - sizz][len], f[y][sizz][max(0, min(k, min(sizz - 1, k - len)))]));
                _ = Add(_, Mul(f[y][sizz][len] - (len?f[y][sizz][len - 1]:0), preh[siz - sizz][max(0, min(k, min(siz - sizz - 1, k - len)))]));
                if(len + len <= k) _ = Add(_, mod - Mul(f[y][sizz][len] - (len?f[y][sizz][len - 1]:0), h[siz - sizz][len]));
            }
            hh[siz][len] = _;
        }
        For(siz, 1, m) For(len, 0, min(k, siz - 1)) h[siz][len] = hh[siz][len];
        For(siz, 1, m) For(len, 0, min(k, siz - 1)) preh[siz][len] = Add(len?preh[siz][len - 1]:0, h[siz][len]);
    }

    // dbg2(x);
    // REP(i, 0, m + 1) REP(j, 0, k + 1) {
    //     dbg1(i), dbg1(j), dbg2(h[i][j]);
    // }

    For(siz, 1, m) For(len, 0, min(k, siz - 1)) {
        f[x][0][0] = Add(f[x][0][0], h[siz][len]);
        if(len + 1 <= k) f[x][siz][len + 1] = h[siz][len];
    }

    // REP(i, 0, m + 1) REP(j, 0, k + 1) {
    //     dbg1(i), dbg1(j), dbg2(f[x][i][j]);
    // }
    // dbg3(-----------------);
    
    For(siz, 1, m) For(len, 1, min(k, siz - 1)) {
        f[x][siz][len] = Add(f[x][siz][len - 1], f[x][siz][len]);
    }

    // REP(i, 0, m + 1) REP(j, 0, k + 1) {
    //     dbg1(i), dbg1(j), dbg2(f[x][i][j]);
    // }
    // dbg3(-----------------);

}
signed main() {
    n = read(), m = read(), k = read() * 2;
    REP(i, 1, n) {
        int x = read();
        int y = read();
        G[x].pb(y); G[y].pb(x);
    }
    dfs(1, 0);
    printf("%d\n", f[1][0][0]);
    return 0;
}