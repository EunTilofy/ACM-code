#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main() {
    freopen("continued.in", "r", stdin);
    freopen("continued.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > ans;
    if(n >= m) {
        vector<int> pos;
        for(int i = m; i <= n; i += m) {
            pos.push_back(1);
            for(int j = 1; j < m && i + j <= n; ++j) pos.push_back(0);
        }
        ans.push_back(pos);
    } else ans.push_back({0});
    vector<int> pos;
    n = n % m;
    if(n){
        for(int i = n + 1; i <= m; ++i) pos.push_back(9);
        // cerr << m - n + 1 << " " << m << "\n";
        // for(int i = 1; i <= m - n; ++i) pos.push_back(0);
        ans.push_back(pos);
        ans.push_back({1});
        pos.clear();
        for(int i = 1; i <= n; ++i) pos.push_back(9);
        ans.push_back(pos);
    }  else {
        for(int i = 1; i <= m; ++i) pos.push_back(9);
        ans.push_back(pos);
    }
    cout << ans.size() - 1 << "\n";
    for(auto x : ans) {
        for(int y : x) cout << y;
        cout << " ";
    }
    return 0;
}
/*
!!
1
2
in
1
1pos
19z
201a
19b
210a
11!
!!
1
in
9
9pos
19z
19a
19b
10a
10!

1
11 19

*/