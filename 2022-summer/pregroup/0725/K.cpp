#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
#define mod 123456789
int Add(int x, int y){return (x + y) % mod;}
#define MN 1000005
int L, S;
int f[MN], p[MN];
int main() {
    L = read(), S = read();
    p[1] = f[1] = 1;
    for(int i = 2; i <= L; ++i) {
        f[i] = Add(p[i - 1], mod - p[max(0, i - S - 1)]);
        p[i] = Add(p[i - 1], f[i]);
    }
    int ans = 0;
    for(int i = 1; i <= S; ++i) {
        ans = Add(ans, Add(p[L - i + 1], mod - p[L - S]));
    } 
    return 0 * printf("%d\n", ans);
}