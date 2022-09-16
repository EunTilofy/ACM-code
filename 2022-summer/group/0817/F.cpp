#include<bits/stdc++.h>
#define ll long long
#define db double
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
#define pb push_back
#define mk make_pair
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
const int MN = 1e6+ 55;
int a[2], b[2];
int f[10][10];

int get(int x, int y) {
    return f[x][y];
}

void init() {
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= 7; ++i) f[i][i] = 0;
    for(int i = 1; i <= 7; i += 3) {
        for(int j = i + 1; j <= min(7, i + 2); ++j)
            f[i][j] = f[j][i] = 1;
        for(int j = max(1, i - 2); j <= i - 1; ++j)
            f[i][j] = f[j][i] = 1;
    }
    for(int k = 1; k <= 7; ++k)
        for(int i = 1; i <= 7; ++i)
            for(int j = 1; j <= 7; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    // printf("%d\n", f[2][3]);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    init();
    int T = read();
    for(int o = 1; o <= T; ++o) {
        for(int i = 0; i < 2; ++i) a[i] = read();
        for(int i = 0; i < 2; ++i) b[i] = read();
        int ans = 100;
        ans = min(get(a[0], b[0]) + get(a[1], b[1]), ans);
        ans = min(get(a[0], b[1]) + get(a[1], b[0]), ans);
        printf("%d\n", ans);
    }
    return 0;
}