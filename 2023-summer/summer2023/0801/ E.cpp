#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a;
    a.push_back(-1);
    for(int i = 1, x; i <= n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    vector<pair<int, int> > b(q);
    for(int i = 1, x; i <= q; ++i) {
        cin >> x;
        b[i - 1] = {x, i - 1};
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<int, int> > c;
    for(int i = 1; i <= n; ++i) {
        if(a[i] != a[i - 1] + 1) {
            c.push_back({a[i - 1] + 1, a[i] - 1});
        }
    }
    // for(auto[x, y] : c) cerr << x << " " << y << "\n";
    vector<int> ans(q);
    int id = 0, sum = 0;
    for(int o = 0; o < q; ++o) {
        auto [val, i] = b[o];
        //cerr << val << " " << i << "xx\n";
        if(o && val == b[o - 1].first) {ans[i] = ans[b[o - 1].second]; continue;}
        for(; id < c.size() && c[id].second - c[id].first + 1 + sum < val; sum += c[id].second - c[id].first + 1, id++);
        if(id < c.size()) {
            // cerr << o << " " << id << " " << sum << "\n";
            int pos = val - sum;
            ans[i] = pos + c[id].first - 1;
            sum = val;
            c[id].first = ans[i] + 1;
        } else {
            //cerr << val << " " << sum << "\n";
            int pos = val - sum;
            ans[i] = a[n] + pos;
        }
    }
    for(int x : ans) cout << x << " ";
    return 0;
}