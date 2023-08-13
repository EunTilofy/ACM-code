#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<char,int>> L;
    vector<double> ans;
    for(int i = 1; i <= 2 * n; ++i) {
        char c; int t;
        cin >> c >> t;
        L.push_back({c, t});
    }

    int now = 0;
    double exp = 0;
    for(int i = 2 * n - 1; ~i; --i) {
        char c = L[i].first;
        int t = L[i].second;
        if(c == '+') {
            now --;
            ans.push_back(exp - t);
        } else {
            now ++;
            exp = (1.0/(double)now) * t + (1.0 - 1.0/(double)now) * exp;
            // cerr << exp << endl;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto &x : ans) cout << fixed << setprecision(10) << x << "\n";
    return 0;
}