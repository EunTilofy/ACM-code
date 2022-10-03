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
int n, m;
long long a[MN];
std::map<ll, int> mp;
int num[MN];
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    n = read(); m = read();
    REP(i, 1, n + 1) {
        ll _ = 0ll;
        REP(j, 1, m + 1) _ = (_ << 2ll) + read();
        a[i] = _;
        mp[_] = i;
    }
    REP(i, 1, n + 1) REP(j, i + 1, n + 1) {
        ll x = a[i], y = a[j];
        ll _ = 0ll;
        REP(k, 1, m + 1) {
            int nm1 = x % 4, nm2 = y % 4;
            x /= 4; y /= 4;
            _ += ((6ll - (ll)nm1 - (ll)nm2) % 3ll) << ((k - 1) * 2);
        }
        // if(i == 1 && j == 4) dbg2(_);
        if(mp[_] > j) {
            ++num[i];
            ++num[j];
            ++num[mp[_]];
        }
    }
    ll ans = 0ll;
    REP(i, 1, n + 1) {
        if(num[i] >= 2) {
            ans += 1ll * num[i] * (num[i] - 1) / 2ll;
        }
    }
    // dbg2(ans);
    // REP(i, 1, n + 1) REP(j, 0, G[i].size()) {
    //     int nm1 = G[i][j].fi, nm2 = G[i][j].se;
    //     dbg1(i); dbg1(nm1); dbg2(nm2);
    //     ans += G[nm1].size() + G[nm2].size();
    // }
    printf("%lld\n", ans);
    return 0;
}