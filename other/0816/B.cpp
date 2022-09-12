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
ll a[MN], b[MN], c[MN], n, m;
std::map<long long, int> mp;
signed main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int T = read();
    b[0] = b[1] = 1;
    c[0] = 1;c[1] = 2;
    mp[1] = 0; mp[2] = 1;
    REP(i, 2, 100) {
        b[i] = b[i - 1] + b[i - 2];
        c[i] = c[i - 1] + b[i];
        mp[c[i]] = i;
        if(b[i] > 1000000000ll) {m = i - 1; break;}
    }
    while(T--) {
        n = read();
        ll sum = 0;
        REP(i, 1, n + 1) a[i] = read(), sum += a[i];
        if(!mp.count(sum)) {puts("NO"); continue;}
        int all = mp[sum];
        int last = -1, flg = 1;
        DREP(i, all , 1) {
            int id = -1, mx = -inf;
            REP(j, 1, n + 1) if(mx < a[j] && j != last) id = j, mx = a[j];
            if(id == last) {flg = 0; break;}
            if(a[id] < b[i]) {flg = 0; break;}
            a[id] -= b[i]; last = id;
        }
        REP(i, 1, n + 1) if(a[i] == 2) {flg = 0; break;}
        if(flg) puts("YES");
        else puts("NO");
    }
    return 0;
}