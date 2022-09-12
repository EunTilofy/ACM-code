#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    int x = 0, f = 1;char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1e6+5;
#define nn 1000001
int n;
struct node{
    int p, q, x, y;
    int rk;
}a[MN];
int id[MN];
bool cmp1(int x, int y) {return a[x].y > a[y].y;}
bool cmp2(int x, int y) {return a[x].x > a[y].x || (a[x].x == a[y].x && a[x].p < a[y].p);}
long long t[MN], t1[MN], t2[MN], t3[MN], t4[MN], t5[MN], t6[MN];
void C(int x, int y){for(;x <= n; x += (x & (-x))) t[x] += y; return;}
long long G(int x){long long r = 0;for(; x; x -= (x & (-x))) r += t[x]; return r;}
void C1(int x, int y){for(;x <= n; x += (x & (-x))) t1[x] += y; return;}
long long G1(int x){long long r = 0;for(; x; x -= (x & (-x))) r += t1[x]; return r;}
void C2(int x, int y){for(;x <= n; x += (x & (-x))) t2[x] += y; return;}
long long G2(int x){long long r = 0;for(; x; x -= (x & (-x))) r += t2[x]; return r;}
void C3(int x, int y){for(;x <= nn; x += (x & (-x))) t3[x] += y; return;}
long long G3(int x){long long r = 0;for(; x; x -= (x & (-x))) r += t3[x]; return r;}
void C4(int x, int y){for(;x <= nn; x += (x & (-x))) t4[x] += y; return;}
long long G4(int x){long long r = 0;for(; x; x -= (x & (-x))) r += t4[x]; return r;}
void C5(int x, int y){for(;x <= nn; x += (x & (-x))) t5[x] += y; return;}
long long G5(int x){long long r = 0;for(; x; x -= (x & (-x))) r += t5[x]; return r;}
void C6(int x, int y){for(;x <= nn; x += (x & (-x))) t6[x] += y; return;}
long long G6(int x){long long r = 0;for(; x; x -= (x & (-x))) r += t6[x]; return r;}
signed main() {
    n = read();
    for(int i = 1; i <= n; ++i) a[i].p = read();
    for(int i = 1; i <= n; ++i) a[i].q = read();
    for(int i = 1; i <= n; ++i) {
        id[i] = i;
        a[i].x = a[i].p + a[i].q;
        a[i].y = a[i].q - a[i].p;
    }
    std::sort(id + 1, id + n + 1, cmp1);
    int now = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[id[i]].y != a[id[i - 1]].y || i == 1) a[id[i]].rk = ++now;
        else a[id[i]].rk = now;
    }
    std::sort(id + 1, id + n + 1, cmp2);
    long long ans = 0;
    int j = 0;
    for(int i = 1; i <= n; ++i) {
        int o = id[i];
        int num1 = G(a[o].rk);
        int num2 = j - num1;
        ans -= 1ll * a[o].p * num1 + 1ll * a[o].q * num2;
        long long sum1 = G1(a[o].rk), sum2 = G2(n - a[o].rk);
        ans += sum1 + sum2;

        int num3 = G3(a[o].p);
        int num4 = G5(a[o].q);
        ans += 2ll * a[o].p * num3 + 2ll * a[o].q * num4;
        long long sum3 = G4(a[o].p), sum4 = G6(a[o].q);
        ans -= 2ll * sum3 + 2ll * sum4;

        if(a[id[i]].x != a[id[i + 1]].x || i == n) {
            for(int k = j + 1; k <= i; ++k) {
                C(a[id[k]].rk, 1);
                C1(a[id[k]].rk, a[id[k]].p);
                C2(n - a[id[k]].rk + 1, a[id[k]].q);
                C3(a[id[k]].p, 1);
                C4(a[id[k]].p, a[id[k]].p);
                C5(a[id[k]].q, 1);
                C6(a[id[k]].q, a[id[k]].q);
                ans += 1ll * a[id[k]].p * (2 * k - j - 1 - i);       
            }
            j = i;
        }
    }
    printf("%lld\n", ans << 1);
    return 0;
}