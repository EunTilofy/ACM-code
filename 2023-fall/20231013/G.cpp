#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
const int mod = 998244353;
int fpow(int x, int y) {
    int r = 1;
    for(;y;x=1ll*x*x%mod, y>>=1)if(y&1)r=1ll*r*x%mod;
    return r;
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int add(int x, int y) {
    return (x + y) % mod;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, bs = fpow(100, mod - 2);
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n);
    for(int i = 0; i < n - 1; ++i) {
        cin >> p[i];
    }
    p[n - 1] = 100;
    for(int &x : p) x = mul(x, bs);
    int ans = 0, sum = 0;
    for(int i = 0; i < n; ++i) {
        sum = (sum + (s[i] - '0')) % mod;
        ans = (ans + mul(sum, p[i])) % mod;
        sum = mul(sum, mod + 1 - p[i]);
        sum = mul(sum, 10);
    }
    cout << ans << "\n";
    return 0;
}