#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010;
struct node{
    int x, y;
};
int n, m;
int vs[N][N], res = 0;
vector<node> q[N];
string a[N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void dfs(int x, int y) {
    if(vs[x][y]) return ;
    if(!vs[x][y]) vs[x][y] = 1, q[res].push_back({x, y});
    for(int o = 0; o < 4; ++o) {
        int xx = x + dx[o], yy = y + dy[o];
        if(xx < 0 || xx >= n || yy < 0 || yy >= m || a[xx][yy] == 'O') continue;
        dfs(xx, yy);
    }
}
int mk[N];
bool check(int A, int B) {
    for(auto [x, y] : q[A]) mk[x * m + y] = 1;
    for(auto [nx, ny] : q[A]) {
        int flg = 1;
        int px = nx - q[B][0].x, py = ny - q[B][0].y;
        for(auto [x, y] : q[B]) {
             int xx = x + px, yy = y + py;
            if(xx < 0 || xx >= n || yy < 0 || yy >= m || !mk[xx * m + yy]) {flg = 0; break;}
        }
        if(flg) {
            for(auto [x, y] : q[A]) mk[x * m + y] = 0;
            return true;
        }
    }
    for(auto [x, y] : q[A]) mk[x * m + y] = 0;
    return false;
}

void solve() {
    res = 0;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        if(!vs[i][j] && a[i][j] == '.') {
            ++res, q[res].clear();
            dfs(i, j);
        }
    }
    // for(int i = 1; i <= res; ++i) {
    //     cout << "i = " << i << "\n";
    //     for(auto [x, y] : q[i]) {
    //         cout << x << " " << y << "\n";
    //     }
    // }
    
    int ans = 0;
    for(int i = 1; i <= res; ++i) {
        int flg = 1;
        for(int j = 1; j <= res; ++j) if(i != j) {
            if(check(j, i)) {flg = 0; break;}
        }
        // cout << i << " " << flg << "\n";
        ans += flg * q[i].size();
    }
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) vs[i][j] = 0;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for(int o = 1; o <= T; ++o) solve();
}