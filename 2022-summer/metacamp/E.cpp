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
#define int long long
int n;
int a[205][205], b[205];
std::set<pii> S;
pii c[205], d[205];
int tot, totd;
signed main() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            a[i][j] = read();
            if(i == j && a[i][j] > 0) {
                b[i] = a[i][j];
                c[++tot] = mkp(i, i);
            }
        }
    }
    for(int o = 2; o <= n; ++o) {
        totd = 0;
        for(int i = 1; i <= tot; ++i) {
            int j = i, l = c[i].fi, sum = a[c[i].fi][c[i].se];
            while(j + 1 <= tot) {
                if(max(sum, a[c[j + 1].fi][c[j + 1].se]) < a[l][c[j + 1].se]) {
                    if(c[j].se + 1 < c[j + 1].fi) 
                        b[c[j].se + 1] = a[l][c[j + 1].se] - sum - a[c[j + 1].fi][c[j + 1].se];
                    for(int k = c[j].se + 2; k < c[j + 1].fi; ++k) b[k] = 0;
                    sum = a[l][c[j + 1].se];
                    ++j;
                }
                else break;
            }
            d[++totd] = mkp(c[i].fi, c[j].se);
            i = j;
        }
        for(int i = 1; i <= totd; ++i) c[i] = d[i];
        tot = totd;
    }

    for(int i = 1; i < tot; ++i) {
        b[c[i].se + 1] = -min(a[c[i].fi][c[i].se], a[c[i + 1].fi][c[i + 1].se]);
    }

    for(int i = 1; i <= tot; ++i) {
        int j = i, l = c[i].fi, sum = a[c[i].fi][c[i].se];
        int mx = sum;
        while(j + 1 <= tot) {
                if(max(mx, a[c[j + 1].fi][c[j + 1].se]) < a[l][c[j + 1].se]) {
                    while(a[l][c[j + 1].se] == a[c[i + 1].fi][c[j + 1].se]) ++i;
                    l = c[i].fi;
                    b[c[i].se + 1] -= a[l][c[j + 1].se] - sum - a[c[j + 1].fi][c[j + 1].se];
                    for(int k = c[j].se + 2; k < c[j + 1].fi; ++k) b[k] = 0;
                    sum = a[l][c[j + 1].se];
                    ++j;
                }
                else break;
            }
        i = j;
    }

    for(int i = 1; i <= n; ++i) printf("%lld ", b[i]);
}