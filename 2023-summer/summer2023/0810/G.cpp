#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int o, k;
    cin >> o >> k;
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<ll> qz(n + 5, 0), f(n + 5, 0), g(n + 5, 0), pr(n + 5, 0);
    for(int i = 0; i < n; ++i) {
        qz[i + 1] = qz[i] + ((s[i] == 'o') ? o : k);
    }
    for(int i = 1; i <= n; ++i) {
        f[i] = max(f[i], f[i - 1]);
        f[i] = max(f[i], pr[i - m] + (qz[i] - qz[i - m]) / g[i]);
        pr[i] = max(pr[i - 1], f[i]);
    }
    cout << f[n] << "\n";
    return 0;
}