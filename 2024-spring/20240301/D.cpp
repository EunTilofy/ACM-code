#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), ys(n);
    vector<pair<int, int>> c(n);
    for(int &x : a) cin >> x;
    for(int i = 0; i < n; ++i) c[i] = {a[i], i};
    sort(all(c));
    for(int i = 0; i < n; ++i) ys[c[i].second] = i;
    vector<pair<int, int>> b;
    for(int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        x--;
        b.push_back({x, y});
    }
    b.push_back({-1, 0}), b.push_back({n - 1, 0});
    sort(all(b)), reverse(all(b));
    vector<ll> ans(n), da(n), hz(n + 5, 1e9), qz(n + 5, 1e9);
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        ans[i] = sum;
        da[i] = c[i].first;
        sum += c[i].first;
    }
    sum = 0;
    for(int i = 0; i + 1 < b.size(); ++i) {
        int l = b[i + 1].first + 1, r = b[i].first;
        // cout << l << " " << r << "\n";
        // return ;
        sum -= b[i].second;
        for(int j = l; j <= r; ++j) {
            int id = ys[j];
            hz[id] = min(hz[id], a[j] + sum);
            qz[id + 1] = min(qz[id + 1], sum);
        }
    }
    for(int i = n; i >= 0; --i) hz[i] = min(hz[i], hz[i + 1]);
    for(int i = 1; i < n; ++i) qz[i] = min(qz[i], qz[i - 1]);
    for(int i = 0; i < n; ++i) {
        // cout << i << " " << ans[i] << " " << da[i] << " " << qz[i] << " " << hz[i] << "\n";
        cout << ans[i] + min(hz[i], da[i] + qz[i]) << " \n"[i == n - 1];
    }
    // for(int i = 0; i < n; ++i) 
    //     cout << i << " " << ans[i] << " " << da[i] << " " << qz[i] << " " << hz[i] << "\n";
}
/*
-2 0 3 7 12 
-21 -18 -15 -11 -5 3 13 
*/
/*
2
5 2
1 2 3 4 5
3 1
4 2
7 3
4 3 1 10 3 8 6
4 9
3 8
4 5
*/
/*
-1 -2 0 3 7
0 0 1 1000000000 -2
1 1 2 -3 -1
2 3 3 -3 0
3 6 4 -3 1
4 10 5 -3 3
-20 -21 -18 -15 -11 -5 3
0 0 1 1000000000 -21
1 1 3 -22 -19
2 4 3 -22 -18
3 7 4 -22 -18
4 11 6 -22 -12
5 17 8 -22 -12
6 25 10 -22 -12
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) solve();
    
    return 0;
}