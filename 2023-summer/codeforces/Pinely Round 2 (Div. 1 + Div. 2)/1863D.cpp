#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, m;
string a[505], b[505];
// bool rr[505], ll[505];

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
    // for(int i = 1; i <= n; ++i) rr[i] = 0;
    // for(int i = 0; i < m; ++i) ll[i] = 0;
    for(int i = 1; i < n; ++i) {
        bool now = 0;
        for(int j = 0; j < m; ++j) {
            if(a[i][j] == 'U' && a[i + 1][j] == 'D') {
                if(now) b[i][j] = 'B', b[i+1][j] = 'W';
                else b[i][j] = 'W', b[i+1][j] = 'B';
                now ^= 1;
            }
        }
        if(now != 0) {
            cout << "-1\n";
            return;
        }
    }
    for(int j = 0; j < m-1; ++j) {
        bool now = 0;
        for(int i = 1; i <= n; ++i) {
            if(a[i][j] == 'L' && a[i][j + 1] == 'R') {
                if(now) b[i][j] = 'B', b[i][j+1] = 'W';
                else b[i][j] = 'W', b[i][j+1] = 'B';
                now ^= 1;
            }
        }
        if(now != 0) {
            cout << "-1\n";
            return;
        }
    }
    for(int i = 1; i <= n; ++i) cout << b[i] << "\n";
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