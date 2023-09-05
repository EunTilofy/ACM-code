#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll f[N][3];
int val[N], c[N], nm[N], sz[N];
vector<int> G[N];

void dfs(int x) {
    sz[x] = 1;
    ll sum = 0, pos = 0;
    vector<ll> a;
    for(int y : G[x]) {
        dfs(y);
        sz[x] += sz[y];
        if(sz[y] % 2 == 0) sum += f[y][0];
        else sum += f[y][1], pos++, a.push_back(f[y][2] - f[y][1]);
    }
//     cout << x << " " << sz[x] << "\n";
    if(c[x]) {
        pos++;a.push_back(val[x]);
    } else {
        pos++, sum += val[x];
        a.push_back(-val[x]);
    }
    sort(all(a));
    if(sz[x] & 1) {
        int len = pos / 2;
        for(int i = 0; i < len; ++i) sum += a[i];
        f[x][1] = sum;
        f[x][2] = sum + a[len];
//         cout << f[x][1] << " " << f[x][2] << "\n";
    } else {
        int len = pos / 2;
        for(int i = 0; i < len; ++i) sum += a[i];
        f[x][0] = sum;
//         cout << f[x][0] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i] >> val[i] >> nm[i];
        for(int j = 1, x; j <= nm[i]; ++j) {
            cin >> x;
            G[i].push_back(x);
        }
    }
    dfs(1);
    if(sz[1] & 1) {
        cout << min(f[1][1], f[1][2]) << "\n";
    } else cout << f[1][0] << "\n";
    return 0;
}