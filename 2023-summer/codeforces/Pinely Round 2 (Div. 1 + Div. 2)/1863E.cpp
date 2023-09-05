#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MN = 2e5+5;
int n, m, k;
vector<int> G[MN];
int in[MN];
long long h[MN];
long long t[MN];
long long dfs(int x) {
    long long tmp = t[x];
    for(auto &y : G[x]) if(t[y] < t[x]) {
        while(t[y] < t[x]) {
            t[y] += k;
        }
        tmp = max(tmp, dfs(y));
    }
    return tmp;
}

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> h[i];
    for(int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        ++in[y];
    }
    set<pair<int,int>> q, qqq;
    vector<pair<int,int>> qq;
    for(int i = 1; i <= n; ++i) {
        if(in[i] == 0) {
            q.insert({h[i], i});
            qqq.insert({h[i], i});
        }
    }
    long long step = 0, now = 0;
    int cnt = 0;
    while(!q.empty()) {
        ++cnt;
        set<pair<int,int>>::iterator it;
        if(q.lower_bound({now, -1}) != q.end()) it = q.lower_bound({now, -1});
        else it = q.begin();
        auto [ti, id] = *it;
        q.erase(*it);
        // long long TI = ti;
        
        // vector<int> ids;
        // while(ti == TI) {
        //     ids.push_back(id);
        if(qqq.count({ti, id})) qq.push_back({ti, id});
        if(ti < now) ++step, now = ti;
        else now = ti;
        t[id] = 1ll * step * k + now;
        //     if(q.lower_bound({now, -1}) != q.end() && q.lower_bound({now, -1})->first == TI) {
        //         it = q.lower_bound({now, -1});
        //         id = it->second;
        //         q.erase(*it);
        //     } else ti = -1;
        // }
        // for(auto idd : ids)
        for(auto y : G[id]) {
            if(!(--in[y])) q.insert({h[y], y});
        }
        // if(now == k - 1) now = 0, ++step;
        // else ++now;
    }
    assert(cnt == n);
    long long mi = t[1], ma = t[1];
    for(int i = 2; i <= n; ++i) {
        // cout << t[i] << "~~\n";
        mi = min(mi, t[i]), ma = max(ma, t[i]);
    }
    long long mii = mi, maa = ma, MI = qq.back().first;
    for(auto [ti, id] : qq) {
        // cerr << ti << " " << id << "\n";
        mii = ti;
        if(maa - mii < ma - mi) {
            ma = maa, mi = mii;
        }
        if(ti != MI){// move [ti, id]
            t[id] += k;
            maa = max(dfs(id), maa);
        }
    }
    // cerr << "~~~\n";
    cout << ma - mi << "\n";
    for(int i = 1; i <= n; ++i) in[i] = 0, t[i] = 0, G[i].clear();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}