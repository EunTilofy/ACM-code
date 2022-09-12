#include<bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
    while(ch >='0' && ch <='9'){x = (x << 1) + (x << 3) + ch -'0'; ch = getchar();}
    return x * f;
}
const int MN = 1e6 + 5;
const int P = 998244353;
int inv[MN<<1], fac[MN<<1];
int f1[MN], f2[MN];
int Mul(int x, int y) {return 1ll * x * y % P;}
int Add(int x, int y) {return (x + y) % P;}
int C(int x, int y) {
    if(x < y) return 0;
    return Mul(fac[x], Mul(inv[y], inv[x - y]));
}
int main() {
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for(int i = 2; i <= 2000000; ++i) {
        inv[i] = Mul(inv[P % i], (P - P / i));
        fac[i] = Mul(fac[i - 1], i);
    }
    for(int i = 2; i <= 2000000; ++i) inv[i] = Mul(inv[i - 1], inv[i]);
    f1[0] = f1[1] = 1;
    for(int i = 2; i <= 1000000; ++i) f1[i] = Add(C(2 * i, i), P - C(2 * i, i - 1));
    f2[0] = f2[1] = 1;
    for(int i = 2; i <= 1000000; ++i) f2[i] = Add(f2[i - 1], f2[i - 2]);
    int T = read();
    while(T --) {
        int n = read();
        printf("%d %d\n", f1[n], f2[n]);
    }
    return 0;
}