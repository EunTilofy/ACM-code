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
inline long long read()
{
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
__int128 n, m;
void write(__int128 ans) {
    __int128 M = 10;
    if(ans >= 10) write(ans / M);
    printf("%d", (int)(ans % M));
}
__int128 GCD(__int128 x, __int128 y) {
    if(y == 0) return x;
    return GCD(y, x % y);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long x, y;
    x = read(), y = read();
    n = x; m = y;
    // write(n);puts("");write(m);puts("");
    
    __int128 g = GCD(x - 1, y - 1);
    // write(g);puts("");
    __int128 _1 = 1, _2 = 2;

    // if(n > m) swap(n, m);
    // write(n);puts("");
    __int128 P = 1000000000000000009;
    // write(P);
    // write(n*((m-_1)/g)%P);puts("");

    __int128 ans = n * ((m - _1) / g) % P;
    // write(ans);puts("");
    ans -= (((n - _1) / g + _1) / (_2)) * ((m - _1)/g - _1) % P;
    ans = (ans + P) % P;
    if(((n - _1) / g) % _2 == 0) ans -= (((m - _1) / g - _1) / _2) % P;
    ans = (ans % P + P) % P;
    write(ans);
    return 0;
}