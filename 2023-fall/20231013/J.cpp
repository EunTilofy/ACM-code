#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 81, K = 6401;
int dis[N][N], q[N];
int f[2][2][N][K];

void Min(int &x, int y) {
    x = min(x, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    memset(dis, 0x3f, sizeof dis);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) dis[i][i] = 0;
    for(int i = 1, x, y; i <= m; ++i) {
        cin >> x >> y;
        dis[x][y] = 1;
    }
    for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    // cerr << dis[4][5] << " " << dis[1][5] << "\n";
    int Q; cin >> Q;
    q[0] = 1;
    for(int i = 1; i <= Q; ++i) cin >> q[i];
    int nw = 0; 
    memset(f[0], 0x3f, sizeof f[0]);
    f[0][0][0][0] = 0;
    for(int o = 1; o <= Q; ++o, nw ^= 1) {
        memset(f[nw ^ 1], 0x3f, sizeof f[nw ^ 1]);
        for(int i = 0; i < 2; ++i) for(int j = 0; j <= o; ++j) for(int k = 0; k < K; ++k) if(f[nw][i][j][k] <= 6400){
            if(!i) {
                // if(o == 5 && j == 4 && k == 2) cerr << "!!" << f[nw][i][j][k] << " ??? " << dis[q[o - 1]][q[o]] << "\n";
                Min(f[nw ^ 1][0][j][k], f[nw][i][j][k] + dis[q[o - 1]][q[o]]);
                Min(f[nw ^ 1][1][o - 1][k + dis[q[j]][q[o]]], f[nw][i][j][k]);
            } else {
                Min(f[nw ^ 1][1][j][k + dis[q[o - 1]][q[o]]], f[nw][i][j][k]);
                Min(f[nw ^ 1][0][o - 1][k], f[nw][i][j][k] + dis[q[j]][q[o]]);
                // if(o == 5 && k == 2) cerr << "!!" << q[j] << " " << f[nw][i][j][k] << " " << dis[q[j]][q[o]] << "\n";
            }
        }
        // for(int i = 0; i < 2; ++i) for(int j = 0; j <= o; ++j) for(int k = 0; k < K; ++k) {
        //     if(f[nw ^ 1][i][j][k] <= 6400) cerr << o << " " << i << " " << j << " " << k << " " << f[nw ^ 1][i][j][k] << "\n";
        // }
    }
    int ans = 1e9;
    for(int i = 0; i < 2; ++i) for(int j = 0; j <= Q; ++j) for(int k = 0; k < K; ++k) {
        ans = min(ans, max(k, f[nw][i][j][k]));
    }
    cout << ans << "\n";
    return 0;
}