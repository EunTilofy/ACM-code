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
std::map<int, int> mpa, mpb;
int base(int x) {
    if(x < 10) return 1;
    return 1 + base(x / 10);
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T --) {
        n = read();
        mpa.clear(); mpb.clear();
        REP(i, 1, n + 1) a[i] = read(), mpa[a[i]]++;
        REP(i, 1, n + 1) b[i] = read(), mpb[b[i]]++;
        // std::sort(a + 1, a + n + 1);
        // std::sort(b + 1, b + n + 1);
        int ans = 0;
        m = 0;
        REP(i, 1, n + 1) {
            if(mpb[a[i]]) {
                mpb[a[i]]--;
                a[i] = -1;
                ++m;
            }
            else {
                if(a[i] >= 10) ++ans, a[i] = base(a[i]);
            }
        }
        REP(i, 1, n + 1) {
            if(mpa[b[i]]) {
                mpa[b[i]] --;
                b[i] = -1;
            }
            else {
                if(b[i] >= 10) ++ans, b[i] = base(b[i]);
            }
        }
        std::sort(a + 1, a + n + 1);
        std::sort(b + 1, b + n + 1);
        mpa.clear();
        mpb.clear();
        REP(i, m + 1, n + 1) {
            mpa[a[i]]++;
            mpb[b[i]]++;
        }
        REP(i, 2, 10) {
            int o = max(mpa[i] - mpb[i], mpb[i] - mpa[i]);
            // mpa[i] -= o;
            // mpb[i] -= o;
            ans += o;
        }

        printf("%d\n", ans);
    }
    return 0;
}