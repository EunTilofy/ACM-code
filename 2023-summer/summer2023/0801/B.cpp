#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MN = 2e5+5;
pair<long long, long long> ds[MN], dt[MN];
priority_queue<pair<long long, int>> q;
int n, m, l, r, L;
vector<pair<int,int>> G[MN];
const long long INF = 1e15;
long long add(long long x, long long y) {
    return (x + y) % 1000000007;
}
long long mul(long long x, long long y) {
    return 1ll * x * y % 1000000007;
}
void dij(int s, pair<long long, long long>* d) {
    while(!q.empty()) q.pop();
    d[s] = {0, 1};
    for(int i = 1; i <= n; ++i) {
        if(i != s) d[i] = {INF, 0};
    }
    q.push({0, s});
    while(!q.empty()) {
        pair<long long, int> o = q.top();
        q.pop();
        int x = o.second;
        long long w = -o.first;
        if(w > d[x].first) continue;
        for(auto &[y, ww] : G[x]) {
            if(d[y].first > d[x].first + ww) {
                d[y].second = d[x].second;
                d[y].first = d[x].first + ww;
                q.push({-d[y].first, y});
            } else if(d[y].first == d[x].first + ww){
                d[y].second = add(d[y].second, d[x].second);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> l >> r >> L;
    for(int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x].push_back({y, w});
        G[y].push_back({x, w});
    }
    dij(l, ds);
    dij(r, dt);
    long long ans = 0;

    long long mindis = ds[r].first;
    assert(ds[r].first == dt[l].first);
    if(L == mindis) {
        cout << ds[r].second;
        return 0;
    }
    if(L < mindis) {
        cout << 0;
        return 0;
    }
    // for(int i=1;i<=n;++i) cout << ds[i].first << " " << dt[i].first << " " << ds[i].second << " " <<dt[i].second << "\n";

    for(int x = 1; x <= n; ++x)
    if(ds[x].first + dt[x].first == mindis && x != r)
    for(auto &[y,w] : G[x]) {
        if(ds[x].first + dt[y].first + w == L) {
            ans = add(ans, mul(ds[x].second, dt[y].second));
        }
    }
    cout << ans;
    return 0;
}