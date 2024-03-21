#include<bits/stdc++.h>
using namespace std;

// void write(__int128 n) {
//     if(n < 10) {
//         cout << int(n%10);
//     } else {
//         write(n/10);
//         cout << int(n%10);
//     }
// }

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    long long all = 0;
    for(auto &x : a) cin >> x, all += x;
    sort(a.begin(), a.end());
    long long ans = 0, N = all;
    if(k == 1) {
        ans = N * (N - 1) / 2;
    } else if(k == 2) {
        ans = N * (N - 1) / 2;
        for(auto x : a) ans -= 1ll * x * (x - 1) / 2;
    } else {
        long long last = 0;
        for(int i = 0; i < n; ++i) {
            ans = ans + 1ll * (a[i]-last) * (1ll * (n-i) * (n-i-1) / 2);
            last = a[i];
            while(i+1<n&&a[i+1]==a[i]) ++i;
        }
    }
    cout << ans << "\n";
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