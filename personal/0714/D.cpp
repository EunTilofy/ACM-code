#include<bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
    while(ch >='0' && ch <='9'){x = (x << 1) + (x << 3) + ch -'0'; ch = getchar();}
    return x * f;
}
int a, b, m, n, p;
int fpow(int x, int y, int P) {
    int r = 1;
    for(; y; y >>= 1, x = 1ll * x * x % P) if(y & 1) {r = 1ll * r * x % P;}
    return r;
}
int main() {
    a = read(), b = read(), m = read(), n = read(), p = read();
    int g = __gcd(m, n);
    printf("%d\n", (fpow(a, g, p) + p - fpow(b, g, p)) % p);
    return 0;
}