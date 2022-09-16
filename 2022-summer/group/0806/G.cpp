#include<bits/stdc++.h>
#define ll long long
#define db long double
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
struct VEC {
    long double x, y, z;
};
struct ball {
    VEC c;
    long double r;
}a[105], A;
int n;
ball get_ball() {
    VEC u;
    u.x = read(); u.y = read(); u.z = read();
    long double r = read();
    return (ball){u, r};
}
db sqr(db x) {
    return x * x;
}
db sqrr(db x) {
    return x*x*x;
}
db dis(VEC x, VEC y) {
    return sqrt(sqr(x.x - y.x) + sqr(x.y - y.y) + sqr(x.z - y.z));
}
const db PI = acos(-1.);
const db eps = 1e-12;
db sol(db a, db b, db R) {
    // cout<<a<<" "<<b<<" "<<R<<endl;
    return PI*sqr(R)*(b-a) - PI*(1/3.00)*(sqrr(b)-sqrr(a)); 
}
db cr(ball x, ball y) {
    db d = dis(x.c , y.c);
    // std::cout<<d<<" "<<x.r<<" "<<y.r<<endl;
    // std::cout<<PI<<" "<<sqrr(y.r)<<endl;
    if(d + y.r <= x.r + eps) {
        db ret = 4.00 / 3.00 * PI * sqrr(y.r);
        // cout<<"found!"<<ret<<endl;
        return ret;
    }
    // cal x
    // r*r - x*x = R*R - (d-x)*(d-x)
    db r = y.r, R = x.r;
    db xx = (sqr(r) + sqr(d) - sqr(R)) / 2 / d;
    db ret = 0.0;
    ret += sol(xx, r, r);
    ret += sol(d-xx, R, R);
    // cout<<"cal!"<<ret<<endl;
    return ret;
}
int main() {
    int T = read();
    for(int o = 1; o <= T; ++o) {
        int n = read();
        long double ans = 0.0;
        for(int i = 1; i <= n; ++i) {
            a[i] = get_ball();
        }
        A = get_ball();
        for(int i = 1; i <= n; ++i) ans+=cr(A, a[i]);
        printf("Case #%d: %.20Lf\n", o, ans);
    }
    return 0;
}  
/*
1
3
5 5 5 2
-6 -7 6 1
6 -5 0 3
1 -1 0 10

*/