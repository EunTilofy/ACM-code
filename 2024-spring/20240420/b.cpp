#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<string> a(n);
    for(auto &x : a) cin >> x;
    int k; cin >> k;
    string t = "<censored>";
    string ans = "";
    string s;
    getline(cin, s);
    getline(cin, s);
    int cnt = 0, res = 0;
    vector<pair<int, int>> b;
    vector<int> vs(s.size() + 10, 0);
    for(auto st : a) {
        int pd = 1;
        int len = st.size();
        for(int i = 0; i + len - 1 < s.size(); ++i) {
            int flg = 1;
            for(int j = 1; j <= len; ++j) if(vs[i + j - 1]) {flg = 0; break;}
            if(!flg) continue;
            if(st == s.substr(i, len)) {
                // cout << i << "!!\n";
                pd = 0;
                ++res;
                ++cnt;
                for(int k = i; k < i + len; ++k) vs[k] = 1;
                b.push_back({i, i + len - 1});
                i = i + len - 1;
            }
        }
        // if(!pd) ++cnt;
    }
    assert(res == cnt);
    int st = 0;
    sort(all(b));
    for(int i = 0; i < s.size(); ++i) {
        if(st >= b.size() || b[st].first != i) {
            ans += s[i];
        } else {
            assert(b[st].first == i);
            i = b[st].second; ++st;
            ans += t;
        }
    }
    if(cnt < k) {
        cout << ans << "\n";
    }
    else cout << k << "\nHe Xie Ni Quan Jia!\n";
    return 0;
}