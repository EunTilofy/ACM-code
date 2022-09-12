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
#define se second y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1000005, P = 1e7 + 7;
struct que {
    int n;
    int id;
    bool operator < (que &o) const {
        return n < o.n;
    }
}q[MN];
bool mk[MN];
int pr[MN],c[MN],tot,mi[MN],ans[MN];
void init() {
    for(int i = 2; i < MN; ++i) {
        if(!mk[i]) {
            pr[++tot] = i;
            mi[i] = i;
        }
        for(int j = 1; j <= tot && 1ll * pr[j] * i < MN; ++j) {
            mk[pr[j] * i] = 1;
            mi[pr[j] * i] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
}
int Mul(int x, int y) {return (1ll * x * y) % P;}
#define int long long
int cal(int n, int p) {
    // dbg1(n); dbg2(p);
    int _ = 0, _p = p;
    while(n >= _p) {
        _+=n/_p;
        _p=_p*p;
    }
    return (1ll * (_ + 1) * (_ + 2) / 2ll) % P;
}
signed main() {
    init();
    // int T = 0;
    // while(1) {
    //     int _n = read();
    //     if(!_n) break;
    //     q[++T].n = _n;
    //     q[T].id = T;
    // }
    // std::sort(q+1,q+T+1);
    // int step = 1, nowans = 1;
    // for(int i = 1; i <= T; ++i) {
    //     while(step < q[i].n) {
    //         int x = ++step;
    //         while(x != 1) {
    //             int y = mi[x];
    //             int z = 0;
    //             while(x % y == 0) ++z, x/=y;
    //             c[y] += z;
    //         }
    //     }
    //     nowans = 1;
    //     for(int i = 1; i <= tot && pr[i] <= step; ++i) nowans = Mul(nowans, cal(pr[i]));
    //     ans[q[i].id] = nowans;
    // }
    // for(int i = 1; i <= T; ++i) printf("%d\n", ans[i]);

    // for(int i = 1; i <= 20; ++i) dbg1(pr[i]);
    // dbg2(pr[tot]);
    while(1) {
        int n = read();
        if(n != 0) {
            int ans = 1;
            for(int i = 1; i <= tot && pr[i] <= n; ++i) {
                ans = (1ll * ans * cal(n, pr[i])) % P;
            }
            printf("%lld\n", ans);
        }
        else break;
    }
    return 0;
}