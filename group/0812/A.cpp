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
const int MN = 5005;
int a[MN], b[MN], tot, c[MN], id[MN];
int e[2][MN];
std::set<int> cannot;
void solve(int l, int r) {
    // id[l] ~ id[r] in d[L] ~ d[R]
    if(l >= r) return ;
    int cnt0 = 0, cnt1 = 0;
    cannot.clear();
    for(int i = l + 1; i <= r; ++i) {
        if(cannot.count(b[id[i]])) e[1][++cnt1] = id[i];
        else {
            e[0][++cnt0] = id[i];
            cannot.insert(b[id[i]] * 2 - b[id[l]]);
        }
    }
    id[cnt0 + l] = id[l];
    for(int i = 1; i <= cnt0; ++i) id[i + l - 1] = e[0][i];
    for(int i = 1; i <= cnt1; ++i) id[cnt0 + l + i] = e[1][i];
    // for(int i = l; i <= r; ++i) dbg1(id[i]); dbg3();
    solve(l, l + cnt0 - 1);
    solve(l + cnt0 + 1, r);
}

signed main() {
    int n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    std::sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i) {
        if(a[i] > a[i - 1]) {
            b[++tot] = a[i];
            c[tot] = 1;
        }
        else ++c[tot];
    }
    n = tot;
    for(int i = 1; i <= n; ++i) if(c[i]>2) {
        return 0 * puts("NO");
    }
    for(int i = 1; i <= n; ++i) id[i] = i;    
    // for(int i = 1; i <= n; ++i) printf("%d %d %d\n", id[i], b[i], c[i]);
    solve(1, n);
    puts("YES");
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= c[id[i]]; ++j) printf("%d ", b[id[i]]);
    }
    return 0;
}