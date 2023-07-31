#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll calc(ll a, ll b, ll c) {
    ll x = a;
    if (b < x) x = b;
    if (c < x) x = c;
    return a * a + b * b + c * c + x * 7ll;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        ll a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        if (d > 50) {
            c += d;
            printf("%lld\n", calc(a, b, c));
        } else {
            ll ans = 0;
            for (ll i = 0; i <= d; ++i) {
                for (ll j = 0; i + j <= d; ++j) {
                    ll A = a + i, B = b + j, C = c + (d - i - j);
                    ans = max(ans, calc(A, B, C));
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}