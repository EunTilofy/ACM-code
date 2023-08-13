#include<bits/stdc++.h>
using namespace std;

struct node {
    int x, y, w;
    bool operator < (const node & o) const {
        return w > o.w;
    }
};

const int N = 81;
int f[N][N];
struct oo {
    int px, py, ox, oy;
} pr[N][N];
int n, m, nm[2];
string s;

void print(int x, int y) {
    if(x == nm[0]) return ;
    auto[px, py, ox, oy] = pr[x][y];
    print(px, py);
    string t = "";
    for(char &ch : s) {
        if(ch == '0'){
            if(ox) ch = '1', ox--, t += "1";
            else t += "0";
        }
        else {
            if(oy) ch = '0', oy--, t += "1";
            else t += "0";
        }
    }
    cout << t << "\n";
}

void solve() {
    cin >> n >> m;
    for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) {
        f[i][j] = 1e9;
        pr[i][j] = {-1, -1, -1, -1};
    }
    cin >> s;
    priority_queue<node> q;
    nm[0] = nm[1] = 0;
    for(char ch : s) nm[ch - '0']++;
    q.push({nm[0], nm[1], 0}); f[nm[0]][nm[1]] = 0;
    while(q.size()) {
        auto[x, y, w] = q.top(); q.pop();
        if(f[x][y] != w) continue;
        // cerr << x << " " << y << " " << w << "\n";
        for(int i = 0; i <= m; ++i) {
            if(x >= i && y >= m - i) {
                int xx = x - i + (m - i), yy = y - (m - i) + i;
                if(f[xx][yy] > f[x][y] + 1) {
                    f[xx][yy] = f[x][y] + 1;
                    q.push({xx, yy, f[xx][yy]});
                    pr[xx][yy] = {x, y, i, m - i};
                }
            }
        }
    }
    // cerr << f[0][n] << "\n";
    // return ;
    if(f[0][n] > n) cout << "CATACLYSM IMMINENT - TIME TO HOARD FACE MASKS\n";
    else {
        cout << f[0][n] << "\n";
        print(0, n);
    }
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