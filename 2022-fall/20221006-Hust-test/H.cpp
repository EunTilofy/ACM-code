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
int n, m;
char s[3005][3005];
bool chk(int x1, int x2, int y1, int y2) {
    bool fl = 1;
    REP(i, x1, x2 + 1) REP(j, y1, y2 + 1) fl &= s[i][j] == 'x';
    return fl;
}
bool mk[3005][3005];
bool chkall() {
    bool fl = 1;
    REP(i, 1, n + 1) REP(j, 1, m + 1) fl &= (s[i][j] == 'x') == mk[i][j];
    return fl;
}
void paint(int x1, int x2, int y1, int y2) {
    REP(i, x1, x2 + 1) REP(j, y1, y2 + 1) mk[i][j] = 1;
}
void fpaint(int x1, int x2, int y1, int y2) {
    REP(i, x1, x2 + 1) REP(j, y1, y2 + 1) mk[i][j] = 0;
}
#define S(x,y) (s[x][y] == 'x')

bool chkH() {
    int II = -1, JJ = -1;
    REP(i, 1, n + 1) {
        bool fl = 0;
        REP(j, 1, m + 1) if(S(i,j)) {fl = 1; II = i, JJ = j; break;}
        if(fl) break;
    }
    if(II == -1) return 0;
    int d = 1;
    while(JJ+d<=m&&S(II,JJ+d)) ++d;
    int h = 1;
    while(II + h <= n && chk(II+h,II+h,JJ,JJ+d-1)) ++h;

    int JJ_ = -1;
    REP(j, JJ+d+1, m + 1) if(S(II, j)) {JJ_ = j; break;}
    if(JJ_ == -1) return 0;
    if(JJ_ + d - 1 > m) return 0;
    if(!chk(II, II+h-1, JJ_, JJ_+d-1)) return 0;

    int JJJ = JJ+d, III = -1;
    REP(i, II + 1, n + 1) if(S(i, JJJ)) {III = i; break;}
    if(III == -1) return 0;
    if(III + d >= II + h) return 0;
    if(!chk(III, III+d-1, JJJ, JJ_ - 1)) return 0;
    
    paint(II, II + h - 1, JJ, JJ + d - 1);
    paint(III, III + d - 1, JJJ, JJ_ - 1);
    paint(II, II + h - 1, JJ_, JJ_ + d - 1);

    bool Fl = 0;
    if(chkall()) Fl = 1;
    fpaint(II, II + h - 1, JJ, JJ + d - 1);
    fpaint(III, III + d - 1, JJJ, JJ_ - 1);
    fpaint(II, II + h - 1, JJ_, JJ_ + d - 1);
    return Fl;
}

bool chkT() {
    int II = -1, JJ = -1;
    REP(i, 1, n + 1) {
        bool fl = 0;
        REP(j, 1, m + 1) if(S(i,j)) {fl = 1; II = i, JJ = j; break;}
        if(fl) break;
    }
    if(II == -1) return 0;
    int h = 1;
    while(JJ + h <= m && S(II,JJ+h)) ++h;
    int d = 1;
    while(II + d <= n && chk(II+d,II+d,JJ,JJ+h-1)) ++d;

    int JJ_ = -1, III = II + d;

    if(III > n) return 0;

    REP(j, JJ+1, m + 1) if(S(III, j)) {JJ_ = j; break;}
    if(JJ_ == -1) return 0;
    if(JJ_ + d - 1 >= JJ + h - 1) return 0;

    int h2 = 0;
    while(III + h2 <= n && chk(III+h2,III+h2,JJ_,JJ_+d-1)) ++h2;
    if(!h2) return 0;

    paint(II, II + d - 1, JJ, JJ + h - 1);
    paint(III, III + h2 - 1, JJ_, JJ_ + d - 1);
    bool Fl = 0;
    if(chkall()) Fl = 1;
    fpaint(II, II + d - 1, JJ, JJ + h - 1);
    fpaint(III, III + h2 - 1, JJ_, JJ_ + d - 1);
    return Fl;
}

