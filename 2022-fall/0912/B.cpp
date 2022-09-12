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
struct rect {
    int x1, y1, x2, y2;
    // bool operator < (const rect &o) const {
    //     return x1 < o.x1 || (x1 == o.x1 && x2 < o.x2);
    // }
}a[10];
int n, W, H;
int f[1<<10];
int c[11];
bool b[11], d[11];
int lm[25], tot;
pii rm[25];
int tt;
bool CHK() {
    tt = 0;
    REP(i, 0, n) if(d[i]) rm[++tt] = mkp(a[i].y1, 1), rm[++tt] = mkp(a[i].y2, -1);
    rm[++tt] = mkp(0, 0);
    rm[++tt] = mkp(H - 1, 0);
    std::sort(rm + 1, rm + tt + 1);
    int _ = 0;
    int fl = 1;
    REP(i, 1, tt + 1) {
        _ += rm[i].se;
        while(i + 1 <= tt && rm[i + 1].fi == rm[i].fi) ++i, _ += rm[i].se;
        if(rm[i].fi >= 0 && rm[i].fi < H) {
            if(_ < 1) fl = 0;
        }
    }
    return fl;
}
bool chk() {
    tot = 0;
    REP(i, 0, n) if(b[i]) lm[++tot] = a[i].x1, lm[++tot] = a[i].x2;
    lm[++tot] = 0;
    bool fl = 1;
    REP(i, 1, tot + 1) {
        int X = lm[i];
        if(X < 0 || X >= W) continue;
        REP(j, 0, n) {
            d[j] = (b[j] && (a[j].x1 <= X && X < a[j].x2));
        }
        if(!CHK()) {fl = 0; break;}
    }
    return fl;
}
void print(int S) {
    printf("%d", (S&1));
    if(S < 2) return;
    print(S>>1);
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    c[0] = c[1] = 1;
    REP(i, 2, 11) c[i] = Mul(c[mod % i], (mod - mod / i)); 
    while(T--) {
        n = read();
        W = read(), H = read();
        REP(i, 0, n) {
            a[i].x1 = read(), a[i].y1 = read();
            a[i].x2 = read(), a[i].y2 = read();
        }
        // std::sort(a, a + n);
        bool HHH = 1;
        DREP(S, (1<<n) - 1, -1) {
            // print(S);puts("");
            REP(j, 0, n) b[j] = (S>>j)&1;
            if(chk()) {
                f[S] = 0;
                // print(S);puts("");
            }
            else {
                if(S == (1<<n) - 1) {
                    HHH = 0;
                    puts("-1");
                    break;
                }
                int _ = n, sm = 0;
                REP(j, 0, n) {
                    if(b[j]) --_;
                    else sm = Add(sm, f[S|(1<<j)]);
                }
                f[S] = Mul(Add(n, sm), c[_]);
            }
        }
        if(HHH) printf("%d\n", f[0]);
    }
    return 0;
}