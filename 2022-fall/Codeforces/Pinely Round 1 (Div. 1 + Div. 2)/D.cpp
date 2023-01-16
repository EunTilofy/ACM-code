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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int mod = 1e9+7;
const int MN = 1e6+6;
int Add(int x, int y){return (x+y)%mod;}
int Mul(int x, int y){return 1ll * x * y % mod;}
int fac[MN], inv[MN];
int C(int x, int y) {
    return Mul(fac[x], Mul(inv[y], inv[x-y]));
}
// const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN], n, m;
signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    cin>>n>>m;
    int ans = 0;
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for(int i = 2; i < MN; ++i) {
        fac[i] = Mul(fac[i - 1], i);
        inv[i] = Mul((mod-mod/i), inv[mod % i]);
    }
    for(int i = 2; i < MN; ++i) inv[i] = Mul(inv[i-1], inv[i]);
    c[0] = 1;
    for(int i = 1; i < MN; ++i) c[i] = Mul(c[i-1], 3);
    for(int t = 1; t <= m; ++t) {
        if(t + m <= n + 1) ans = Add(ans, Mul(c[n+1-2*t], Mul(C(m-1,t-1), C(n-m, t-1))));
        if(t + m <= n) ans = Add(ans, Mul(c[n-2*t], Mul(C(m-1,t-1), C(n-m,t))));
    }
    if(m==0) ans = c[n];
    cout<<ans<<endl;
    return 0;
}