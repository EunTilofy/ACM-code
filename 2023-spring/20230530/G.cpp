#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll> > a(n);
    for(int i = 0; i < n; ++i) {
        ll x; cin >> x;
        a[i] = {x - i, -x};
    }
    sort(all(a));
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        int j = i;
        for(; j + 1 < n && a[j + 1].first == a[j].first; ++j);
        for(int k = i; k < j; k += 2) {
            ll pos = -(a[k].second + a[k + 1].second);
            if(pos > 0) ans += pos;
        }
        i = j;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}