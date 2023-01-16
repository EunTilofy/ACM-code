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
int que(int x, int y) {
    // dbg1(x); dbg2(y);
    if(x == 1) return y;
    vector<int> d;
    int I = 2, UP = sqrt(x + 5);
    while(x!=1) {
        while(x % I != 0 && I + 1 <= UP) ++I;
        if(x % I == 0) d.pb(I);
        while(x%I==0) x/=I;
        if(I == UP) {
            if(x != 1) d.pb(x);
            x = 1;
        }
    }
    vector<pii> o;
    o.pb({d.back(), 1});
    d.pop_back();
    // reverse(d.begin(), d.end());
    for(auto _ : d) {
        vector<pii> tmp;
        for(auto xx : o) tmp.pb({xx.fi * _, xx.se ^ 1});
        for(auto xx : tmp) o.pb(xx);
        o.pb({_, 1});
    }
    // dbg2(y);
    long long ret = y;
    for(auto xx : o) {
        // dbg1(xx.fi); dbg2(xx.se);
        ret = ret + (xx.se?-1:1) * (y/xx.fi);
    }
    return ret;
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        REP(i, 1, n + 1) cin >> a[i];
        long long ans = 1;
        REP(i, 2, n + 1) {
            int last = a[i - 1];
            int now = a[i];
            // dbg1(last); dbg2(now);
            if(a[i - 1] % a[i] != 0) {ans = 0; break;}
            ans = 1ll * ans * que(a[i - 1]/a[i], m/a[i]) % mod;
            // dbg2(ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}