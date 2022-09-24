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
int a[MN];
long long b[MN], c[MN], n, m;
int S[MN]; int tot1;
bool solve() {
    b[m] = 0;
    REP(i, m + 1, n + 1) b[i] = b[i - 1] + a[i];
    DREP(i, m - 1, 0) b[i] = b[i + 1] + a[i];
    // S1.clear(); S2.clear();
    tot1 = 0;
    ll minx = 0;
    REP(i, m + 1, n + 1) {
        minx = min(minx, b[i]);
        c[i] = minx;
        if(tot1 == 0 && b[i] > 0) S[++tot1] = i;
        else if(c[i] < c[S[tot1]]) {
            if(b[i] > b[S[tot1]]) S[++tot1] = i;
        }
        else if(c[i] == c[S[tot1]]) {
            if(b[i] > b[S[tot1]]) S[tot1] = i;
        }
        // S[++tot1] = mkp(mkp(-minx, -b[i]), i);
    }
    std::sort(S + 1, S + tot1 + 1);
    int j = 0, r = m;
    long long now = a[m];
    DREP(i, m, 0) {
        if(now < 0) return false;
        if(i == 1) return true;
        while(j + 1 <= tot1 && now + c[S[j + 1]] - b[S[j]] >= 0) {
            now += b[S[j + 1]] - b[S[j]];
            ++j;
        }
        now += a[i - 1];
    }
    return true;
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        n = read(), m = read();
        REP(i, 1, n + 1) a[i] = read();
        if(a[m] < 0) {puts("NO"); continue;}
        bool fl = 0;
        fl |= solve();
        for(int i = 1; i + i <= n; ++i) std::swap(a[i], a[n - i + 1]);
        m = n - m + 1;
        fl |= solve();
        puts(fl?"YES":"NO");
    }
    return 0;
}