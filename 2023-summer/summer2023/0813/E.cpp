#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MN = 3003;
long long f[MN], g[MN][MN], suf[MN], a[MN];
long long Suf(int l, int r) {
    return suf[l] - suf[r + 1];
}
signed main() {
    freopen("ebola.in", "r", stdin);
    freopen("ebola.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1) {
    int n;
    cin >> n;
    if(n==0) break;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = n; i; --i) suf[i] = suf[i + 1] + a[i];

    for(int i = 1; i <= n; ++i) {
        g[i][i] = 0;
        for(int j = i - 1; j; --j) {
            g[j][i] = g[j+1][i] + min(3ll * (i - j) * a[j] + Suf(j+1, i), 2ll * Suf(j+1, i));
        }
    }

    for(int i = 1; i <= n; ++i) {
        f[i] = g[1][i] + (i + 3ll * (i - 1)) * Suf(i + 1, n);
        for(int j = 1; j < i; ++j) {
            f[i] = min(f[i], f[j] + g[j+1][i] + (i-j+1+3*(i-j-1)) * 1ll * Suf(i+1, n) + Suf(j+1, i));
        }
    }
    cout << f[n] << "\n";
    for(int i = 0; i <= n; ++i) {
        f[i] = 0; suf[i] = 0; a[i] = 0;
        for(int j = 0; j <= n; ++j) g[i][j] = 0;
    }
    }
    return 0;
}