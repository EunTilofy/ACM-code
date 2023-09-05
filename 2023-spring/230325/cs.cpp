#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, st, k;
    cin >> n >> st >> k;
    double ans = 0.0;
    for(int i = 1; i <= k; ++i) {
        double pos = (int)ans;
        double tmp = pos * (pos - 1) + ((pos + n) / 2.0 + 1) / 2.0 * (n - pos + 1);
        ans = tmp;
    }
    cout << ans << endl;
    return 0;
}