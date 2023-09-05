#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;
const int N = 1e5 + 10;
pair<ll, ll> a[N];
int n;
bool cmp(int x, int y) {
    return x > y;
}
bool check(ll x) {
    vector<ll> p, q;
    for(int i = 1; i <= n; ++i) {
        if(a[i].first >= x) p.push_back(-x + a[i].first + a[i].second);
        else q.push_back(a[i].second);
    }
    sort(all(p), cmp), sort(all(q), cmp);
    // for(ll X : p) cout << X << " " ; cout << "\n";
    // for(ll X : q) cout << X << " " ; cout << "\n";
    if(p.size() < q.size()) return false;
    for(int i = 0; i < q.size(); ++i) {
        if(p[i] < q[i]) return false;
    }
    return true;
}

void solve() {
    cin >> n;
    int l = 1e9, r = 1e9;
    for(int i = 1, x, y; i <= n; ++i) {
        cin >> x >> y;
        a[i] = {x, y};
        l = min(x, l), r = max(x, r);
    }   
    int ans = -1;
    // check(8);
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}