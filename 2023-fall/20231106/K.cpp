#include<bits/stdc++.h>
#define db double
using namespace std;

struct node {
    int x, y;
};

void get(node A, node B, double p) {
    int dx = B.x - A.x, dy = B.y - A.y;
    cout << fixed << setprecision(10) << A.x + p * dx << " " << A.y + p * dy << "\n";
}

void solve() {
    vector<node> a(3);
    for(auto &[x, y] : a) cin >> x >> y;
    int px, py;
    cin >> px >> py;
    int flg = -1, id1, id2;
    double p = 0.0;
    for(int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        int dx = a[j].x - a[i].x, dy = a[j].y - a[i].y;
        int nx = px - a[i].x, ny = py - a[i].y;
        if(1ll * nx * dy != 1ll * ny * dx) continue;
        if(!dx && nx) continue;
        if(!dy && ny) continue;
        if(dx) p = 1.0 * nx / dx;
        if(dy) p = 1.0 * ny / dy;
        if(p < 0 || p > 1) continue;
        if(p < 0.5) p = 1.0 - p, id1 = j, id2 = (j + 1) % 3;
        else id1 = i, id2 = (j + 1) % 3;
        flg = i;
    }
    if(flg == -1) {
        cout << "-1\n";
        return ;
    }
    // cout << p << "\n";
    get(a[id1], a[id2], 1.0 / (2.0 * p));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
        solve();
    }
    
    return 0;
}