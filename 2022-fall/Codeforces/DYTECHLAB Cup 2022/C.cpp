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
int x[4], y[4];
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        n = read();
        REP(i, 0, 4) x[i] = read(), y[i] = read();
        if(n == 2) {
            bool fl = 1;
            REP(i, 0, 3) {
                if(x[i] == x[3] && y[i] == y[3]) fl = 0;
            }
            if(fl) puts("NO");
            else puts("YES");
            continue;
        }
        int o = 0;
        REP(i, 0, 3) {
            bool fl = 1;
            REP(j, 0, 3) if(x[i]!=x[j]&&y[i]!=y[j]) fl=0;
            if(fl) o=i;
        }
        // dbg1(x[o]); dbg2(y[o]);
        if((x[3]-x[o])&1 && (y[3]-y[o])&1) {puts("NO"); continue;}
        if((x[o]==1||x[o]==n)&&(y[o]==1||y[o]==n)) {
            if(x[3]!=x[o]&&y[3]!=y[o]) {puts("NO");continue;}
        }
        puts("YES");
    }
    return 0;
}


