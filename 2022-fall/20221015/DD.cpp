#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

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

const int B = 100000000, MAXL = 60;
struct Num {
    int a[MAXL], len, fu;
    Num() {len = 1, fu = a[1] = 0;}
    Num operator + (Num b) {
        Num c;
        c.len = max(len, b.len) + 2;
        int i;
        for(i = 1; i <= c.len; i ++) c.a[i] = 0;
        if(fu == b.fu) {
            for(i = 1; i <= len; ++i) c.a[i] = a[i];
            for(i = 1; i <= b.len; ++i) c.a[i] += b.a[i];
            for(i = 1; i <= c.len; ++i) if(c.a[i] >= B) c.a[i + 1]++, c.a[i] -= B;
            while(c.len > 1 && !c.a[c.len]) c.len--;
            c.fu = fu;
        } else {
            bool flag = 0;
            if(len == b.len) {
                for(i = len;i;--i)if(a[i]!=b.a[i]) {
                    if(a[i] > b.a[i]) flag = 1;
                    break;
                }
            } else if(len > b.len) flag = 1;
            if(flag) {
                for(i=1;i<=len;++i) c.a[i]=a[i];
                for(i=1;i<=b.len;++i) c.a[i] -= b.a[i];
                for(i=1;i<=c.len;++i) if(c.a[i]<0) c.a[i+1]--,c.a[i]+=B;
                while(c.len>1&&!c.a[c.len]) c.len--;
                c.fu = fu;
            }
            else {
                for(i=1;i<=b.len;++i) c.a[i]=b.a[i];
                for(i=1;i<=len;++i) c.a[i]-=a[i];
                for(i=1;i<=c.len;++i)if(c.a[i]<0)c.a[i+1]--,c.a[i]+=B;
                while(c.len>1&&!c.a[c.len]) c.len--;
                c.fu = b.fu;
            }
        }
        return c;
    }

    Num operator - (Num b) {
        b.fu ^= 1;
        return *this + b;
    }

    Num operator * (Num b) {
        Num c;
        c.len = len + b.len + 2;
        c.fu = fu ^ b.fu;
        int i,j;
        for(i=1;i<=c.len;++i) c.a[i] = 0;
        for(i=1;i<=len;++i) for(j=1;j<=b.len;++j) {
            c.a[i+j-1] += a[i] * b.a[j];
            if(c.a[i+j-1]>=B) {
                c.a[i+j] += c.a[i+j-1]/B; c.a[i+j-1]%=B;
                if(c.a[i+j]>=B) c.a[i+j+1]+=c.a[i+j] / B, c.a[i+j] %= B;
            }
        }
        while(c.len > 1 && !c.a[c.len]) c.len--;
        return c;
    }
    void write() {
        if(len==1 && !a[1]) fu = 0;
        if(fu) putchar('-');
        printf("%lld", a[len]);
        for(int i = len - 1;i;--i) printf("%08lld",a[i]);
        puts("");
    }
    void set(int b) {
        this->len = 1;
        this->fu = 0;
        this->a[1] = b;
    }
    Num operator ^(int b) {
        Num c, x = *this;
        c.set(1);
        while(b) {
            if(b & 1) c = c * x;
            x = x * x;
            b >>= 1;
        }
        return c;
    }
}S[105][105], d[105][105], A[105], C[105][105], _num[105];
int siz[15];
std::bitset<105> a[15];
bool co[15][15];
bool in[15];
int fa[15];
int getf(int x) {
    return x==fa[x]?x:fa[x]=getf(fa[x]);
}
int union_(int x,int y) {
    x = getf(x);
    y = getf(y);
    if(x == y) return 0;
    else fa[x] = y;
    return 1;
}

int n;

Num cal(int m, int l) {
    Num ret;
    REP(p, 1, m + 1) {
        Num nm;
        REP(i, 0, n - l + 1) {
            nm = nm + C[n-l][i] * A[n-l-i] * (_num[p]^i);
        }
        ret = ret + nm * S[m][p];
    }
    return ret;
}

signed main() {
    freopen("partitions.in", "r", stdin);
    freopen("partitions.out", "w", stdout);
	n = read();
    int M = read();
    REP(i, 1, M + 1) {
        siz[i] = read();
        REP(j, 0, siz[i]) {
            a[i][read()] = 1;
        }
    }
    REP(i, 1, M + 1) REP(j, 1, M + 1) if(i != j){
        int nm1 = a[i].count();
        int nm2 = a[j].count();
        co[i][j] = (a[i]|a[j]).count() < nm1 + nm2;
    }
    S[0][0].set(1);
    S[1][0].set(0);
    S[1][1].set(1);
    REP(i, 1, 105) _num[i].set(i);
    REP(i, 2, n + 1) {
        S[i][0].set(0);
        S[i][i].set(1);
        REP(j, 1, i) {
            S[i][j] = _num[j] * S[i - 1][j] + S[i - 1][j - 1]; 
        }
    }

    C[0][0].set(1);
    REP(i, 1, n + 1) {
        C[i][0] = C[i][i] = _num[1];
        REP(j, 1, i) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    A[0].set(1);
    REP(i, 1, n + 1) {
        A[i].set(0);
        REP(j, 0, i + 1) A[i] = A[i] + S[i][j];
    }

    Num Ans = A[n];

    int ALL = 1<<M;
    REP(Set, 1, ALL) {
        int Block = 0, num = 0;
        REP(i, 0, M) Block += (in[i + 1] = Set>>i&1);
        REP(i, 1, M + 1) fa[i] = i;
        num = Block;
        std::bitset<105> _;
        _.reset();
        REP(i, 1, M + 1) if(in[i]) _ |= a[i];
        REP(i, 1, M + 1) REP(j, i + 1, M + 1) if(in[i] && in[j] && co[i][j]) Block -= union_(i, j);
        int l = _.count();
        if(num & 1) {
            // cal(Block,l).write();
            Ans = Ans - cal(Block,l);
        }
        else{
            Ans = Ans + cal(Block,l);
        }
    }
    Ans.write();
    return 0;
}