#include<bits/stdc++.h>
using namespace std;

const int MN = 10005;
unsigned long long L[MN], R[MN];
bool L0[MN], R0[MN];
unsigned long long p[MN];
bool b[MN][MN];
unsigned long long a[MN];
unsigned long long pw[66];

unsigned msb(unsigned long long x)
{
    return 63 - __builtin_clzll(x);
}
unsigned long long get(int x, int y) {
    return p[y]^p[x-1];
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) p[i] = p[i-1] ^ a[i];
    b[1][n] = 1;
    if(get(1, n) == 0) L0[1] = R0[n] = 1;
    else {
        int c = msb(get(1, n));
        // cerr << c << " " << get(1, n) << " " << pw[c] << "\n";
        L[1] |= pw[c];
        R[n] |= pw[c];
    }
    for(int len = n-1; len >= 1; --len) {
        for(int i = 1, j = len; j <= n; ++i, ++j) {
            if(L0[i]||R0[j]||(get(i,j)&L[i])||(get(i,j)&R[j])) {
                b[i][j] = 1;
                if(get(i, j) == 0) L0[i] = R0[j] = 1;
                else {
                    int c = msb(get(i,j));
                    L[i] |= pw[c];
                    R[j] |= pw[c];
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i) if(b[i][i]) cout << "1"; else cout << "0";
    cout << "\n";
    for(int i = 0; i <= n; ++i) {
        L0[i] = R0[i] = 0, L[i] = R[i] = 0;
        for(int j = i; j <= n; ++j) b[i][j] = 0;
        p[i] = a[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    pw[0] = 1;
    for(int i = 1; i <= 66; ++i) pw[i] = 1ll * pw[i-1] * 2ll;
    while(T--) {
        solve();
    }
}