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
const int MN = 1e6+ 55;
const double EPS = 1e-12;

struct VEC {
    double x, y;
};

double cmp(double a, double b) {
    return fabs(a - b) >= EPS + fabs(a) * EPS ? a - b : 0;
}
double cmp(const VEC &a, const VEC &b) {
    double at = cmp(a.x, b.x);
    return !at ? cmp(a.y, b.y) : at;
}
bool operator == (const VEC &a, const VEC &b) {
    return !cmp(a, b);
}
bool operator < (const VEC &a, const VEC &b) {
    return cmp(a,b) < 0;
}
VEC operator + (const VEC &a, const VEC &b) {
    return (VEC){a.x + b.x, a.y + b.y};
}
VEC operator - (const VEC &a, const VEC &b) {
    return (VEC){a.x - b.x, a.y - b.y};
}
double cmp_side(const VEC &a, const VEC &b) {
    return cmp(a.x * b.y, +a.y * b.x);
}
double getdis(const VEC &a, const VEC &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

vector<VEC> convex(vector<VEC> u) {
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    if(u.size() < 3) return u;
    vector<VEC> c;
    for(int i = 0, o = 1, m = 1; ~i; i += o) {
        while(c.size() > m) {
            VEC a = c.back() - c[c.size() - 2];
            VEC b = c.back() - u[i];
            if(cmp_side(a, b) < 0) break;
            c.pop_back();
        }
        c.push_back(u[i]);
        if(i + 1 == u.size()) m = c.size(), o = -1;
    }
    c.pop_back();
    return c;
}
int xx[MN], yy[MN];
vector<VEC> q, p;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n = read(), l = read();
    for(int i = 0; i < n; ++i) {
        xx[i] = read(), yy[i] = read();
    }
    for(int i = 0; i < n; ++i) {
        int fr = (i + 1) % n;
        if(xx[i] == xx[fr]) {
            q.push_back((VEC){xx[i] + l, yy[i]});
            q.push_back((VEC){xx[i] + l, yy[fr]});
            q.push_back((VEC){xx[i] - l, yy[i]});
            q.push_back((VEC){xx[i] - l, yy[fr]});
        } else {
            q.push_back((VEC){xx[i], yy[i] + l});
            q.push_back((VEC){xx[fr], yy[i] + l});
            q.push_back((VEC){xx[i], yy[i] - l});
            q.push_back((VEC){xx[fr], yy[i] - l});
        }
    }
    p = convex(q);
    int sz = p.size();
    double ans = 0.0;
    for(int i = 0; i < sz; ++i) {
        // printf("%.10f %.10f\n", p[i].x, p[i].y);
        ans += getdis(p[i], p[(i + 1) % sz]);
    }
    printf("%.12f\n", ans);
    return 0;
}