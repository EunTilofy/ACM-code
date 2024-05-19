#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int N = 110;
int a[N][N];
int dis[N][N];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int sx, sy;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        cin >> a[i][j];
        if(a[i][j] == 2) {
            sx = i, sy = j;
        }
    }
    // cout << sx << " " << sy << "sx\n";
    int inf = 1e9;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) dis[i][j] = inf;
    queue<pair<int, int>> q;
    dis[sx][sy] = 0; q.push({sx, sy});
    while(q.size()) {
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if(a[xx][yy] && dis[xx][yy] > dis[x][y] + 1) {
                dis[xx][yy] = dis[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    // for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j)
    // cout << i << " " << j << " " << dis[i][j] << "\n";
    vector<pair<int, int>> a;
    int Q; cin >> Q;
    for(int i = 1, x, y; i <= Q; ++i) {
        cin >> x >> y;
        swap(x,y);
        if(dis[x][y] != inf) {
            // cout << x << " " << y << " "  << dis[x][y] << "??\n";
        a.push_back({dis[x][y], i});
        }
    }
    sort(all(a));
    for(int i = 0; i < a.size(); ++i) {
        int j = i;
        for(; j + 1 < a.size() && a[j + 1].first == a[i].first; ++j);
        if(i != j) i = j;
        else {
            cout << a[i].second << " " << a[i].first << "\n";
            return 0;
        }
    }
    cout << "No winner.\n";
    return 0;
}