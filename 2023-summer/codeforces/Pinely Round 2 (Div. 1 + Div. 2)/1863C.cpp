#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int a[MN], b[MN];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i <= n + 1; ++i) b[i] = 0;
    for(int i = 1; i <= n; ++i) cin >> a[i], b[a[i]] = 1;
    int cc = 0;
    for(int i = 1; i <= n; ++i) if(b[i] == 0) cc = i;
    a[0] = cc;
    int fr = ((0 - m) % (n + 1) + (n + 1)) % (n + 1);
    for(int i = fr, j = 1; j <= n; ++j) {
        cout << a[(i + j) % (n + 1)] << " ";
    }
    cout << "\n";
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