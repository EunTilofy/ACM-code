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
const int MN = 110;
int a[MN][MN], p[MN];
queue<int> q;

int main() {
    // ios::sync_with_stdio(0);cin.tie(0);
    int T = read();
    for(int o = 1; o <= T; ++o) {
        int n = read(), m = read(), s = read(), t = read();
        for(int i = 1; i <= n; ++i){
            p[i] = 0;
            for(int j = 1; j <= n; ++j)
                a[i][j] = 0;
        }
        for(int i = 1, x, y; i <= m; ++i) {
            x = read(), y = read();
            a[x][y]++, a[y][x]++;
        }
        q.push(t);p[t] = 2;
        while(q.size()) {
            int u = q.front(); q.pop();
            int cnt = 0;
            for(int i = 1; i <= n; ++i) {
                if(a[i][u] && p[i] < 2) {
                    p[i] += a[i][u];
                    if(p[i] >= 2) q.push(i);
                }
            }
        }
        if(p[s] > 1) puts("Join Player");
        else puts("Cut Player");
    }
    return 0;
}