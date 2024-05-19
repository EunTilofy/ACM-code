#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
void cmax(int &x, int y) {x  = std::max(x, y);}
const int mod = 998244353;
const int N = 1010;
int pr[N], jc[N], f[N];

int q_pow(int x, int y) {
    int ans = 1;
    for(; y; y >>= 1) {
        if(y & 1) ans = 1ll * ans * x % mod;
        x = 1ll * x * x % mod;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    jc[0] = 1;
    for(int i = 1; i < N; ++i) jc[i] = 1ll * jc[i - 1] * i % mod;
    f[1] = 0, f[2] = 1;
    for(int i = 3; i < N; ++i) f[i] = 1ll * (i - 1) * (f[i - 1] + f[i - 2]) % mod;
    cerr << f[n] << " " << q_pow(jc[m], n) << "\n";
    cout << 1ll * q_pow(f[n], m) * q_pow(jc[m], n) % mod << "\n";
    return 0;
}