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
int n, T;
int a[2][MN], b[2][MN], c[2][MN];
int ans;
int main() {
    T = read();
    while(T--) {
        int n = read();
        for(int i = 1; i <= n; ++i) a[0][i] = read() + 1, b[0][i] = a[0][i] - i, c[0][i] = a[0][i] + i;
        for(int i = 1; i <= n; ++i) a[1][i] = read() + 1, b[1][i] = a[1][i] - i, c[1][i] = a[1][i] + i;
        for(int i = n - 1; i; --i) {
            b[0][i] = max(b[0][i], b[0][i + 1]);
            b[1][i] = max(b[1][i], b[1][i + 1]);
            c[0][i] = max(c[0][i], c[0][i + 1]);
            c[1][i] = max(c[1][i], c[1][i + 1]);
        }
        ans = 2 * n - 1 + max(max(b[0][2] + 1, c[1][1] - 2 * n), 0);
        ans = min(ans, 2 * n - 1 + max(a[1][1] - 1, max(0, max(b[1][2], c[0][2] - 2 * n - 1))));
        int nows = max(0, a[1][1] - 1), step = 1, p = 1;
        for(int i = 2; i < n; ++i) {
            ++step;
            nows = max(nows, a[p][i] - step);
            ++step;
            nows = max(nows, a[p ^ 1][i] - step);
            p ^= 1;
            if(p == 0) ans = min(ans, 2 * n - 1 + max(nows, max(0, max(b[0][i+1]-step/2, c[1][i+1]-2*n-(step+1)/2))));
            else ans = min(ans, 2 * n - 1 + max(nows, max(0, max(b[1][i+1]-step/2, c[0][i+1]-2*n-(step+1)/2))));
        }
        printf("%d\n", ans);
    }
}