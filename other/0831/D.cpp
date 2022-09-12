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
int a[MN], n;
int t[MN * 50][2], f[MN * 50][2];
int cnt = 1;
void ins(int val, int id, int _) {
    int p = 1;
    for(int i = 30; ~i; --i) {
        int o = (val>>i&1) ^ (id>>i&1);
        if(!t[p][o]) t[p][o] = ++cnt;
        p = t[p][o];
        f[p][val>>i&1] = max(f[p][val>>i&1], _);
    }
}
int get(int val, int id) {
    int p = 1;
    int ret = 0;
    for(int i = 30; ~i; --i) {
        int o = (val>>i&1) ^ (id>>i&1);
        // a ^ d < b ^ c
        //if (a ^ b == 0 && c ^ d == 0) 
        //if (a ^ b == 0 && c ^ d == 1) -> a != c
        //if (a ^ b == 1 && c ^ d == 1)
        //if (a ^ b == 1 && c ^ d == 0) -> a == c
        ret = max(ret, f[t[p][o ^ 1]][(val>>i&1) ^ o ^ 1]);
        p = t[p][o];
    }
    return ret;
}
signed main() {
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int T = read();
    while(T --) {
        n = read();
        REP(i, 1, n + 1) a[i] = read();
        // ins(a[n], 0, 1);
        int ans = 1;
        cnt = 1;
        DREP(i, n, 0) {
            int _ = get(a[i], i - 1) + 1;
            ins(a[i], i - 1, _);
            ans = max(ans, _);
        }
        printf("%d\n", ans);
        REP(i, 1, cnt + 1) t[i][0] = t[i][1] = f[i][0] = f[i][1] = 0;
    }
    return 0;
}