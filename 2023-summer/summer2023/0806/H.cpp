#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<pair<int, int> > G[N];
int n, m, k;

bool check(int x) {
    int mx = 2 * k + 5;
    vector<int> f(n + 1, 0);
    for(int o = 1; o <= mx; ++o) {
        vector<int> g(n + 1, -1e9);
        for(int i = 1; i <= n; ++i) {
            for(auto[y, w] : G[i]) {
                if(w >= x) g[y] = max(g[y], f[i] + 1);
                else g[y] = max(g[y], f[i] - 1);
            }
        }
        f = g;
        if(o >= k) {
            for(int i = 1; i <= n; ++i) if(f[i] >= 1) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    int l = 1, r = 0, ans = -1;
    for(int i = 1, x, y, z; i <= m; ++i) {
        cin >> x >> y >> z;
        G[x].push_back({y, z});
        r = max(r, z);
    }
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    // assert(ans != -1);
    cout << ans << "\n";
    return 0;
}