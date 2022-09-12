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
const int MN = 1e5 + 5;
int a[MN];
bool sqr(int x) {
    int o = (int)sqrt((double)x + 0.5);
    if(o * o == x) return true;
    if((o - 1) * (o - 1) == x) return true;
    if((o + 1) * (o + 1) == x) return true;
    return false;
}
void solve(int l, int r) {
    if(l > r) return;
    int _ = l - 1;
    for(int i = l; i <= r; ++i) if(sqr(i + r)) {
        for(int j = i; j <= r; ++j) a[j] = i + r - j;
        _ = i - 1; break;
    }
    solve(l, _);
}
int main() {
    int T = read();
    while(T--) {
        int n = read();
        solve(0, n - 1);
        bool flag = 1;
        for(int i = 0; i < n; ++i) flag &= sqr(i + a[i]);
        if(!flag) {puts("-1");continue;}
        else {
            for(int i = 0; i < n; ++i) printf("%d ", a[i]);puts("");
        }
    }
}