#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<queue<int> > a(26);
    for(int i = 0; i < n; ++i) a[s[i] - 'a'].push(i);
    map<int, int> mp;
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        vector<pair<int, int> > b;
        int res = 0;
        for(int j = 0; j < 26; ++j) {
            while(a[j].size()) {
                int x = a[j].front();
                if(x >= i) {b.push_back({-x, j}); res ^= (1 << j); break;}
                a[j].pop();
            }
        }
        // cerr << i << " " << res << "res\n";
        sort(b.begin(), b.end());
        if(mp.count(res)) mp[res] = max(mp[res], n - i);
        else mp[res] = n - i;
        for(auto [pos, tmp] : b) {
            res ^= (1 << tmp);
            if(!res) break;
            pos = -pos;
            if(mp.count(res)) mp[res] = max(mp[res], pos - i);
            else mp[res] = pos - i;
        }
    }
    for(auto [x, y] : mp) {
        // cerr << x << " " << y << "\n";
        int nm = 0, X = x;
        for(; X; X /= 2) nm += (X & 1);
        ans += 1ll * nm * y;
    }
    cout << mp.size() << " " << ans << "\n";
}

int main() {
    freopen("jingles.in", "r", stdin);
    freopen("jingles.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for (int o = 1; o <= T; ++o) {
        solve();
    }
    return 0;
}