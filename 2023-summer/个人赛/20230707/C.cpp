#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int mul(int x, int y) {
    return (1ll * x * y) % mod;
}
int add(int x, int y) {
    return (x + y) % mod;
}
int inv[5];
int C(int n, int m) {
    int ret = 1;
    for(int i = 1; i <= m; ++i) {
        ret = mul(ret, mul(inv[i], n-i+1));
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    inv[1] = 1; inv[2] = (mod + 1)/2, inv[3] = (mod + 1)/3, inv[4] = (1ll * 3 * mod + 1)/4;
    int n, m;
    cin >> n >> m;
    int ans = add(add(mul(mul(C(n, 4), C(m, 2)), C(m, 2)), mul(mul(C(m, 4), C(n, 2)), C(n, 2))), 998244353 - mul(C(n, 4), C(m, 4)));
    cout << ans;
    return 0;
}