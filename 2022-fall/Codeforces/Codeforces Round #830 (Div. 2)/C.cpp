#include<bits/stdc++.h>
#define ll long long
#define int long long
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
long long a[MN], b[MN], c[MN], n, m;

long long chk(int l, int r) {
    return b[r]-b[l-1]-(c[r]^c[l-1]);
}
int getl(int i, int R) {
    int l = i, r = R - 1, k = R;
    long long tmp = chk(i,R);
    while(l <= r) {
        int mid = (l + r) >>1;
        if(b[mid]-b[i-1]-(c[mid]^c[i-1]) == tmp) k = mid, r = mid - 1;
        else l = mid + 1;
    }
    return k-i;
}

signed main() {
    int T = read();
    while(T--) {
        n = read(); m = read();
        REP(i, 1, n + 1) a[i] = read();
        REP(i, 1, n + 1) b[i] = b[i - 1] + a[i];
        REP(i, 1, n + 1) c[i] = c[i - 1] ^ a[i];
        REP(i, 1, m + 1) {
            int l = read();
            int r = read();
            long long ans = b[r] - b[l-1] - (c[r]^c[l-1]);
            int ansl = l, L = l + 1, R = r;
            while(L <= R) {
                int mid = (L+R)>>1;
                if(chk(mid,r)==ans) ansl = mid, L = mid + 1;
                else R = mid - 1;
            }
            int mkl = l, mkr = ansl;
            int Ansl = l;
            while(mkl <= mkr) {
                if(mkr - mkl <= 4) {
                    Ansl = mkl;
                    REP(i, mkl + 1, mkr + 1) if(getl(i,r)<getl(Ansl,r)) Ansl=i;
                    break;
                }
                int mk1 = mkl + (mkr - mkl) / 3;
                int mk2 = mkr - (mkr - mkl) / 3;
                if(getl(mk1, r) <= getl(mk2, r)) mkr = mk2;
                else mkl = mk1;
            }
            int now = getl(Ansl,r);
            for(int i = 0; i < 300; ++i) {
                int I = rand() % (ansl - l + 1) + l;
                if(getl(I,r) < now) {Ansl = I; now = getl(I,r);}
            }
            printf("%lld %lld\n", Ansl, Ansl + now);
        }
    }
    return 0;
}