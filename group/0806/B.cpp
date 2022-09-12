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
int pre, len, cnt[MN], tot, nm[MN], G[MN];
#define get(x) X[(x<=pre?x:(pre+(x-pre)%len))]
ll cal(int l, int r, int L, int R) {
    for(int i = 0; i <= m + 1; ++i) nm[i] = cnt[i] = 0;
    long long ret = 0;
    for(int i = l; i <= r; ++i) ret += 1ll * get(i) * (R - L + 1), ++cnt[get(i)];
    for(int i = m; i >= 0; --i) cnt[i] += cnt[i + 1];
    for(int i = L; i <= R; ++i) {
        long long num = 0;
        if(nm[get(i) + 1]) num = nm[get(i) + 1];
        else for(int k = 1; k * (get(i)+1) <= m; ++k) {
            num += cnt[k * (get(i)+1)];
        }
        ret -= 1ll * (nm[get(i)+1]=num) * (get(i) + 1);
    }
    return ret;
}
int in[MN];
signed main() {
    int T = read();
    for(int o = 1; o <= T; ++o) {
        m = read(), a = read(), c = read();
        X[0] = read(), l1 =read(), r1 = read(), l2 = read(), r2 = read();
        for(int i = 1; i <= m; ++i) {
            X[i] = (1ll * a * X[i - 1] % m + 1ll * c) % m;
            in[i] = -1;
        }
        in[0] = -1;
        tot = 0;
        while(in[X[tot]] == -1) {
            in[X[tot]] = tot;
            ++tot;
        }
        len = tot - in[X[tot]];
        pre = in[X[tot]];
        // dbg1(len); dbg2(pre);
        int num1 = 0, num2 = 0;
        num1 = max(num1, (r1 - max(l1, pre + 1) + 1) / len);
        num2 = max(num2, (r2 - max(l2, pre + 1) + 1) / len);
        int rr = r1 - num1 * len;
        int RR = r2 - num2 * len;

        // dbg1(rr); dbg2(RR);
        // dbg1(num1); dbg2(num2);
        long long ans = 0;
        ans += 1ll * num1 * num2 * cal(pre + 1, tot, pre + 1, tot);
        // dbg2(ans);
        ans += 1ll * num2 * cal(l1, rr, pre + 1, tot);
        // dbg2(ans);
        ans += 1ll * num1 * cal(pre + 1, tot, l2, RR);
        // dbg2(ans);
        ans += 1ll * cal(l1, rr, l2, RR);
        printf("Case #%lld: %lld\n", o, ans);
    }
}
//m,a,c,X0,l1,r1,l2,r2
/*
2
7 1 4 1 2 3 4 5
10 3 6 1 2 3 1 2

1
7 1 4 1 0 8 7 10
*/