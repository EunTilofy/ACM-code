#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
int n;
long long k;
int a[MN];
int mi[19][MN], ma[19][MN], lg[MN];
int getmin(int l, int r) {
    int o = lg[r - l + 1];
    return min(mi[o][l], mi[o][r - (1 << o) + 1]);
}
int getmax(int l, int r) {
    int o = lg[r - l + 1];
    return max(ma[o][l], ma[o][r - (1 << o) + 1]);
}
long long get(int l, int r) {
    return 1ll * (r - l + 1) * (getmax(l, r) - getmin(l, r));
}
int getint(void) {
    int ch = getchar(), res = 0, flg = 0;
    while (!isdigit(ch) && ch != '-')
        ch = getchar();
    if (ch == '-')
        flg = 1, ch = getchar();
    for (; isdigit(ch); ch = getchar())
        res = (res << 1) + (res << 3) + (ch - '0');
    return flg ? -res : res;
}
bool chk(long long x) {
    long long _ = 0;
    int j = 1;
    for (int i = 1; i <= n; ++i) {
        while (get(i, j) <= x && j <= n)
            ++j;
        if (j <= n)
            _ += (n + 1 - j);
    }
    // printf("%lld %lld\n", x, _);
    return _ < k;
}
signed main() {
    n = getint();
    scanf("%lld", &k);
    for (int i = 1; i <= n; ++i)
        a[i] = getint();
    {
        int i, j;
        for (i = 1, j = 0; i <= n; i <<= 1, j++)
            lg[i] = j;
    }
    for (int i = 1; i <= n; ++i)
        lg[i] = max(lg[i - 1], lg[i]);
    for (int i = 1; i <= n; ++i)
        mi[0][i] = ma[0][i] = a[i];
    for (int j = 1; j <= 18; ++j)
        for (int i = 1; i <= n; ++i)
            if (i + (1 << j) - 1 <= n) {
                mi[j][i] = min(mi[j - 1][i], mi[j - 1][i + (1 << (j - 1))]);
                ma[j][i] = max(ma[j - 1][i], ma[j - 1][i + (1 << (j - 1))]);
            }
    long long l = 0, r = 1000000000000000ll, ans, mid;
    while (l <= r) {
        // printf("%lld %lld\n", l, r);
        mid = (l + r) >> 1;
        if (chk(mid))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}