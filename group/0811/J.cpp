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
const int MN = 2e5 + 5;

int a[MN], b[MN];
int c[MN], n, m;
char s[MN];
const int B = 233;

int Add(int x, int y) {return (x + y) % mod;}
int Dec(int x, int y) {return Add(x, mod - y);}
int Mul(int x, int y) {return 1ll * x * y % mod;}

int PB[MN];

int get1(int l, int r) {
    return Dec(a[r], Mul(a[l - 1], PB[r - l + 1]));
}
int get2(int l, int r) {
    return Dec(b[l], Mul(b[r + 1], PB[r - l + 1]));
}

int get(int l, int r, int L, int R) {
    int _1 = get1(l, L - 1);
    int _2 = get2(L, R);
    int _3 = get1(R + 1, r);
    int len1 = L - 1 - l + 1;
    int len2 = R - L + 1;
    int len3 = r - R;
    return Add(Add(Mul(_1, PB[len3 + len2]), Mul(_2, PB[len3])),_3);
}
int getr(int l, int r, int L, int R) {
    int _3 = get2(l, L - 1);
    int _2 = get1(L, R);
    int _1 = get2(R + 1, r);
    int len3 = L - 1 - l + 1;
    int len2 = R - L + 1;
    int len1 = r - R;
    return Add(Add(Mul(_1, PB[len3 + len2]), Mul(_2, PB[len3])),_3);
}

int main() {
    scanf("%s", s + 1);
    int l = 0, r = 1 + strlen(s + 1);
    while(s[l + 1] == s[r - 1] && l + 1 < r - 1) ++l, --r;
    ++l; --r;
    PB[0] = 1;
    for(int i = 1; i <= r - l + 5; ++i) PB[i] = Mul(PB[i - 1], B);
    if(l >= r) {
        printf("%d %d\n", 1, 1);
        return 0;
    }
    for(int i = l; i <= r; ++i) {
        a[i] = (1ll * a[i - 1] * B % mod + s[i] - 'a' + 1) % mod;
    }
    for(int i = r; i >= l; --i) {
        b[i] = (1ll * b[i + 1] * B % mod + s[i] - 'a' + 1) % mod;
    }
    for(int i = l + 1; i <= r; ++i) {
        if(get(l, r, l, i) == getr(l, r, l, i)) 
            return 0 * printf("%d %d\n", l, i);
    }
    for(int j = r - 1; j >= l; --j) {
        if(get(l, r, j, r) == getr(l, r, j , r))
            return 0 * printf("%d %d\n", j, r);
    }
    puts("-1 -1");
    return 0;
}