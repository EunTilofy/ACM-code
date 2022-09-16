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
#define int long long
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
int num[15], tot = 0;
ll getr(ll x) {
    tot = 0;
    while(x) num[++tot] = x%10, x/=10;
    ll y = 0;
    for(int i = 1; i <= tot; ++i) y = y * 10 + num[i];
    return y;
}
bool chk(ll x) {
    if(x%10==0) return false;
    x = getr(x);
    int y = (ll)sqrt(x);
    if(y * y == x) return true;
    if((y - 1) * (y - 1) == x) return true;
    if((y + 1) * (y + 1) == x) return true;
    return false;
}
long long sol(int A) {
    int ans = 0;
    for(int i = 1; 1ll * i * i <= A; ++i) {
        ans += chk(i * i);
    }
    return ans;
}
signed main () {
    // printf("%lld\n", getr(325));
    int A = read(); int B = read();
    // cout<<A<<B;
    printf("%lld\n", sol(B) - sol(A - 1));
    return 0;
}