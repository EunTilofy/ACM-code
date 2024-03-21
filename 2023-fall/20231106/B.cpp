#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10, mod = 1e9 + 7;
int jc[N], ny[N];

int mul(int  x, int y) {
    return 1ll * x * y % mod;
}

int q_pow(int x, int y) {
    int ans = 1;
    for(; y; y >>= 1) {
        if(y & 1) ans = mul(ans, x);
        x = mul(x, x);
    }
    return ans;
}

int C(int n, int m) {
    return mul(jc[n], mul(ny[m], ny[n - m]));
}

void solve() {
    int n, m;
    cin >> n >> m;
    if(n > m) swap(n, m);
    if(m == 1) {
        cout << "1\n";
        return ;
    }
    if(n == 1) {
        cout << "2\n";
        return ;
    }
    cout << 4ll * C(n + m - 2, n - 1) % mod << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    jc[0] = ny[0] = 1;
    for(int i = 1; i < N; ++i) jc[i] = mul(jc[i - 1], i);
    ny[N - 1] = q_pow(jc[N - 1], mod - 2);
    for(int i = N - 2; i >= 1; --i) ny[i] = mul(ny[i + 1], i + 1);
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
        solve();
    }
}