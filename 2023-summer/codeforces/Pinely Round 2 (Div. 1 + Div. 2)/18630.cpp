#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    string ans = "NO";
    int now = a, ca = a;
    if(now >= n) ans = "YES";
    for(auto x : s) {
        if(x == '+') {
            ++now;
            ++ca;
            // cout << ca << "\n";
        }
        else --now;
        if(now >= n) ans = "YES";
        if(ans != "YES") {
            if(ca >= n) ans = "MAYBE";
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}