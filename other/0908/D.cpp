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
int a[MN], b[MN], c[MN], d[MN], n, m;
char s[MN];
int f[2005][2005];
int chk(char x, char y, int _) {
    if(_ == 0) return 0;
    if(_ == 1) return 1;
    if(x == y) return 2;
    if(x < y) return 1;
    if(x > y) return 0;
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T --) {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        REP(i, 1, n) {
            if(s[i] == s[i + 1]) f[i][i + 1] = 2;
            else f[i][i + 1] = 1;
        }
        for(int i = 4; i <= n; i += 2) REP(j, 1, n - i + 2) {
            int l = j, r = j + i - 1;
            int o = 0;
            if(f[l + 1][r - 1] != 0 && f[l + 2][r] != 0) {
                // l
                int k1 = chk(s[l], s[l + 1], f[l + 2][r]);
                int k2 = chk(s[l], s[r], f[l + 1][r - 1]);

                // dbg1(l); dbg1(r); dbg1(k1); dbg2(k2);

                if(k1 == 0 || k2 == 0);
                else if(k1 == 2 || k2 == 2) {if(o == 0) o = 2;}
                else if(k1 == 1 && k2 == 1) {
                    // dbg3(xxx);
                    o = 1;
                }
            }
            if(f[l + 1][r - 1] != 0 || f[l][r - 2] != 0) {
                // r
                int k1 = chk(s[r], s[r - 1], f[l][r - 2]);
                int k2 = chk(s[r], s[l], f[l + 1][r - 1]);

                // dbg1(l); dbg1(r); dbg1(k1); dbg2(k2);
                
                if(k1 == 0 || k2 == 0);
                else if(k1 == 2 || k2 == 2) {if(o == 0) o = 2;}
                else if(k1 == 1 && k2 == 1) {
                    // dbg3(xxx);
                    o = 1;
                }
            }

            // dbg1(l); dbg1(r); dbg2(o);

            f[l][r] = o;
        }  
        // dbg2(f[1][n]);
        // dbg2(f[2][n - 1]);
        // dbg2(f[3][n - 2]);
        if(f[1][n] == 1) puts("Alice");
        if(f[1][n] == 0) puts("Bob");
        if(f[1][n] == 2) puts("Draw");
    }
    return 0;
}