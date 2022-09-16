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
#define int long long
const int MN = 1e4 + 5;
long long a[MN], s[MN];
bool b[MN][MN];
signed main() {
    int n = read();
    int l = 1;
    for(int i = 1; i <= n; ++i) {
        while(b[l][i]) ++l;
        printf("? %d %d\n", l, i);
        fflush(stdout);
        long long sum = read();
        int L = read(), R = read();
        b[L][R] = 1;
        a[i] = sum - s[i - 1] + s[l - 1];
        s[i] = s[i - 1] + a[i];
    }
    printf("!\n");
    fflush(stdout);
    for(int i = 1; i <= n; ++i) printf("%lld ", a[i]), fflush(stdout);
    printf("\n");
    fflush(stdout);
    return 0;
}