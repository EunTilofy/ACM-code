#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

const int N = 1010;
map<int, int> mp;
int cnt = 0;
vector<int> q[N * N][2];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) {
        int x;
        cin >> x;
        if(!mp.count(x)) mp[x] = ++cnt;
        int nw = mp[x];
        q[nw][0].push_back(i);
        q[nw][1].push_back(j);
    }
    ll ans = 0;
    for(int o : {0, 1}) {
        for(int i = 1; i <= cnt; ++i) {
            sort(all(q[i][o]));
            ll sum = 0;
            for(int j = 0; j < q[i][o].size(); ++j) {
                ans += 1ll * j * q[i][o][j] - sum;
                sum += q[i][o][j];
            }
        }
    }
    cout << ans * 2 << "\n";
    return 0;
}