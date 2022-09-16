#include<bits/stdc++.h>
#define int long long
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

const int N = 15;
int pw[N][N], f[N][N], g[N][N], C[N][N];
void init() {
    for(int i = 0; i <= 14; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    for(int i = 0; i <= 10; ++i) {
        pw[i][0] = 1ll;
        for(int j = 1; j <= 14; ++j) {
            pw[i][j] = pw[i][j - 1] * i;
        }
    }
    for(int i = 0; i <= 9; ++i){
        for(int j = 1; j < 14; ++j) {
            for(int t = 1; t <= j; ++t) {
                g[i][j] += t * C[j][t] * pw[9 - i][t] * pw[i + 1][j - t];
            }
            // printf("g[%lld][%lld] = %lld\n", i, j, g[i][j]);
        }
    }
    for(int i = 0; i <= 9; ++i) {
        for(int j = 1; j < 14; ++j) {
            f[i][j] = g[i][j];
            for(int t = 0; t <= 9; ++t) for(int k = 1; k < j; ++k)
                f[i][j] += pw[10][j - k - 1] * g[t][k]; 
            // printf("f[%lld][%lld] = %lld\n", i, j, f[i][j]);
        }
    }
}

int tr[11];
void add(int x) {
    for(; x <= 10; x += (x & (-x))) tr[x]++;
}
int qry(int x) {
    if(x < 0) return 0;
    int ans = 0;
    for(; x; x -= (x & (-x))) ans += tr[x];
    return ans;
}

int a[15];
int get(int x) {
    int si = 0;
    for(int i = 0; i < 10; ++i) tr[i] = 0;

    for(; x; x /= 10) a[++si] = x % 10;
    for(int i = 1; i <= si / 2; ++i) swap(a[i], a[si - i + 1]);
    // for(int i = 1; i <= si; ++i) {
    //     printf("%lld ", a[i]);
    // }
    // puts("");
    int ans = 0, res = 0;
    for(int i = 1; i <= si; ++i) {
        // printf("i = %lld\n", i);
        int pos = 0, tmp = 0;
        for(int j = 0; j < a[i]; ++j) {
            if(j || i > 1) pos += f[j][si - i] + (qry(j) + res) * pw[10][si - i];
        }
        // printf("!!%lld, ans = %lld\n", i, pos);
        int pi = a[i];
        if(i == 1) pi -= 1;
        for(int j = 1; j < i; ++j) tmp += g[a[j]][si - i] * pi;
        res += qry(a[i]);
        add(a[i] + 1);
        ans += pos + tmp;
        // printf("%lld, ans = %lld\n", i, ans);
        // puts("???");
    }
    for(int i = 1; i < si; ++i) {
        for(int j = 1; j <= 9; ++j)
            ans += f[j][i - 1];
    }
    return ans;
}

void solve() {
    int l = read(), r = read();
    int ans1 = get(r + 1), ans2 = get(l);
    // printf("%lld %lld\n", ans1, ans2);
    printf("%lld\n", ans1 - ans2);
}

signed main() {
    init();
    int T = read();
    for(int o = 1; o <= T; ++o) {
        printf("Case %d: ", o);
        solve();
    }
    return 0;
}