#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int ans = 0, pr = 0;
    for(int i = 0; i < n; ++i) {
        int pos = (t[i] - s[i] + 26) % 26;
        ans += (pos != pr);
        pr = pos;
    }
    cout << ans << "\n";
    return 0;
}