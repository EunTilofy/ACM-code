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

inline long long read()
{
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}

long long t[100], k[100], tot;

int main() {
    long long x = read();
    long long y = read();
    long long prex = x, prey = y;
    while(1) {
        // printf("now %d %d\n", x, y);
        long long xx = abs(x);
        long long yy = abs(y);
        if(xx == 0 || yy == 0) break;
        if(yy > xx) {
            t[++tot] = 2;
            k[tot] = -(yy/xx) * (y/yy) * (x/xx);
            long long yyy = yy % xx;
            if(yyy * 2 > xx) k[tot] -= (y/yy) * (x/xx);
            y += k[tot] * x;
        }
        else {
            t[++tot] = 1;
            k[tot] = -(xx/yy) * (y/yy) * (x/xx);
            long long xxx = xx % yy;
            if(xxx * 2 > yy) k[tot] -= (y/yy)*(x/xx);
            x += k[tot] * y;
        }
    }
    if(tot > 50) assert(0);
    printf("%lld\n", tot);
    for(int i = 1; i <= tot; ++i) {
        printf("%lld %lld\n", t[i], k[i]);
    }
    return 0;
}