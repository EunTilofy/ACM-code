#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
const int N = 1e5 + 10;
vector<int> G[N];
int c[N], f[N][2];

void dfs(int x, int fa) {
    int pos = 0, son = 0;
    vector<int> p;
    for(int y : G[x]) if(y != fa) {
        dfs(y, x);
        son++;
        pos += f[y][0];
        p.push_back(f[y][1] - f[y][0]);
    }
    sort(all(p)), reverse(all(p));
    if(!son) {
        f[x][0] = c[x];
        f[x][1] = !c[x];
    } else {
        int tmp = pos + p[0];
        for(int i = 1; i + 1 < p.size(); i += 2) {
            int j = i + 1;
            if(p[i] + p[j] > 0) tmp += p[i] + p[j];
            else break;
        }
        for(int i = 0; i + 1 < p.size(); i += 2) {
            int j = i + 1;
            if(p[i] + p[j] > 0) pos += p[i] + p[j];
            else break;
        }
        f[x][0] = pos + c[x];
        f[x][1] = tmp + (!c[x]);
    }
    // cerr << x << " " << f[x][0] << " " << f[x][1] << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> c[i];
    for(int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    cout << max(f[1][0], f[1][1]) << "\n";
    return 0;
}