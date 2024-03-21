#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &x : a) cin >> x;
    for(int &y : b) cin >> y;
    ll ans = 0;
    for(int i = 1; i < n; ++i) ans += abs(a[i] - a[i - 1]);
    for(int i = 1; i < m; ++i) ans += abs(b[i] - b[i - 1]);
    cout << ans << "\n";
    return 0;
}