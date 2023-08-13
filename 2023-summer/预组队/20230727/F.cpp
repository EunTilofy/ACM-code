#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > a, b, c;
set<int> S;
vector<vector<pair<int,int>>> d;
int mn, mx, inf;

vector<pair<int,int>> sol(int x, int y) {
    // cerr << "x = " << x << " y = " << y << "\n";
    vector<pair<int,int>> res;
    if(x == y) {
        res.push_back({1, inf});
        return res;
    }
    for(int i = 1; i <= x; ++i) {
        int j = x/(x/i);
        int ii, jj;
        jj = y/(x/i);
        ii = y/((x/i)+1)+1;
        int l = max(ii, i);
        int r = min(jj, j);
        if(l <= r) {
            res.push_back({l, r});
            // cerr << l << " " << r << "\n";
            assert((x/l)==(y/l));
            assert((x/r)==(y/r));
            assert((x/l)==(x/r));
            assert((y/l)==(y/r));
        }
        i = j;
    }
    res.push_back({max(x, y) + 1, inf});
    return res;
}
vector<pair<int,int>> inv(vector<pair<int,int>> o) {
    // cerr << "inv !" << "\n";
    // for(auto &[x, y] : o) {
    //     cerr << "<<< " << x << " " << y << "\n";
    // }
    vector<pair<int,int>> res;
    if(o.size() == 0) {
        res.push_back({1, inf});
    } else {
        if(o.size()>0 && o[0].first>1) res.push_back({1, o[0].first-1});
        for(int i = 0; i + 1 < o.size(); ++i) if(o[i+1].first - 1 > o[i].second) res.push_back({o[i].second + 1, o[i+1].first - 1});
        if(o.size()>0 && o[o.size()-1].second<inf) res.push_back({o[o.size()-1].second + 1, inf});
    }
    // for(auto &[x, y] : res) {
    //     cerr << "!!! " << x << " " << y << "\n";
    // }
    return res;
}

void solve() {
    for(auto &[x, y] : b) d.push_back(sol(x, y));
    for(auto &[x, y] : c) d.push_back(inv(sol(x, y)));
    vector<pair<int,int>> _;
    int all = d.size();
    for(auto &o : d) {
        for(auto &[x, y] : o) {
            _.push_back({x, 1});
            _.push_back({y+1, -1});
            // cerr << x << " " << y << "\n";
        }
        // cerr << "------------" << "\n";
    }
    sort(_.begin(), _.end());
    int cnt = 0, ans = 0;
    for(int i = 0; i < _.size(); ++i) {
        int j = i;
        cnt += _[i].second;
        while(j + 1 < _.size() && _[j+1].first == _[i].first) {
            ++j;
            cnt += _[j].second;
        }
        i = j;
        if(cnt == all) {
            if(i+1 < _.size()) {
                ans += _[i+1].first - _[i].first;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    a.resize(n);
    for(auto &[x, y] : a) cin >> x >> y;
    sort(a.begin(), a.end());

    mn = 1, mx = 2e9+1, inf = 2e9+1;

    for(int i = 0; i < a.size(); ++i) {
        int l = i;
        int r = i;
        while(r + 1 < a.size() && a[r + 1].second == a[l].second) ++r;
        if(S.count(a[l].second)) {
            cout << "0";
            return 0;
        }
        mn = max(mn, a[r].first - a[l].first + 1);
        S.insert(a[l].second);
        if(b.size()) mx = min(mx, a[l].first - b.back().first);
        b.push_back({a[l].first - 1, a[r].first - 1});
        i = r;
    }
    if(mx == inf) {
        cout << "-1";
        return 0;
    }
    for(int i = 0; i + 1 < b.size(); ++i) {
        c.push_back({b[i].second, b[i+1].first});
    }
    solve();
}