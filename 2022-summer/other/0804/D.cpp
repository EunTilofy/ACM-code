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
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
#define REP(i,a,b) for(int i=(a),i##_end_=(b);i<i##_end_;++i)
#define DREP(i,a,b) for(int i=(a),i##_end_=(b);i>i##_end_;--i)
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 2e5+5;
int f[MN][2], ans[MN], num[MN];
int Add(int x, int y) {return (x + y) % mod;}
int main() {
    int n = read();
    int k = read();
    for(int i = k; i <= n; i += k) f[i][0] = 1, ans[i] ++;
    int o = k + k + 1, p = 1;
    for(int j = k + 1; o <= n; ++j, o += j, p ^= 1) {
        for(int i = 0; i < j; ++i) num[i] = 0;
        for(int i = 1; i <= n; ++i) {
            f[i][p] = num[i % j];
            num[i % j] = Add(num[i % j], f[i][p ^ 1]);
            ans[i] = Add(ans[i], f[i][p]);
        }
    }
    for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    return 0;
}