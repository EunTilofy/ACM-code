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
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
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
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e6 + 5;
const int B[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};
std::map<int, int> S;
long long qz[MN];
int get(int x) {
    if(x < 10) return x;
    int _ = 1, Mod = x + 1;
    REP(i, 0, 10) {
        if(x >= (B[i] / 10)) _ = 1ll * _ * (x % B[i]) % Mod; 
    }
    return _;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = read();
    while(T--) {
        int n = read();
        int m = read();
        long long ans = 0;
        S.clear();
        REP(i, 1, m + 1) {
            n = get(n);
            // dbg1(i); dbg2(n);
            qz[i] = qz[i - 1] + n;
            if(S.count(n)) {
                int l = S[n];
                int r = i;
                // dbg1(l); dbg2(r);
                ll sum = qz[r] - qz[l];
                ans += 1ll * ((m - i + 1) / (r - l)) * sum; 
                // dbg2(qz[(m - i + 1) % (r - l) + l - 1]);
                // dbg2(qz[l - 1]);
                ans += qz[((m - i + 1) % (r - l)) + l - 1] - qz[l - 1];
                break;
            }
            S[n] = i;
            ans += n;
        }
        printf("%lld\n", ans);
    }
    return 0;
}