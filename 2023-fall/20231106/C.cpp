#include<bits/stdc++.h>
using namespace std;

int a[1005][1005], nm[1005][1005][5];
vector<pair<int,pair<int,int>>> v;
const int mod = 1000000007;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            v.push_back({a[i][j], {i, j}});
        }

    sort(v.begin(), v.end());
    int ans = 0;
    for(auto [v, ps] : v) {
        int x = ps.first, y = ps.second;
        bool fl = 0, fl2 = 0;
        // if(v == 1) nm[x][y] = 1;
        // else {
            if(x > 1 && a[x-1][y] == v-1) {
                fl2 = 1;
                nm[x][y][2] = (nm[x][y][2] + nm[x-1][y][1])%mod;
                nm[x][y][3] = (nm[x][y][3] + nm[x-1][y][2])%mod;
                nm[x][y][4] = (nm[x][y][4] + nm[x-1][y][3])%mod;
                nm[x][y][4] = (nm[x][y][4] + nm[x-1][y][4])%mod;
            }
            if(x < n && a[x+1][y] == v-1) {
                fl2 = 1;
                nm[x][y][2] = (nm[x][y][2] + nm[x+1][y][1])%mod;
                nm[x][y][3] = (nm[x][y][3] + nm[x+1][y][2])%mod;
                nm[x][y][4] = (nm[x][y][4] + nm[x+1][y][3])%mod;
                nm[x][y][4] = (nm[x][y][4] + nm[x+1][y][4])%mod;
            }
            if(y > 1 && a[x][y-1] == v-1) {
                fl2 = 1;
                nm[x][y][2] = (nm[x][y][2] + nm[x][y-1][1])%mod;
                nm[x][y][3] = (nm[x][y][3] + nm[x][y-1][2])%mod;
                nm[x][y][4] = (nm[x][y][4] + nm[x][y-1][3])%mod;
                nm[x][y][4] = (nm[x][y][4] + nm[x][y-1][4])%mod;
            }
            if(y < m && a[x][y+1] == v-1) {
                fl2 = 1;
                nm[x][y][2] = (nm[x][y][2] + nm[x][y+1][1])%mod;
                nm[x][y][3] = (nm[x][y][3] + nm[x][y+1][2])%mod;
                nm[x][y][4] = (nm[x][y][4] + nm[x][y+1][3])%mod;
                nm[x][y][4] = (nm[x][y][4] + nm[x][y+1][4])%mod;
            }
        // }
        if(!fl2) nm[x][y][1] = 1;
        if(x > 1 && a[x-1][y] == v+1) fl = 1;
        if(x < n && a[x+1][y] == v+1) fl = 1;
        if(y > 1 && a[x][y-1] == v+1) fl = 1;
        if(y < m && a[x][y+1] == v+1) fl = 1;
        if(!fl) ans += nm[x][y][4], ans%=mod;
    }
    cout << ans << "\n";
}