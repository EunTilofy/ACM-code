#include<bits/stdc++.h>
#define ll long long
#define db double
#define LL __int128
#define DB __float128
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
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e6 + 6;
long long n, m, p, x, a, b, c;
long long s[MN], t[MN];
std::map<long long, int> mp;
int main() {
    int T = read();
    while(T--) {
        n = read(), m = read();
        p = read(), x = read();
        a = read(), b = read(), c = read();
        for(int i = 1; i <= n; ++i) {
            s[i] = (1ll * a * x % p * x % p + 1ll * b * x % p + c) % p;
            x = s[i];
        }
        for(int i = 1; i <= m; ++i) {
            t[i] = (1ll * a * x % p * x % p + 1ll * b * x % p + c) % p;
            x = t[i];
        }
        long long ans = 0;
        mp.clear();
        for(int i = 1; i <= n; ++i) {
            if(!mp.count(s[i])) mp[s[i]] = i;
        }
        for(int i = 1; i <= m; ++i) if(mp.count(t[i])) {
            ans = max(ans, min(m - i + 1, n - mp[t[i]] + 1));
        }
        printf("%lld\n", ans);
    }
}