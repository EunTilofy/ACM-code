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
ll n1, n2;
ll ans1, ans = -1;
ll rnd(ll l, ll r) {
    return rand() % (r - l + 1) + l;
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    srand(time(NULL));
    ll l = 3, r = 1000000000000000000;
    for(int i = 1; i <= 25; ++i) {
        if(ans != -1) break;
        ll n = rnd(l, r);
        printf("? %lld %lld\n", 1, n);
        fflush(stdout);
        cin>>n1;
        printf("? %lld %lld\n", n, 1);
        fflush(stdout);
        cin>>n2;
        if(n1 == -1) {
            r = n - 1;
        }
        else if(n1 == n2) {
            ans1 = n1;
        }
        else {
            ans = n1 + n2;
        }
    }
    if(ans != -1) cout<<"! "<<ans<<endl;
    else cout<<"! "<<ans1 * 2ll<<endl;
    return 0;
}