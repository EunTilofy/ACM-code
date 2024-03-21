#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nm(n + 1);
    vector<int> a(n + 1);
    queue<int> p, q;
    int flg = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] != a[1]) flg = 0;
        nm[a[i]] = 1;
        if(a[i] == 2) p.push(i);
        else q.push(i);
    }
    int pos = -1;
    for(int i = 2; i <= k; ++i) if(!nm[i]) pos = i;
    if(flg && a[1] <= k) pos = a[1];
    if(pos == -1) {
        cout << "-1\n";
        return ;
    }
    vector<vector<int> > ans;

    int tmp = n - pos, cnt = 0;

    while(p.size() >= 2 && tmp) {
        --tmp;
        int x = p.front(); p.pop();
        int y = p.front(); p.pop();
        ans.push_back({x, y}), ++cnt;
        p.push(n + cnt * 2 - 1);
    }
    while(q.size() >= 2 && tmp) {
        --tmp;
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        ans.push_back({x, y}), ++cnt;
        q.push(n + cnt * 2);
    }
    {
        vector<int> f;
        while(p.size()) {
            int x = p.front(); p.pop();
            f.push_back(x);
        }
        while(q.size()) {
            int x = q.front(); q.pop();
            f.push_back(x);
        }
        assert(f.size() == pos);
        ans.push_back(f);
    }
    cout << ans.size() << "\n";
    for(auto &x : ans) {
        cout << x.size() << " ";
        for(int y: x) cout << y << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}