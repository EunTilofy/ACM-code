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
inline long long read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 2e5 + 5;
bool chk(ll a,ll b,ll x,ll _) {
    while((a>0&&b>0)&&(a%x==0||b%x==0)) {
        // dbg1(a);dbg2(b);
        if(b%x==0) swap(a,b);
        if(b%x==0&&a%x==0) {
            //x==1
            assert(x==1);
            if(a>b)swap(a,b);
        }
        ll aa = a/x;
        ll bb = ((a + b)/_) - aa;
        a=aa;b=bb;
    }
    if((a==1&&b==0)||(a==0&&b==1)) return true;
    return false;
}
int main() {
    int T = read();
    while(T--) {
        long long a = read();
        long long b = read();
        long long x = read();
        long long y = read();
        long long g = __gcd(a, b);
        a/=g;b/=g;
        g = __gcd(x, y);
        x/=g;y/=g;
        ll c = a + b;
        ll d = x + y;
        int ans = 0;
        while(c%d==0) ++ans, c/=d;
        if(c!=1) puts("-1");
        else {
            if((x==1&&y==1)||chk(a,b,x,x+y)) printf("%d\n", ans + 1);
            else puts("-1");
        }
    }
    return 0;
}
/*
4
3 5 1 1
1 24 1 4
12 113 3 2
8 117 2 3

*/