#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(2*n);
    for(auto &aa : a) aa.resize(2*m);
    string s;
    cin >> s;
    int len = s.size();
    int up = 0, down = 0, left = 0, right = 0;
    int x = 0, y = 0;
    for(int i = 0; i < len; ++i) {
        if(s[i] == 'U') {
            --x;
            up = min(up, x);
        } else if(s[i] == 'D') {
            ++x;
            down = max(down, x);
        } else if(s[i] == 'L') {
            --y;
            left = min(left, y);
        } else if(s[i] == 'R') {
            ++y;
            right = max(right, y);
        }
        if(n-x>=1&&n-x<2*n&&m-y>=1&&m-y<2*m) a[n-x][m-y]=1;
    }
    a[n][m]=1;
    for(int i = 1; i < 2*n; ++i)
        for(int j = 1; j < 2*m; ++j)
            a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
    up = max(1, 1 - up), down = min(n, n - down), left = max(1, 1 - left), right = min(m, m - right);
    if(up > down || left > right) {
        if(k == 0) cout << n*m << "\n";
        else cout << "0\n";
        return;
    }
    else {
        int num = (down - up + 1) * (right - left + 1) - k;
        // cerr << num << "\n";
        if(num < 0) {
            cout << "0\n";
            return;
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
            int u, d, l, r;
            u = max(1, up + (n - i));
            d = min(n*2-1, down + (n - i));
            l = max(1, left + (m - j));
            r = min(m*2-1, right + (m - j));
            if(u > d || l > r) {
                if(num == 0) ++ans;
            }
            else if(num == (a[d][r]-a[(u)-1][r]-a[d][(l)-1]+a[(u)-1][(l)-1])) ++ans;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}