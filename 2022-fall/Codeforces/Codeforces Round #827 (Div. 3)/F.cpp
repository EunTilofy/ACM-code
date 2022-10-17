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
char s[MN];
long long cal(int l, int r, int nm) {
    // dbg1(l); dbg1(r); dbg2(nm); 
    if(r - l + 1 + nm > n) return 0;
    if(nm < 0) return 0;
    if(nm == 0) return 1;
    long long ret = 0;
    int leftx = min(l - 1ll, nm);
    int lefty = max(0ll, nm - (n - r));
    return max(leftx - lefty + 1, 0ll);
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        n = read();
        REP(i, 1, n + 1) a[i] = read() + 1, b[a[i]] = i;
        int l = n + 1, r = 0;
        long long ans = 0;
        REP(med, 1, (n + 3) / 2) {
            l = min(l, b[med]);
            r = max(r, b[med]);
            if(r - l + 1 - med > med) continue;
            ans += cal(l, r, med - (r - l + 1 - med));
            // dbg2(ans);
            ans += cal(l, r, med - 1 - (r - l + 1 - med));
            // dbg2(ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}