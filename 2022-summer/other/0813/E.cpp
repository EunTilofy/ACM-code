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
long long C(int x) {
    return 1ll * x * (x - 1) * (x - 2) / 6ll;
}
int p[MN], tot, num;
int q[MN], num2, num3;
long long solve(int l, int r) {
    long long ret = 0;
    for(int k = l + 2; k <= r; ++k) {
        num = tot = num2 = num3 = 0;
        for(int i = 1; i * i <= k; ++i) if(k % i == 0) {
            num ++;
            if(k / i != i) num ++;
            // else dbg1(i), dbg2(k);
        }
        for(int i = 1; i * i <= k; ++i) if(k % i == 0) {
            p[++tot] = i;
            p[num - tot + 1] = k / i;
        }
        num3 = 1;
        while(num3 < num && p[num3] < l) ++num3;
        if(num - 1 - num3 + 1 >= 2) ret += 1ll * (num - 1 - num3 + 1) * (num - 2 - num3 + 1) / 2;
        //lcm(i, j, k) = 2k && i + j > k
        int x = k, y = 1;
        while(x % 2 == 0) y *= 2, x /= 2;
        for(int i = 1; i < num; ++i) if(p[i] % y == 0) {
            if(p[i] * 2 < k) q[++num2] = p[i] * 2;
        }
        int j1 = 1, j2 = 1;
        int rett = 0;
        for(int i = num2; i; --i) {
            //q[i] + q[j2] > k
            //q[i] + p[j2] > k
            //q[i] != q[j2]
            if(q[i] < l) break;
            if(q[i] >= k) continue;
            if(q[i] + q[i] > k) --rett;
            while(j1 < num && p[j1] + q[i] <= k) ++j1;
            // dbg2(j1);
            while(j2 <= num2 && q[j2] + q[i] <= k) ++j2;
            // dbg2(j2);
            while(p[j1] < l && j1 < num) ++j1;
            while(q[j2] < l && j2 <= num2) ++j2;
            if(num - j1 > 0) ret += num - j1;
            if(num2 - j2 + 1 > 0) rett += num2 - j2 + 1;
        }
        ret += rett / 2;
        // dbg1(rett);
        // dbg2(ret);
    }
    ret = C(r - l + 1) - ret;    
    return ret;
}
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = read();
    while(T--) {
        int l = read();
        int r = read();
        printf("%lld\n", solve(l, r));
    }
    return 0;
}
/*
5
1 4
3 5
8 86
68 86
6 86868
*/