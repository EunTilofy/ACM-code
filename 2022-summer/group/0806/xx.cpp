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
#define FOR(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;++i)
#define DFOR(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;--i)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define mod 998244353
#define int long long
inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e6+ 55;
int m, a, c, X[MN], l1, r1, l2, r2;
int cnt[MN], tot;
bool in[MN];
ll cal(int l, int r, int L, int R) {

    // dbg1(l); dbg1(r); dbg1(L); dbg2(R);

    if(l>r||L>R) return 0;
    for(int i = 0; i <= m; ++i) cnt[i] = 0;
    long long ret = 0;
    for(int i = l; i <= r; ++i) ret += 1ll * X[i%tot] * (R - L + 1), ++cnt[X[i%tot]];
    for(int i = m - 1; i >= 0; --i) cnt[i] += cnt[i + 1];

    // dbg2(ret);

    for(int i = L; i <= R; ++i) {
        long long num = 0;
        for(int k = 1; k * (X[i%tot]+1) <= m; ++k) {
            num += cnt[k * (X[i%tot]+1)];
        }
        // dbg1(num); dbg2(X[i%tot] + 1);
        ret -= 1ll * num * (X[i%tot] + 1);
    }
    return ret;
}
int getr(int l, int r) {
    return rand() % (r - l) + l;
}
signed main() {
    srand(time(NULL));
    cout<<"1"<<endl;
    m = rand() % 1000000;
    cout<<m;
    int a = rand() % m;
    int c = rand() % m;
    int X0 = rand() % m;
    cout<<" "<<a<<" "<<c<<" "<<" "<<X0<<" ";
    l1 = getr(0, 100);
    l2 = getr(0, 100);
    r1 = getr(l1, 100);
    r2 = getr(l2, 100);
    cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<endl;
}
//m,a,c,X0,l1,r1,l2,r2
/*
2
7 1 4 1 2 3 4 5
10 3 6 1 2 3 1 2

1
7 1 4 1 0 8 7 10
*/

