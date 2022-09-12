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
#define For(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;++i)
#define FOr(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;--i)
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
const int MN = 1e6+ 55;
int a[MN], b[MN], c[MN], tot, id[MN];
int idd[MN];
void solve(int l, int r, int k) {
    if(l >= r || k > 29) return ;
    int _l = l, _r = r;
    For(i, l, r)
        if(b[id[i]]>>k&1) idd[_l++] = id[i];
        else idd[_r--] = id[i];
    For(i, l, r) {
        id[i] = idd[i];
    }
    solve(l, _l - 1, k + 1); solve(_r + 1, r, k + 1);
}
int main() {
    int n = read();
    For(i, 1, n) a[i] = read();
    std::sort(a + 1, a + n + 1);
    For(i, 1, n) {
        if(a[i] > a[i - 1]) b[++tot] = a[i];
        c[tot] ++;
    }
    n = tot;
    For(i, 1, n) if(c[i] > 2) return 0 * puts("NO");
    For(i, 1, n) id[i] = i;
    puts("YES");
    solve(1, n, 0);
    For(i, 1, n) For(j, 1, c[id[i]]) {
        printf("%d ", b[id[i]]);
    }
    return 0;
}