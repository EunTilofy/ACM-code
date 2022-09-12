#include<bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
    while(ch >='0' && ch <='9'){x = (x << 1) + (x << 3) + ch -'0'; ch = getchar();}
    return x * f;
}
int n, m, T;
const int MN = 1e5 + 5;
int p[MN], t[MN], id[MN];
bool cmp(int x, int y) {return p[x] > p[y];}
int main() {
    n = read();
    m = read();
    T = read();
    for(int i = 1; i <= n; ++i) p[i] = read(), t[i] = read();
    for(int i = 1; i <= n; ++i) id[i] = i;
    std::sort(id + 1, id + n + 1, cmp);
    long long ans = 0, sum = 1ll * m * T;
    for(int i = 1; i <= n; ++i) {
        ans += p[id[i]] * min(sum, (long long)t[id[i]]);
        sum = max(0ll, sum - t[id[i]]);
    } 
    return 0 * printf("%lld\n", ans);
}