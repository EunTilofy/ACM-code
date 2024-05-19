#include <bits/stdc++.h>
using namespace std;
int L, n;
int a[5][5], cnt = 0;

bool check() {
    for(int j = 1; j <= n; ++j) {
        int pos = L;
        for(int i = 1; i < n; ++i) pos -= a[i][j];
        if(pos < 0) return false;
        a[n][j] = pos;
    }
    for(int i = 1; i <= n; ++i) {
        int pos = 0;
        for(int j = 1; j <= n; ++j) pos += a[i][j];
        if(pos != L) return false;
    }
    for(int i = 1; i <= n; ++i) {
        int pos = 0;
        for(int j = 1; j <= n; ++j) pos += a[j][i];
        if(pos != L) return false;
    }
    // if(L == 7 && n == 3) {
    //     for(int i = 1; i <= n; ++i) {
    //         for(int j = 1; j <= n; ++j) cout << a[i][j] << " ";
    //         cout << "\n";
    //     }
    // }
    return true;
}

void dfs(int x, int y, int sum) {
    if(x == n) {
        if(check()) cnt++;
        return ;
    }
    for(int j = 0; j <= L - sum; ++j) {
        a[x][y] = j;
        if(y != n - 1) {
            
            dfs(x, y + 1, sum + j);
        }
        else {
            a[x][n] = L - sum - j;
            dfs(x + 1, 1, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(L = 2; L <= 9; ++L) for(n = 2; n <= 4; ++n) {
        cnt = 0;
        dfs(1, 1, 0);
        cout << L << " " << n << " " << cnt << "\n";
    }
    return 0;
}