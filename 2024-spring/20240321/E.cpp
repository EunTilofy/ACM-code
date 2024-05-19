#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
        int n;
        cin >> n;
        vector<ll> a(2 * n);
        for(ll &x : a) cin >> x;
        sort(all(a));
        ll ans = 0;
        for(int i = 0; i < n; ++i) ans -= a[i];
        for(int i = n; i < 2 * n; ++i) ans += a[i];
        cout << ans << "\n";
    }
    return 0;
}