#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define db double
#define ld long double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
#define inf 0x3f3f3f3f
#define infL 0x3f3f3f3f3f3f3f3f
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
inline int Add(int x, int y){return (x + y) % mod;}
inline int Mul(int x, int y){return 1ll * x * y % mod;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 3e5 + 5;
int a[MN], b[MN], c[MN], d[MN], e[MN], n, m;
std::set<std::pair<int , int> > Sa, Sb;
bool chk(int x) {
    reg int i, j;
    REP(i, 0, n) d[i] = e[i] = -1;
    Sa.clear(); Sb.clear();
    REP(i, 0, n) Sa.insert(mkp(a[i], i)), Sb.insert(mkp(b[i], i));
    Sa.insert(mkp((int)2e9, -1));
    Sb.insert(mkp((int)2e9, -1));
    bool ret = 1;
    for(i = n - 1, j = n - 1; ~i && ~j && ret;) {
        // dbg1(i); dbg1(j); dbg2(x);
        if(a[i] > b[j]) {
            int J = (*Sb.lower_bound(mkp(std::abs(x - a[i]), -1))).se;
            // dbg2(J);
            if(~J && b[J] == std::abs(x - a[i]) && !~d[J]) {
                // dbg1(i); dbg2(J);
                d[J] = i;
                e[i] = J;
                Sa.erase(mkp(a[i], i));
                Sb.erase(mkp(b[J], J));
            }
            else {
                // dbg3(----);
                ret = 0;
                break;
            }
        }
        else {
            int I = (*Sa.lower_bound(mkp(std::abs(x - b[j]), -1))).se;
            // dbg1((*Sa.lower_bound(mkp(std::abs(x - b[j]), -1))).fi);
            // dbg2(I);
            if(~I && a[I] == std::abs(x - b[j]) && !~e[I]) {
                // dbg1(I); dbg2(j);
                d[j] = I;
                e[I] = j;
                Sa.erase(mkp(a[I], I));
                Sb.erase(mkp(b[j], j));
            }
            else {
                // dbg3(----);
                ret = 0;
                break;
            }
        }
        while(~i && ~e[i]) --i;
        while(~j && ~d[j]) --j;
    }
    m = x; return ret;
}
signed main() {
    int T = read();
    while(T--) {
        n = read();
        REP(i, 0, n) a[i] = read();
        REP(i, 0, n) b[i] = read();
        std::sort(a, a + n);
        std::sort(b, b + n);
        bool fl = 0;
        REP(i, 0, n) {
            if(chk(a[0] + b[i])) {
                fl = 1;
                break;
            }
            if(chk(std::abs(a[0] - b[i]))) {
                fl = 1;
                break;
            }
        }
        if(!fl) puts("NO");
        else {
            puts("YES");
            int _ = 0;
            // REP(i, 0, n) dbg1(d[i]); dbg3(); dbg2(m);
            REP(i, 0, n) {
                if(a[d[i]] + b[i] == m || a[d[i]] > b[i]) c[i] = a[d[i]];
                else c[i] = m - b[i]; 
                _ = min(_, c[i]);
            }
            REP(i, 0, n) printf("%d ", c[i] - _);
            printf("\n%d %d\n", 0 - _, m - _);
        }
    }
    return 0;
}
