#include<bits/stdc++.h>
using namespace std;
#define all(x) (x.begin(), x.end())

const int MN = 6e5+5;
int fa[MN];
int getf(int x) {
    return fa[x] == x ? x : fa[x] = getf(fa[x]);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> ed, ed1;
    set<pair<int,int>> in;
    unordered_set<int> _;
    unordered_map<int,int> id;
    for(int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        if(y < x) swap(x, y);
        in.insert({x, y});
        ed.push_back({w, {x, y}});
    }
    for(auto &[w, xy] : ed) {
        int x = xy.first, y = xy.second;
        if(!_.count(x)) {
            _.insert(x);
            for(int xx = x-1; xx > 0; --xx) if(!in.count({xx, x})){
                // in.insert({xx,x});
                ed1.push_back({x-xx,{xx, x}});
                break;
            }
            for(int xx = x+1; xx <= n; ++xx) if(!in.count({x, xx})){
                // in.insert({x,xx});
                ed1.push_back({xx-x,{x, xx}});
                break;
            }
        }
        if(!_.count(y)) {
            _.insert(y);
            for(int yy = y-1; yy > 0; --yy) if(!in.count({yy, y})){
                // in.insert({yy,y});
                ed1.push_back({y-yy,{yy, y}});
                break;
            }
            for(int yy = y+1; yy <= n; ++yy) if(!in.count({y, yy})){
                // in.insert({y, yy});
                ed1.push_back({yy-y, {y, yy}});
                break;
            }
        }
    }
    for(auto x : ed1) ed.push_back(x);
    for(auto &[w, xy] : ed) {
        int x = xy.first, y = xy.second;
        _.insert(x); _.insert(y);
        // cerr << x << " " << y << " " << w << endl;
    }
    // cerr << "------" << endl;
    long long ans = n;
    for(auto x : _) {
        ans -= 1;
    }
    int cnt = 0;
    for(auto x : _) id[x] = ++cnt;

    for(int i = 1; i <= cnt; ++i) fa[i] = i;
    sort(ed.begin(), ed.end());

    for(auto &[w, xy] : ed) {
        int x = getf(id[xy.first]), y = getf(id[xy.second]);
        if(x == y) continue;
        else ans += w, fa[x] = y;
    }
    // cerr << "-----" << endl;
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}