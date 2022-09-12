#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int P = 998244353;
int inv[] = {1, 1, 499122177, 332748118, 748683265};
int Mul(int x, int y){return 1ll * x * y % P;}
int Add(int x, int y){return (x + y) % P;}
int C(int x, int y) {
    int ret = 1;
    for(int i = 1; i <= y; ++i) ret = Mul(ret, x - i + 1);
    for(int i = 1; i <= y; ++i) ret = Mul(ret, inv[i]);
    return ret;
}
int main() {
    int W, H;
    W = read(), H = read();
    int ans = 0;
    ans = Add(ans, Mul(11, Mul(C(W, 4), C(H, 4))));
    ans = Add(ans, Mul(6, Mul(C(W, 4), C(H, 3))));
    ans = Add(ans, Mul(6, Mul(C(W, 3), C(H, 4))));
    ans = Add(ans, Mul(1, Mul(C(W, 4), C(H, 2))));
    ans = Add(ans, Mul(1, Mul(C(W, 2), C(H, 4))));
    printf("%d\n", ans);
    return 0;
}