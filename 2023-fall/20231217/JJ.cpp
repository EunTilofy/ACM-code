#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);

    for(auto &x : a) cin >> x;
    vector<bool> in(100001);

    auto sol = [&](const vector<int>& d) -> int {
        for(auto &x : d) in[x] = 1;
        int mex = 0;
        while(in[mex]) ++mex;
        for(auto &x : d) in[x] = 0;
        return mex;
    };
    
    for(int i = 1; i <= n; ++i) {
        vector<int> b;
        for(int j = 0; j + i - 1 < n; ++j) {
            vector<int> c;
            for(int k = j; k <= j + i - 1; ++k) c.push_back(a[k]);
            b.push_back(sol(c));
        }
        cout << sol(b) << " ";
    }
    return 0;
}