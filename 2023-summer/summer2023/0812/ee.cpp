#include<bits/stdc++.h>
#pragma O(2)
#pragma O(3)
using namespace std;

struct node {
    int x, y, z, w;
    bool operator < (const node & o) const {
        return w > o.w;
    }
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> s(n);
    for(auto &x : s) cin >> x;
    priority_queue<node> q;
    vector<vector<vector<int> > > f(n, vector<vector<int> > (m, vector<int> (k + 1, 1e9)));
    vector<vector<vector<bool> > > vs(n, vector<vector<bool> > (m, vector<bool> (k + 1, 0)));
    
    int sx, sy, ex, ey;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        if(s[i][j] == 'A') sx = i, sy = j;
        if(s[i][j] == 'B') ex = i, ey = j;
    }
    q.push({sx, sy, 0, 0}), vs[sx][sy][0] = 1;
    f[sx][sy][0] = 0;
    // cerr << q.size() << "\n";
    while(q.size()) {
        auto [x, y, z, w] = q.top(); q.pop();
        if(f[x][y][z] != w) continue;
        // cerr << x << " " << y << " " << z << " " << f[x][y][z] << "\n";
        for(int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m || s[xx][yy] == '#') continue;
            if(s[xx][yy] == '.' || s[xx][yy] == 'B') {
                if(f[xx][yy][z] > f[x][y][z] + 1) {
                    f[xx][yy][z] = f[x][y][z] + 1;
                    if(s[xx][yy] != 'B') {
                        q.push({xx, yy, z, f[xx][yy][z]});
                    }
                }
                if(s[x][y] == 'D') {
                    if(z && f[xx][yy][z - 1] > f[x][y][z] + 2) {
                        f[xx][yy][z - 1] = f[x][y][z] + 2;
                        if(s[xx][yy] != 'B') {
                            q.push({xx, yy, z - 1, f[xx][yy][z - 1]});
                        }
                    }
                }
            } else if(s[xx][yy] == 'D') {
                if(z + 1 <= k) {
                    if(f[xx][yy][z + 1] > f[x][y][z] + 2) {
                        f[xx][yy][z + 1] = f[x][y][z] + 2;
                        q.push({xx, yy, z + 1, f[xx][yy][z + 1]});
                    } 
                    if(s[x][y] == 'D') {
                        if(f[xx][yy][z] > f[x][y][z] + 3) {
                            f[xx][yy][z] = f[x][y][z] + 3;
                            q.push({xx, yy, z, f[xx][yy][z]});
                        }
                    }
                } 
            }
        }
    }
    int ans = 1e9;
    for(int i = 0; i <= k; ++i) ans = min(ans, f[ex][ey][i]);
    if(ans == 1e9) cout << "HAHAHUHU\n";
    else cout << ans << "\n";
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