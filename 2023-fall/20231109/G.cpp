#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = n - 1; i >= n - k; --i) {
        ans += a[i];
    }
    cout << ans << "\n";
    return 0;
}