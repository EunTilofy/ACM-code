#include<bits/stdc++.h>
using namespace std;
map<string, int> ok;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> _;
    for(int i = n-1; i>=0; --i) {
        int j=i;
        while(j-1>=0&&ok.count(s.substr(j-1, i-j+2))) --j;
        // cout << j << " " << i << "\n";
        _.push_back(ok[s.substr(j, i-j+1)]);
        i=j;
    }
    reverse(_.begin(), _.end());
    for(auto x : _) cout << x; cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ok["I"] = 1;
    ok["II"] = 2;
    ok["III"] = 3;
    ok["IV"] = 4;
    ok["V"] = 5;
    ok["VI"] = 6;
    ok["VII"] = 7;
    ok["VIII"] = 8;
    int T;
    cin >> T;
    while(T--) solve();
}