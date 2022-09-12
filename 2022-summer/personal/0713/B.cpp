#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int P = 1e9 + 7;
const int MN = 1.4e7 + 5;
int inv[MN], fac[MN];
int Mul(int x, int y) {return 1ll * x * y % P;}
int Add(int x, int y) {return (x + y) % P;}
int _2[50], _3[50];
int INV(int x, int y) {
    int r = 1;
    for(; y; y >>= 1, x = Mul(x, x)) if(y & 1) {r = Mul(r, x);}
    return r;
}
int C(int x, int y) {
    return Mul(inv[y], Mul(fac[x], inv[x - y]));
}
int Cal(int n, int step) {
    int res = 1, num = 0;
    for(int i = step; i; --i) {
        res = Mul(res, C(_3[step] - _3[i - 1] - num, _2[i] - _2[i - 1]));
        num += _2[i] - _2[i - 1];
    }
    res = Mul(res, _3[step] - 1 - num);
    int rres = 1; num = 0;
    for(int i = step; i; --i) {
        rres = Mul(rres, C(n - _3[i - 1] - num, _2[i] - _2[i - 1]));
        num += _2[i] - _2[i - 1];
    }
    rres = Mul(rres, n - 1 - num);
    return Mul(res, INV(rres, P - 2));
}
int main() {
    int n = read(); int i;
    for(fac[0] = i = 1; i <= n; ++i) fac[i] = Mul(fac[i - 1], i);
    for(inv[0] = inv[1] = 1, i = 2; i <= n; ++i) inv[i] = Mul(inv[P % i], (P - P / i));
    for(i = 1; i <= n; ++i) inv[i] = Mul(inv[i - 1], inv[i]);
    int a = 1, b = 1, step = 0, ans = 0;
    for(int i = _2[0] = _3[0] = 1; i < 50; ++i) {
        _2[i] = _2[i - 1] * 2;
        _3[i] = _3[i - 1] * 3;
    }
    while(a < n) {
        ++step;
        if(step > 0) ans = Add(ans, Cal(n, step));
        a *= 3;b *= 2;
        a = min(a, n);
        b = min(b, n);
    }
    ans = Add(step, P - ans);
    printf("%d\n", ans);
    return 0;                                                                                                                                                                                                                                                                                                                                                        
}