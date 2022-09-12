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
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mod 998244353
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 5e5 + 5;
int a[MN], sum[MN];
std::vector<int> go[750];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int T = read();
    while(T--) {
        int n = read(); 
        int q = read();
        REP(i, 1, n + 1) a[i] = read();
        int BL = min(n, (int)sqrt(n + 10));
        int tot = 0;
        REP(i, 1, n + 1) {
            ++tot;
            int l = i, r = min(n, i + BL - 1);
            int SIZE = sum[tot] = 0;
            REP(j, l, r + 1) sum[tot] += a[j], SIZE += abs(a[j]);
            go[tot].clear();
            go[tot].resize(SIZE + 1);
            REP(x, 0, SIZE + 1) {
                int xx = x;
                REP(j, l, r + 1) if(xx + a[j] >= 0) xx += a[j];
                go[tot][x] = xx;
                // dbg2(xx);
            }
            i = r;
        }
        while(q--) {
            int l = read() + 1;
            int r = read();
            int x = read();
            if(l > r) {
                printf("%d\n", x);
                continue;
            }
            while(l <= r && (l % BL != 1)) {
                // dbg(l);
                if(x + a[l] >= 0) x += a[l];
                ++l;
            }
            // dbg3(xxxxxxx);
            while(l % BL == 1 && l + BL - 1 <= r) {
                int id = (l - 1) / BL + 1;
                if(x >= go[id].size()) x += sum[id];
                else x = go[id][x];
                l += BL;
            }
            while(l <= r) {
                if(x + a[l] >= 0) x += a[l];
                ++l;
            }
            printf("%d\n", x);
        }
    }
    return 0;
}