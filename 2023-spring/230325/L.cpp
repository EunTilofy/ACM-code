#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, st, k;
    cin >> n >> st >> k;
    double ans = st;
    vector<double> p(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        p[i] = 1.0 * i * (i - 1) + (0.5 * (i + n) + 1) / 2.0 * (n - i + 1);
        // cerr << p[i] << "\n";
        p[i] /= 1.0 * n;
        // cerr << i << " " << p[i] << "\n";
    }
    // cerr << "xxx\n";
    
    for(int i = 1; i <= k; ++i) {
        double pos = (int)ans;
        double tmp = pos * (pos - 1) + ((pos + n) / 2.0 + 1) / 2.0 * (n - pos + 1);
        ans = tmp / n;
        // cerr << pos << " " << ans << "\n";
    }
    cout << ans << endl;
    return 0;
}