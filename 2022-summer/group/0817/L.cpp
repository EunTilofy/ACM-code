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
#define mod 1000000007
// inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e6+ 55;
char s[MN], t[MN];

const int B = 233;
int ft;
int pb[MN], fs[MN], gs[MN];
int Mul(int x, int y) {return (1ll * x * y) % mod;}
int Add(int x, int y) {return (x + y) % mod;}
int Dec(int x, int y) {return Add(x, mod - y);}
int get1(int l, int r) {
    return Dec(fs[r], Mul(fs[l - 1], pb[r - l + 1]));
}
int get2(int l, int r) {
    return Dec(gs[l], Mul(gs[r + 1], pb[r - l + 1]));
}
int lens;
int now(int o, int _) {
    // dbg1(o); dbg2(_);
    if(_ == 1) {
        int l1 = 1, r1 = lens - o + 1;
        int l2 = lens - o + 2, r2 = lens;
        // dbg1(l1); dbg2(r1); dbg1(l2); dbg2(r2);
        return Add(Mul(get1(l2, r2), pb[r1- l1 + 1]), get1(l1, r1));
    }
    else {
        int l1 = 1, r1 = o;
        int l2 = o + 1, r2 = lens;
        return Add(Mul(get2(l1, r1), pb[r2 - l2 + 1]), get2(l2, r2));
    }
}
void solve() {
    scanf("%s%s", s + 1, t + 1);
    int len = strlen(t + 1);
    ft = 0;
    for(int i = 1; i <= len; ++i) {
        ft = Add(Mul(ft, B), t[i] - 'a' + 1);
    } 
    lens = strlen(s + 1);
    fs[0] = 0;
    for(int i = 1; i <= lens; ++i) {
        fs[i] = Add(Mul(fs[i - 1], B), s[i] - 'a' + 1); 
    }
    gs[lens + 1] = 0;
    for(int i = lens; i ; --i) {
        gs[i] = Add(Mul(gs[i + 1], B), s[i] - 'a' + 1);
    }
    int l1 = read();
    int l2 = read();
    // dbg1(fs[lens]); dbg2(ft);
    if(fs[lens] == ft) {puts("yes"); return;}
    int _A = 1, pos = 1;
    REP(o, 0, lens * 3) {
        int _ = (o & 1) ? l2 : l1;
        pos = -pos;
        if(_A <= _) _A = _ - _A + 1;
        else _A = lens - (_A - _) + 1;
        if(now(_A, pos) == ft) {puts("yes"); return;}
    }
    _A = 1; pos = 1;
    REP(o, 0, lens * 3) {
        int _ = (o & 1) ? l1 : l2;
        pos = -pos;
        if(_A <= _) _A = _ - _A + 1;
        else _A = lens - (_A - _) + 1;
        // dbg1(_A); dbg2(pos);
        if(now(_A, pos) == ft) {puts("yes"); return;}
    }
    puts("no");
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int T = read();
    pb[0] = 1;
    for(int i = 1; i < MN; ++i) pb[i] = Mul(pb[i - 1], B);
    for(int o = 1; o <= T; ++o) {
        solve();
    }
    return 0;
}