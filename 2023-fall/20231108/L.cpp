#include<bits/stdc++.h>
using namespace std;
const int N=1050;
int f[N * N];
int a[N][N], b[N][N];

int find(int k) {
    return f[k] == k ? f[k] : f[k] = find(f[k]);
}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool check(int n, int m) {
    for(int i = 1; i <= n * m; ++i) f[i] = i;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        if(!b[i][j]) continue;
        for(int o = 0; o < 4; ++o) {
            int x = i + dx[o], y = j + dy[o];
            if(x < 1 || x > n || y < 1 || y > m || !b[x][y]) continue;
            int u = (x - 1) * m + y, v = (i - 1) * m + j;
            int fu = find(u), fv = find(v);
            f[fu] = fv;
        }
    }
    int last = -1;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) if(b[i][j]) {
        int pos = find((i - 1) * m + j);
        if(last != -1 && last != pos) {
            return 0;
        }
        last = pos;
    }
    return 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    if(n <= 3 && m <= 3) {
        cout << n * m << "\n";
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cout << "1";
            }
            cout << "\n";
        }
        return ;
    }

    if(n==3||m==3) {
        for(int i =1 ; i <= n; ++i) for(int j = 1; j <= m; ++j) {
            b[i][j] = 0;
        }
        for(int i = 1; i <= n; i += 4) {
            for(int j = 1; j <= m; j += 4) {
                for(int o : {0, 1, 2}) b[i][j + o] = 1;
                for(int o : {0, 2, 3}) b[i + 1][j + o] = 1;
                for(int o : {0, 1, 2}) b[i + 2][j + o] = 1;
                for(int o : {1}) b[i + 3][j + o] = 1;
            }
        }
        long long ans = 0;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
            ans += b[i][j];
        }
        cout << ans << "\n";
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cout << b[i][j];
            }
            cout << "\n";
        }
        return ;
    }

    long long c[4][4], ans = 0, _ii = 0, _jj = 0;

    for(int ii = 0; ii < 4; ++ii) for(int jj = 0; jj < 4; ++jj) {
        c[ii][jj] = 0;
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j)
            b[i][j] = a[i+ii][j+jj], c[ii][jj] += b[i][j];
        if(c[ii][jj]>ans) {
            if(check(n, m)) ans = c[ii][jj], _ii = ii, _jj = jj;
        }
    }

    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) b[i][j] = a[i+_ii][j+_jj];
    if(n % 4 == 1 && m % 4 == 1 && _ii == 0 && _jj == 0) b[n][m] = 0;
    assert(check(n, m));
    ans = 0;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) ans += b[i][j];
    cout << ans << "\n";
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cout << b[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= 1040; i += 4) {
        for(int j = 1; j <= 1040; j += 4) {
            for(int o : {0, 1, 2}) a[i][j + o] = 1;

            for(int o : {0, 2, 3}) a[i + 1][j + o] = 1;

            for(int o : {0, 1, 3}) a[i + 2][j + o] = 1;

            for(int o : {1, 2, 3}) a[i + 3][j + o] = 1;
        }
    }
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
        solve();
    }
}

/*

11101110111
10111011101
11011101110
01110111011
11101110111
10111011101
11011101110
01110111011
11101110111
10111011101
11011101110


*/