#include<bits/stdc++.h>
#define ll long long
#define db double
#define LL __int128
#define DB __float128
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
inline long long read() {
    long long x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e5 + 5;
const int log_MN = 70;
long long a[MN], base[log_MN], n, c[MN];
std::bitset<MN> d[log_MN], da; 
inline void calc()
{
    int N = 63;
    register int i, j;
    for(i = 1;i <= n; ++i) {
        da.reset();da[i] = 1;
        ll tmp = a[i];
        int flg = 0;
        for(j = N; ~j; --j)
            if(tmp>>j&1) {
                if(base[j]) tmp ^= base[j];
                else {
                    flg = 1;
                    break;
                }
            }
        if(!flg) continue;
        for(j = N; ~j; --j)
        if(a[i]>>j&1) {
            if(base[j]) a[i] ^= base[j], da ^= d[j];
            else {
                base[j] = a[i];
                d[j] = da;
                break;
            }
        }
    }
}
long long A = 0, B = 0;

bool h[MN];
long long get(long long x) {
    long long ret = 0;
    for(int i = 63; ~i; --i) {
        int bi = (x>>i)&1;
        if(!h[i]) ret = ret<<1|bi;
        else ret = ret<<1;
    }
    return ret;
}

int main() {
    n = read();
    A = 0, B = 0;
    for(int i = 1; i <= n; ++i) {
        long long x = read();
        c[i] ^= x;
        A ^= x;
    }
    for(int i = 1; i <= n; ++i) {
        long long x = read();
        c[i] ^= x;
        B ^= x;
    }
    memset(h, 0, sizeof h);
    for(int i = 63; ~i; --i) {
        int _a = A>>i&1, _b = B>>i&1;
        if(_a != _b) {
            h[i] = 1;
        }
    }
    for(int i = 1; i <= n; ++i) {
        a[i] = get(c[i]);
    }
    // ll tmp = A, pos = B;
    A = get(A); B = get(B);
    calc();
    da.reset();
    for(int i = 63; ~i; --i) {
        int _a = A>>i&1, _b = B>>i&1;
        if(_a == 0 && _b == 0) {
            // 1
            if(base[i]) {
                A ^= base[i];
                B ^= base[i];
                da ^= d[i];
            }
        }
        else if(_a == 1 && _b == 1) {
            // 0
            // nothing happened
        }
    }
    long long _ = 0;
    for(int i = 63; ~i; --i) {
        _ = (_<<1)|h[i];
    }

    printf("%lld %d\n", A + B + _, da.count());
    for(int i = 1; i <= n; ++i) {
        if(da[i] == 1) printf("%d ", i);
    }
    return 0;
}