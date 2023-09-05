#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
map<int, int> mp;
vector<int> ys;
vector<pair<int, int>> p[N];
int lim[N];
ll a[N];
int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    int g; cin >> g;
    for(int i = 1, x, y; i <= g; ++i) {
        cin >> x >> y;
        if(!mp.count(x)) ys.push_back(x), mp[x] = ys.size();
        a[mp[x]] += y;
    }
    int n, ans = 0;
    cin >> n;
    vector<set<pair<int, int>>> s(N);
    queue<int> q;
    for(int i = 1, sz; i <= n; ++i) {
        cin >> sz;
        lim[i] = sz;
        for(int j = 1, x, y; j <= sz; ++j) {
            cin >> x >> y;
            if(!mp.count(x)) ys.push_back(x), mp[x] = ys.size();
            if(a[mp[x]] >= y) lim[i]--;
            else s[mp[x]].insert({y, i});
        }
        if(!lim[i]) q.push(i);
        cin >> sz;
        for(int j = 1, x, y; j <= sz; ++j) {
            cin >> x >> y;
            if(!mp.count(x)) ys.push_back(x), mp[x] = ys.size();
            p[i].push_back({mp[x], y});
        }
    }
    while(q.size()) {
        ++ans;
        int x = q.front(); q.pop();
        for(auto [y, w] : p[x]) {
            a[y] += w;
            vector<pair<int, int> > del;
            for(auto it = s[y].begin(); it != s[y].end() && (*it).first <= a[y]; ++it) {
                int id = (*it).second;
                lim[id]--;
                if(!lim[id]) q.push(id);
                del.push_back(*it);
            }
            for(auto pp : del) s[y].erase(pp);
        }
    }
    cout << ans << "\n";
    return 0;
}