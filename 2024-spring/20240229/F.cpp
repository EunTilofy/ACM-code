#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<int> tr;
    void init(int _n) {
        n = _n;
        tr.resize(n + 1);
        // for(int x : tr) cout << x << " "; cout << "\n";
    }
    void upd(int x, int k) {
        for(; x <= n; x += (x & (-x))) {
            tr[x] += k;
        }
    }
    int get(int x) {
        int ans = 0;
        for(; x; x -= (x & (-x))) ans += tr[x];
        return ans;
    }
};
const int N = 5e5 + 10;
int dp[N][2];

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), ys(n + 1);
    for(int i = 1; i <= n; ++i) {cin >> a[i]; ys[a[i]] = i;}
    BIT t; t.init(n);
    vector<int> f(n + 1), g(n + 1);
    ll ans = 0;
    for(int i = n; i >= 1; --i) {
        ans += t.get(a[i]);
        t.upd(a[i], 1);
    }    
    // cout << ans << "ans\n";
    for(int i = 1; i < n; ++i) {
        int pos = max(dp[i - 1][0], dp[i - 1][1]), tmp = (ys[i] > ys[i + 1]);
        dp[i][0] = pos;
        dp[i][1] = max(pos, dp[i - 1][0] + tmp);
    }
    cout << ans - max(dp[n - 1][0], dp[n - 1][1]) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}

/*
4
3 3
2 2 1
3 3
2 3 3
5 2
1 1 1 1 1
1 1
1
*/