bool chkU() {
    int II = -1, JJ = -1;
    REP(i, 1, n + 1) {
        bool fl = 0;
        REP(j, 1, m + 1) if(S(i,j)) {fl = 1; II = i, JJ = j; break;}
        if(fl) break;
    }
    if(II == -1) return 0;
    int d = 1;
    while(JJ+d<=m&&S(II,JJ+d)) ++d;
    int h = 1;
    while(II + h <= n && chk(II+h,II+h,JJ,JJ+d-1)) ++h;

    int JJ_ = -1;
    REP(j, JJ+d+1, m + 1) if(S(II, j)) {JJ_ = j; break;}
    if(JJ_ == -1) return 0;
    if(JJ_ + d - 1 > m) return 0;
    if(!chk(II, II+h-1, JJ_, JJ_+d-1)) return 0;
    if(h <= d) return 0;
    if(!chk(II+h-d,II+h-1,JJ,JJ_+d-1)) return 0;

    paint(II, II + h - 1, JJ, JJ + d - 1);
    paint(II+h-d,II+h-1,JJ+d,JJ_-1);
    paint(II, II + h - 1, JJ_, JJ_ + d - 1);
    bool Fl = 0;
    if(chkall()) Fl = 1;
    fpaint(II, II + h - 1, JJ, JJ + d - 1);
    fpaint(II+h-d,II+h-1,JJ+d,JJ_-1);
    fpaint(II, II + h - 1, JJ_, JJ_ + d - 1);
    return Fl;
}

bool chkS() {
    int II = -1, JJ = -1;
    REP(i, 1, n + 1) {
        bool fl = 0;
        REP(j, 1, m + 1) if(S(i,j)) {fl = 1; II = i, JJ = j; break;}
        if(fl) break;
    }
    if(II == -1) return 0;
    int h = 1;
    while(II + h <= n && S(II+h,JJ)) ++h;
    int d = 1;
    while(JJ + d <= m && chk(II,II+h-1,JJ+d,JJ+d)) ++d;
    if(h <= 2 * d) return 0;

    int d2 = 0;
    while(JJ + d + d2 <= m && chk(II,II+d-1,JJ+d+d2,JJ+d+d2)) ++d2;
    if(!d2) return 0;

    if(!chk(II+h-d,II+h-1,JJ+d,JJ+d+d2-1)) return 0;

    int h2 = 0;
    while(II + h + h2 <= n && chk(II+h+h2, II+h+h2, JJ+d2, JJ+d+d2-1)) ++h2;
    if(!h2) return 0;

    if(h2 <= d) return 0;

    if(!chk(II+h+h2-d,II+h+h2-1,JJ,JJ+d+d2-1)) return 0;
    
    paint(II, II + h - 1, JJ, JJ + d - 1);
    paint(II, II + d - 1, JJ + d, JJ + d + d2 - 1);
    paint(II+h-d,II+h-1,JJ+d,JJ+d+d2-1);
    paint(II+h, II+h+h2-1, JJ+d2, JJ+d+d2-1);
    paint(II+h+h2-d,II+h+h2-1,JJ,JJ+d2-1);
    bool Fl = 0;
    if(chkall()) Fl = 1;
    fpaint(II, II + h - 1, JJ, JJ + d - 1);
    fpaint(II, II + d - 1, JJ + d, JJ + d + d2 - 1);
    fpaint(II+h-d,II+h-1,JJ+d,JJ+d+d2-1);
    fpaint(II+h, II+h+h2-1, JJ+d2, JJ+d+d2-1);
    fpaint(II+h+h2-d,II+h+h2-1,JJ,JJ+d2-1);
    return Fl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin>>T;
    while(T--) {
        cin>>n>>m;
        REP(i, 1, n + 1) cin>>(s[i]+1);
        // n = read(), m = read();
        // REP(i, 1, n + 1) scanf("%s", s[i] + 1);
        if(chkH()) puts("H");
        else if(chkT()) puts("T");
        else if(chkS()) puts("S");
        else if(chkU()) puts("U");
        else puts("OOPS!");
    }
    return 0;
}