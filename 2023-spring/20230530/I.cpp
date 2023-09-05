#include<bits/stdc++.h>
using namespace std;
map<int, int> mp[110];

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    vector<int> mk(10, 0);
    mk[1] = 1, mk[4] = 1;
    for(int i = 1; i <= 6; ++i) for(int j = 1; j <= 6; ++j) for(int k = 1; k <= 6; ++k) {
        vector<int> a(2, 0);
        a[mk[i]] += i, a[mk[j]] += j, a[mk[k]] += k;
        // if(i == 2 && j == 4 && k == 3) cout << a[0] << " " << a[1] << "\n";
        mp[a[1]][a[0]] = 1;
    }
    int n, m;
    cin >> n >> m;
    cout << (mp[n][m] ? "Yes\n" : "No\n") << "\n";
}