#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> a;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    a.clear();
    int len=0, all=0;
    for(auto &x : s) {
        cin >> x; 
        int now = 0, mi = 0;
        for(auto &y : x) {
            if(y == '(') {
                now ++;
            } else now--;
            mi = min(mi, now);
        }
        len += x.size();
        all += now;
        a.push_back({mi, now});
    }
    int ans = len - all;
    
    vector<pair<int, int>> b, c;
    for(int i = 0; i < n; ++i) {
        if(a[i].second >= 0) c.push_back({a[i].first, a[i].second});
        else b.push_back({a[i].second - a[i].first, a[i].first});
    }
    sort(c.begin(), c.end()); reverse(c.begin(), c.end());
    sort(b.begin(), b.end()); reverse(b.begin(), b.end());
    int fd = 0, now = 0;
    for(int i = 0; i < c.size(); ++i) {
        fd = min(fd, now + c[i].first);
        now += c[i].second;
    }
    for(int i = 0; i < b.size(); ++i) {
        fd = min(fd, now + b[i].second);
        now += b[i].first + b[i].second;
    }
    ans = ans + fd * 2;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}