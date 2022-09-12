#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db long double
#define ld long double
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
#define y1 y11111111111
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
const int MN = 3e5 + 5;
typedef long double NUM;
const NUM EPS = 1e-12;
int n;
NUM S;
inline NUM sqr(NUM a) {
    return a * a;
}
inline NUM cmp(NUM a, NUM b) {
    return fabs(a-b)>=EPS+fabs(a)*EPS?a-b:0;
}
struct VEC {
    NUM x, y;
    int xx, yy;
}a[MN];

struct RAY {
    VEC u, v;
};
inline NUM cmp(const VEC &a, const VEC &b) {
    NUM at = cmp(a.x, b.x);
    return !at?cmp(a.y, b.y):at;
}
inline VEC operator + (const VEC &a, const VEC &b) {
    return (VEC) {
        a.x + b.x, a.y + b.y, 0, 0
    };
}
inline VEC operator - (const VEC &a, const VEC &b) {
    return (VEC) {
        a.x - b.x, a.y - b.y, 0, 0
    };
}
inline NUM operator *(const VEC &a, const VEC &b) {
    return a.x*b.y-a.y*b.x;
}
NUM cmp_side(const VEC &a, const VEC &b) {
    return cmp(a.x*b.y, +a.y*b.x);
}
inline bool operator == (const VEC &a, const VEC &b) {
    return !cmp(a, b);
}
inline bool operator < (const VEC &a, const VEC &b) {
    return cmp(a, b) < 0;
}
std::vector<VEC> P1, P2, C1, C2;
std::vector<VEC> ch(std::vector<VEC> u) {
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    if(u.size() < 3) return u;
    vector<VEC> c;
    for(size_t i = 0, o =1, m = 1; ~i; i += o) {
        while(c.size() > m) {
            VEC a = c.back() - c[c.size() - 2];
            VEC b = c.back() - u[i];
            if(cmp_side(a, b) < 0) break;
            c.pop_back();
        }
        c.pb(u[i]);
        if(i + 1 == u.size()) m = c.size(), o = -1;
    }
    c.pop_back();
    return c;
}
NUM cal(std::vector<VEC> u) {
    if(u.size() < 3) return 0;
    NUM ret = 0.0;
    int SIZE = u.size();
    u.pb(u[0]);
    REP(i, 0, SIZE) {
        ret += u[i] * u[i + 1];
    }
    ret = fabs(ret) / 2.0;
    // dbg2(ret);
    return ret;
}
NUM get(int pos) {
    P1.clear(), P2.clear();
    REP(i, 1, n + 1) {
        if(pos == 0) {
            P2.pb(a[i]);
            continue;
        } 
        if(pos > n) {
            P1.pb(a[i]);
            continue;
        }
        if(a[i].xx <= a[pos].xx) P1.pb(a[i]);
        else P2.pb(a[i]);
    }
    C1.clear();C2.clear();
    C1 = ch(P1);
    C2 = ch(P2);
    return cal(C1) - cal(C2);
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    n = read(); S = read();
    REP(i, 1, n + 1) {
        a[i].x = a[i].xx = read();
        a[i].y = a[i].yy = read();        
    }
    std::sort(a + 1, a + n + 1);
    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(get(mid) - S <= 0) {
            ans = mid;
            l = mid + 1;
        } 
        else r = mid - 1;
    }
    NUM ans1 = fabs(get(ans));
    NUM ans2 = fabs(get(ans + 1));
    NUM ANS1;
    if(!cmp(fabs(ans1-S), fabs(ans2-S))) {
        ANS1 = min(ans1, ans2);
    }
    else {
        ANS1 = ans1;
        if(fabs(ans2 - S) < fabs(ans1 - S)) ANS1 = ans2;
    }

    l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(get(mid) + S <= 0) {
            ans = mid;
            l = mid + 1;
        } 
        else r = mid - 1;
    }
    NUM ans3 = fabs(get(ans));
    NUM ans4 = fabs(get(ans + 1));
    NUM ANS2;
    if(!cmp(fabs(ans3-S), fabs(ans4-S))) {
        ANS2 = min(ans3, ans4);
    }
    else {
        ANS2 = ans3;
        if(fabs(ans4 - S) < fabs(ans3 - S)) ANS2 = ans4;
    }
    
    NUM ANS;
    if(!cmp(fabs(ANS1-S), fabs(ANS2-S))) {
        ANS = min(ANS1, ANS2);
    }
    else {
        ANS = ANS1;
        if(fabs(ANS2 - S) < fabs(ANS1 - S)) ANS = ANS2;
    }


    printf("%.10Lf", ANS);
    return 0;
}