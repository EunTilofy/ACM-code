#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n, m, d;
vector<pii> G[2005];
long long dis[2005];
bool in[2005];
int cnt[2005];
bool spfa() {
    queue<int> q;
    memset(cnt, 0, sizeof cnt);
    memset(in, 0, sizeof in);
    q.push(1);
    cnt[1] = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        in[x] = 0;
        if(cnt[x] > n) return 0;
        for(auto [w, y] : G[x]) {
            if(dis[y] < dis[x] + w) {
                dis[y] = dis[x] + w;
                if(!in[y]) {
                    q.push(y);
                    in[y] = 1;
                    ++cnt[y];
                    if(cnt[y] > n) return 0;
                }
            }
        }
    }
    return 1;
}
void solve() {
    cin >> n >> m >> d;
    vector<pair<int,int>> r(n+1), l(n+1);
    for(int i = 1; i <= n; ++i) G[i].clear();
    for(int i = 1; i <= n; ++i) dis[i] = 0;
    for(int i = 1; i < n; ++i) G[i].push_back({1, i+1});
    for(int i = 0; i < m; ++i) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        if(A == B && C == D) {
            G[A].push_back({d, C});
            G[C].push_back({-d, A});
        }
        else{
        if(!r[A].second || D < r[A].second) {
            r[A] = {d+1,D};
        }
        if(!l[C].second || B < l[C].second) {
            l[C] = {1-d, B};
        }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(r[i].second) {
            G[i].push_back(r[i]);
        }
        if(l[i].second) {
            G[i].push_back(l[i]);
        }
    }
    if(!spfa()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else {
        for(int i = 2; i <= n; ++i) {
            if(dis[i] - dis[i-1] > 2000000000) {
                cout << "IMPOSSIBLE" << endl;
                return ;
            }
        }
        for(int i = 2; i <= n; ++i) cout << dis[i] - dis[i-1] << " ";
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
        cout << "Case #" <<i <<": ";
        solve();
    }
}