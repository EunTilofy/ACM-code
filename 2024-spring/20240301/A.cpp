#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    set<pair<int,int>> S;
    for(int i = 1, j = 1; i <= 2 * n; ++i) {
        if(i%2 == 1) {
            cout << j << " " << j << "\n";
            S.insert({j, j});
        }
        else {
            cout << j << " " << (j%n+1) << "\n";
            S.insert({j, (j%n+1)});
            ++j;
        }
    }
    int cnt = 2*n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(cnt == m) break;
            if(S.count({i, j}) == 0) {
                cout << i << " " << j << "\n";
                ++cnt;
            }
        }
        if(cnt == m) break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--) solve();
}