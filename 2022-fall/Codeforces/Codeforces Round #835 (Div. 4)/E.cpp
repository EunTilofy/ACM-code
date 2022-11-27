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
long long cal() {
    long long ret = 0;
    for(int i = 1; i <= n; ++i) b[i] = b[i - 1] + (a[i] == 1);
    for(int i = 1; i <= n; ++i) if(a[i] == 0) ret += b[i - 1];
    return ret;
}
void solve() {
    cin>>n;
    long long ans = 0;
    for(int i = 1; i <= n; ++i) cin>>a[i];
    ans = cal();
    for(int i = 1; i <= n; ++i) if(a[i] == 0) {a[i] = 1; ans = max(ans, cal()); a[i] = 0; break;}
    for(int i = n; i; --i) if(a[i] == 1) {a[i] = 0; ans = max(ans, cal()); a[i] = 1; break;}
    cout<<ans<<endl;
}
signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = 1;
    cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}