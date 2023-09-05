#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int a[MN], b[MN];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], b[a[i]] = i;
    int cnt = 0;
    for(int i = 1; i < n; ++i) if(b[i] > b[i + 1]) ++ cnt;
    cout << cnt << "\n";
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