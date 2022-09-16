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
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define FOr(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
// inline int qpow(int x,ll y,int m=mod){int r=1;for(;y;y>>=1,x=(ll)x*x%m)if(y&1)r=(ll)r*x%m;return r;}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN = 1e6+ 55, mod = 1e9 + 7;
char s[MN];
int a[MN], f[MN];

int add(int x, int y) {
    return (1ll * x + y + mod) % mod;
}
void Add(int &x, int y) {
    x = add(x, y);
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
void Mul(int &x, int y) {
    x = mul(x, y);
}

int cal(int x) {
    if(x <= 0) return 0;
    return add(mul(x, 9), -2);
}

void init() {
    for(int i = 1; i < MN; ++i) f[i] = -1;
}

int dp(int len, int num, int lim) {
    // printf("len = %d, num = %d, lim = %d\n", len, num, lim);
    if(!len) {
        int pos = cal(num);
        // printf("pos = %d\n", pos);
        return pos;
    }
    if(!lim) {
        if(!num && f[len] != -1) return f[len]; 
        int pos = add(mul(10, dp(len - 1,0,0)), add(-cal(len - 1), cal(num + len)));
        if(!num) f[len] = pos;
        return pos;
    }
    int pos = 0;
    for(int i = 0; i <= a[len]; ++i) {
        Add(pos, dp(len - 1, i == 9 ? num + 1 : 0, lim && i == a[len]));
    }
    // printf("!!!len = %d, num = %d, lim = %d\n", len, num, lim);
    // printf("pos = %d\n", pos);
    return pos;
}

int cut(int len) {
    a[1] -= 1;
    for(int i = 1; i <= len; ++i) {
        if(a[i] < 0) {
            a[i] += 10;
            a[i + 1]--;
        }
    }
    for(; len > 1 && !a[len]; --len);
    return len;
}

int js(int len) {
    int ans = 0;
    for(int i = len; i >= 1; --i) {
        Mul(ans, 10);
        Add(ans, a[i]);
    }
    return ans;
}

int main() {
    // for(int o = 1; o <= 1000; ++o) {
    init();
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for(int i = len; i >= 1; --i) {
        a[len - i + 1] = s[i] - '0';
    }
    len = cut(len);
    int ans = js(len);
    // for(int i = len; i >= 1; --i) {
    //     printf("%d", a[i]);
    // }
    // puts("");
    // printf("ans = %d\n", ans);
    int pos = dp(len, 0, 1);
    // printf("pos = %d\n", pos);
    Add(ans, pos);
    printf("%d\n", ans);
    // }
    return 0;
}