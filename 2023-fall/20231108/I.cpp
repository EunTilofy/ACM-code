#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, m, k, d;
vector<int> G[N];

vector<int> get(int be) {
    vector<int> f(n + 1, 1e9);
    queue<int> q;
    f[be] = 0, q.push(be);
    while(q.size()) {
        int x = q.front(); q.pop();
        for(auto y : G[x]) {
            if(f[y] > f[x] + 1) {
                f[y] = f[x] + 1;
                q.push(y);
            }
        }
    }
    return f;
}

vector<ll> dij(int be, vector<int> dk) {
    vector<ll> f(n + 1, 1e18);
    priority_queue<pair<ll, int>>q;
    f[be] = 0;
    q.push({0, be});
    while(q.size()) {
        auto [val, u] = q.top(); q.pop();
        val = -val;
        if(f[u] != val) continue;
        for(int v : G[u]) {
            if(dk[v] >= d) {
                f[v] = min(f[v], f[u]);
            } else if(dk[v] < d) {
                if(f[v] > f[u] + d - dk[v]) {
                    f[v] = f[u] + d - dk[v];
                    q.push({-f[v], v});
                }            
            }
        }
    }
    return f;
}

void solve() {
    cin >> n >> m >> k >> d;
    // for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1, x, y; i <= m; ++i) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    // return ;
    vector<int> dn = get(n);
    // return ;
    vector<int> dk = get(k);
    vector<ll> d1 = dij(1, dk);
    // for(int i = 1; i <= n; ++i) {
    //     cout << i << ", dn = " << dn[i] << ", dk = " << dk[i] << ", di =  " << d1[i] << "\n";
    // }
    ll ans = 1e18;
    if(dk[n] < d) ans = min(ans, d1[n]);
    for(int i = 1; i <= n; ++i) if(dk[i] >= d) {
        ll len = dn[i] + 1;
        ll A = len / d, B = len % d;
        // cout << i << ", val = " << d1[i] + A * d * (d + 1) / 2 + B * (d + d-B+1) / 2 << "\n";
        ans = min(ans, d1[i] + A * d * (d + 1) / 2 + B * (d + d-B+1) / 2);
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    for(int o = 1; o <= T; ++o) {
        solve();
    }
}