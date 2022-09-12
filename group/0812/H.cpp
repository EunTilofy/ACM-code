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
#define int long long
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e7 + 5, MM = 1e7;
int c[MN], n, m, nm;
int pr[MN], tot, mi[MN];
bool mk[MN];
void init() {
    mi[1] = 1;
    for(int i = 2; i <= MM; ++i) {
        if(!mk[i]) {pr[++tot] = i; mi[i] = i;}
        for(int j = 1; 1ll * pr[j] * i <= MM; ++j) {
            mk[pr[j] * i] = 1;
            mi[pr[j] * i] = pr[j];
            if(i % pr[j] == 0) {
                break;
            }
        }
    }
}
long long ans = 0;
void dfs(int now, long long tmp, int cho) {
    if(now == nm) {
        ans += 1ll* (n/tmp) * ((cho&1)?-1:1);
        // dbg1(ans);
        return;
    }
    dfs(now + 1, 1ll * tmp * c[now + 1], cho + 1);
    dfs(now + 1, tmp, cho);
}
signed main() {
    init();
    n = read();
    m = read();
    while(m--) {
        int x = read(), y = read();
        if(__gcd(x, y) == 1) {
            printf("1 1\n");
        }
        else {
            // dbg3(!!!!);
            ans = 0; nm = 0;
            if(__gcd(x, y) == 2) ++ans;
            while(x!=1) {
                c[++nm] = mi[x];
                int xx = mi[x];
                while(x%xx==0) x/=xx;
                while(y%xx==0) y/=xx;
            }

            while(y!=1) {
                c[++nm] = mi[y];
                int yy = mi[y];
                while(y%yy==0) y/=yy;
            }
            // dbg2(nm);
            // for(int i = 1; i <= nm; ++i) dbg1(c[i]);dbg3();
            dfs(0, 1, 0);
            printf("2 %lld\n", ans);
        }
    }
    return 0;
}
/*
6 2
4 5
3 6

*/