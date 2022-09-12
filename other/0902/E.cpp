#include<bits/stdc++.h>
#define ll long long
#define int long long
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
const int MN = 1e5 + 5;
int f[MN], n;
std::vector<int> G[MN];
int mu[MN], pr[MN], tot;
bool mk[MN];
void init() {
    mu[1] = 1;
    REP(i, 2, n + 1) {
        if(!mk[i]) {pr[++tot] = i; mu[i] = -1;}
        for(int j = 1; j <= tot && 1ll * i * pr[j] <= n; ++j) {
            mk[i * pr[j]] = 1;
            if(i % pr[j] == 0) {
                mu[i * pr[j]] = 0;
                break;
            }
            mu[i * pr[j]] = -mu[i];
        }
    }
}
signed main() {
    n = read();
    init();
    int ans = 0;
    REP(i ,1 , n + 1) {
        REP(j, 1, (n/i) + 1) {
            int x = j * i;
            G[x].pb(i);
            f[x] = Add(f[x], Mul(mu[i], j - 1));
        }
    }

    REP(i, 1, n + 1) {
        REP(j, 0, G[n - i].size()) {
            int u = G[n - i][j];
            ans = Add(ans, Mul(f[(n - i) / u], Mul(i, u / __gcd(u, i))));
        }
    }
    printf("%d\n", ans);
    return 0;
}