#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 510;
ll a[N][N];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        cin >> a[i][j];
    }
    ll ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; ++i) {
        int flg = 0;
        for(int j = 1; j <= n; ++j) if(a[i][j] < 0) flg = 1, ans1 += a[i][j];
        if(!flg) {
            ll pos = 1e9;
            for(int j = 1; j <= n; ++j) pos = min(pos, a[i][j]);
            ans1 += pos;
        }
    }
    for(int j = 1; j <= n; ++j) {
        int flg = 0;
        for(int i = 1; i <= n; ++i) if(a[i][j] < 0) flg = 1, ans2 += a[i][j];
        if(!flg) {
            ll pos = 1e9;
            for(int i = 1; i <= n; ++i) pos = min(pos, a[i][j]);
            ans2 += pos;
        }
    }
    cout << min(ans1, ans2) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
        solve();
    }
    return 0;
}