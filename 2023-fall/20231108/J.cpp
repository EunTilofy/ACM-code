#include<bits/stdc++.h>
using namespace std;
const int N=2e5 +10;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n + 1), e(n + 1);
    for(int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        d[x]++, d[y]++;
        e[x] = y, e[y] = x;
    }
    if(n == 2) {
        cout << "-1\n";
        return ;
    }
    int tot = 0;
    vector<int> nm(n + 1);
    for(int i = 1; i <= n; ++i) if(d[i] == 1) {
        ++tot;
        nm[e[i]]++;
    }
    sort(nm.begin(), nm.end()), reverse(nm.begin(), nm.end());
    if(nm[0] * 2 > tot) {
        if(nm[1] == 0) cout << "-1\n";
        else cout << nm[0] << "\n";
    } else {
        cout << (tot + 1) / 2 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) {
        solve();
    }
}