#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    cout << 4 << " ";
    for(int i = 1; i < n; ++i) cout << "-1 2 ";
    cout << -n << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}