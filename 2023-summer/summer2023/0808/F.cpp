#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long double A, B, P, Q;
    cin >> A >> B >> P >> Q;
    P /= 100.0, Q /= 100.0;
    vector<long double> f(A + 1, 0);
    for(int i = 1; i <= A; ++i) {
        if(i >= B) {
            if(B == 1) {
                double pos = (Q + (f[i - 1] + 1) * (1 - Q)) / (1 - Q);
                double tmp = f[i - B] + 1.0 - P + 2.0 * P;
                f[i] = max(pos, tmp);
            } else {
                f[i] = max(f[i - B] + 1.0 - P + 2.0 * P, (f[i - B + 1] + 1.0) * Q + (f[i - B] + 1.0) * (1.0 - Q));
            }
        }
    }
    long double ans = 0.0;
    for(int i = 1; i <= A; ++i) ans = max(ans, f[i]);
    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}