#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double A, B, P, Q;
    cin >> A >> B >> P >> Q;
    P /= 100.0, Q /= 100.0;
    vector<ll> f(A + 1, 0);
    for(int i = 1; i <= A; ++i) {
        if(i >= B) f[i] = max(f[i - B] * 100 + (100 - P) + 2 * P, (f[i - B + 1] + 1) * Q + (f[i - B] + 1) * (100 - Q));
    }
    double ans = 0.0;
    for(int i = 1; i <= A; ++i) ans = max(ans, f[i] / 100.0);
    cout << fixed << setprecision(12) << ans << "\n";
    return 0;
}