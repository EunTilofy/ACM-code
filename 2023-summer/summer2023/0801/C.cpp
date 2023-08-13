#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), vs(n);
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());
    multiset<int> s;
    for(int i = 1, j = n - 1; i < j; i++, j--) {
        vs[i] = j, vs[j] = i;
        s.insert(a[i] + a[j]);
    }
    // cerr << s.size() << "\n";
    // for(auto it : s) cerr << it << "!!??\n";
    // cerr << "!!\n";
    int ans = (*s.rbegin()) - (*s.begin());
    // cerr << "!!\n";
    for(int i = 1; i < n; ++i) {
        int pos = vs[i];
        s.erase(s.find(a[i] + a[pos]));
        vs[i - 1] = pos, vs[pos] = i - 1;
        s.insert(a[i - 1] + a[pos]);
        ans = min(ans, (*s.rbegin()) - (*s.begin()));
        // cerr << i << " " << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}