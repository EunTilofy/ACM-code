#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >='0' && ch <='9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1e6 + 5;
int ch[MN * 31][2], tot;
int t[MN * 31];
long long num[32][2];
void add(int x, int now, int step) {
    bool k = (x >> step) & 1;
    num[step][k] += ch[now][k ^ 1] ? t[ch[now][k ^ 1]] : 0;
    if(!ch[now][k]) ch[now][k] = ++tot;
    ++t[ch[now][k]];
    if(step == 0) return ;
    add(x, ch[now][k], step - 1);
}
int main() {
    int cas = read();
    while(cas --) {
        for(int i = 1; i <= tot; ++i) {
            memset(ch[i], 0, sizeof ch[i]);
            t[i] = 0;
        }
        memset(num, 0, sizeof num);
        int n, q;
        n = read(), q = read(); tot = 1;
        for(int i = 1; i <= n; ++i) {
            int x = read();
            add(x, 1, 30);
        }
        long long ans = 0;
        for(int i = 1; i <= q; ++i) {
            int x = read();
            ans = 0;
            for(int i = 30; ~i; --i) {
                int k = (x >> i) & 1;
                ans += num[i][k];
                // printf("%d + ", num[i][k]);
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}