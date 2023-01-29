#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll l = a[i], r = a[i] + d, cur = 0;
        vector<ll> b = a;
        for (ll& x : b) {
            if (x < l) x = l;
            else if (x > r) x = r;
        }
        for (int j = 1; j < n; ++j) cur += abs(b[j] - b[j - 1]);
        ans = max(ans, cur);
        l = a[i] - d, r = a[i], cur = 0;
        b = a;
        for (ll& x : b) {
            if (x < l) x = l;
            else if (x > r) x = r;
        }
        for (int j = 1; j < n; ++j) cur += abs(b[j] - b[j - 1]);
        ans = max(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}
