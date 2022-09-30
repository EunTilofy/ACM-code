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
int C(int x, int y) {return Mul(b[x], Mul(c[y], c[x - y]));}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T--) {
        n = read();
        int ans1 = 0;
        int ans2 = 0;
        int ans3 = 1;
        // ans1 + ans2 + ans3 = \C(n, n/2)
        b[0] = b[1] = c[0] = c[1] = 1;
        REP(i, 2, MN) b[i] = Mul(b[i - 1], i), c[i] = Mul(c[mod % i], (mod - mod/i));
        REP(i, 2, MN) c[i] = Mul(c[i - 1], c[i]); 
        for(int i = 0; i < n; i += 4){
            if(n-i-4) ans1 = Add(ans1, C(n-i-4, (n-i-2)/2));
            ans1 = Add(ans1, C(n-i-1, (n-i-2)/2));
        }
        ans2 = Add(C(n, n/ 2), mod - ans1 - 1);
        printf("%d %d %d\n", ans1, ans2, ans3);
    }
    return 0;
}