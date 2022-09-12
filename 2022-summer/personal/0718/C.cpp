#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
#define P 998244353
#define Mul(x, y) (1ll * (x) * (y) % P)
#define Add(x, y) (((x) + (y)) % P)
#define MN 100000020
int fac[MN], inv[MN], inva[MN], c[10];
int main() {
    int n = read();
    int i;
    for(i = fac[0] = 1; i <= n + 10; ++i) fac[i] = Mul(fac[i - 1], i);
    for(inv[0] = inv[1] = 1, i = 2; i <= n + 10; ++i) inv[i] = Mul((P - P / i), inv[P % i]);
    for(inva[0] = i = 1; i <= n + 10; ++i) inva[i] = Mul(inva[i - 1], inv[i]);
    int ans = 0;
    int cal, pre = Mul(inv[10], inva[n]);
    for(int i = 1; i < 10; ++i) c[i] = Mul(i, Mul(inva[i], inva[9 - i]));
    for(int k = 1; k <= n; ++k) {
        pre = Mul(Mul(pre, 10), Mul(inv[k - 1], n - k + 1));
        cal = 0;
        for(int i = 1; i <= 9; ++i) {
            cal = Add(cal, Mul(c[i], Mul(fac[9 - i + k - 1], fac[i + n - k])));
        }
        ans = Add(ans, Mul(cal, pre));
    }
    printf("%d\n", ans);
    return 0;
}