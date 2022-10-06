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
const int MN = 1e6 + 5;
int a[MN], b[MN], c[MN], n, m;

int getroot(int p) {
    std::vector<int> fac;
    int phi = p - 1, n = phi;
    for(int i = 2; i * i <= n; ++i) if(n % i == 0){
        fac.pb(i);
        while(n % i == 0) n /= i;
    }
    if(n > 1) fac.pb(n);
    for(int res = 2; res <= p ; ++ res) {
        bool ok = 1;
        for(int x : fac) {
            if(qpow(res, phi / x, p) == 1) {ok = 0; break;}
        }
        if(ok) return res;
    }
    return -1;
}

int vis[MN];

signed main() {
    freopen("fermat.in", "r", stdin);
    freopen("fermat.out", "w", stdout);
    int T = read();
    REP(test, 1, T + 1) {
        n = read();
        int p = read();
        int g = getroot(p);
        int gn = qpow(g, n, p);
        
        int gn_i = 1;
        vis[1] = test;
        a[1] = 0;
        bool fl = 1;
        REP(i, 1, p) {
            gn_i = 1ll * gn_i * gn % p;
            vis[gn_i] = test;
            a[gn_i] = i;
            // 1 + gn_i = gn_j
            if(vis[gn_i + 1] == test) {
                printf("%d %d %d\n", 1, qpow(g, i, p), qpow(g, a[gn_i + 1], p));
                fl = 0;
                break;
            }
            if(vis[gn_i - 1] == test) {
                printf("%d %d %d\n", 1, qpow(g, a[gn_i - 1], p), qpow(g, i, p));
                fl = 0;
                break;
            }
            if(gn_i == 1) break;
        }
        if(fl) puts("-1");
    }
    return 0;
}