#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n * 14);
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        int y = 0;
        while(x) {
            a[y++] += x%10;
            x/=10;
        }
    }
    int ans = 0, all = n * 14;
    for(int i = 0; i < all; ++i) {
        ans += a[i]/10;
        a[i+1] += a[i]/10;
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