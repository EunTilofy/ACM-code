#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MN = 1e5 + 5;
int n;
vector<pair<int,int>> G[MN];
long long f[2][MN];

void dfs(int x, int F, int W) {
    vector<pair<int,int>> _;
    long long all = 0;
    for(auto &[y, w] : G[x]) {
        if(y == F) continue;
        dfs(y, x, w);
        all += f[0][y];
        _.push_back({ -f[1][y] + f[0][y], y});
    }
    sort(_.begin(), _.end());
    // f[1][x]
    f[1][x] = f[0][x] = all;
    int siz = _.size();
    if(siz) {
        f[1][x] -= _[0].first;
        // cerr << "--- x" << x << " " << f[1][x] << " " << all << endl;
        long long sum = -_[0].first;
        for(int i = 2; i < siz; i += 2) {
            sum -= (_[i-1].first + _[i].first);
            f[1][x] = max(f[1][x], all + sum);
        }
    }
    f[1][x] += W;
    // f[0][x]
    if(siz) {
        long long sum = 0;
        for(int i = 1; i < siz; i += 2) {
            sum -= (_[i-1].first + _[i].first);
            f[0][x] = max(f[0][x], all + sum);
        }
    }
    if(x==1 && siz==1) f[0][1] = max(f[1][1], f[0][1]);

    // cerr << x << " " << f[0][x] << " " << f[1][x] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x].push_back({y, w});
        G[y].push_back({x, w});
    }
    dfs(1, 0, 0);

    cout << f[0][1] << endl;
}