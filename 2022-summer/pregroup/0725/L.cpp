#include<bits/stdc++.h>
using namespace std;
inline long long read() {
    long long x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
long long n, a[20005];
int main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    std::sort(a + 1, a + n + 1);
    if(n < 3) return 0 * puts("impossible");
    for(int i = 1; i + 2 <= n; ++i) {
        if(a[i] + a[i + 1] > a[i + 2]) return 0 * puts("possible");
    }
    puts("impossible");
    return 0;
}