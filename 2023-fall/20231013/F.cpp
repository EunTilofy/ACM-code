#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e6 + 10;
int vs[N], cnt = 0;
queue<pair<int, int> > q;
vector<pii> ans;
vector<int> a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, t;
    cin >> n >> m >> t >> k;    
    if(k == 1) {
        for(int i = 1, x, y; i <= m; ++i) {
            cin >> x >> y;
            ans.push_back({x, y});
        }
        cout << ans.size() << " 0\n";
        for(auto[x, y] : ans) cout << x << " " << y << "\n";
        return 0;
    }
    for(int o = 1, x, y; o <= m; ++o) {
        cin >> x >> y;
        if(!vs[y]) {
            a[y].push_back(x);
            ++cnt;
            if(cnt > n) {
                while(q.size()) {
                    auto[u, v] = q.front(); q.pop();
                    if(!vs[u] || a[u].back() != v) continue;
                    --cnt;
                    ans.push_back({x, u});
                    vs[u] = 0, a[u].clear();
                    break; 
                }
            }
            vs[y] = 1, q.push({y, x});
        } else {
            q.push({y, x});
            a[y].push_back(x);
            int tot = a[y].size();
            if(tot >= k && x - a[y][tot - k] <= t) {
                ans.push_back({x, y});
                --cnt;
                vs[y] = 0, a[y].clear();
            }
        }
    }
    cout << ans.size() << " " << cnt << "\n";
    for(auto [x, y] : ans) cout << x << " " << y << "\n";
    for(int i = 1; i < N; ++i) if(vs[i]) cout << i << " "; cout << "\n";
    return 0;
}