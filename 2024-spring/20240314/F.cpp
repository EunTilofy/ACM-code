#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int f[N], vs[N], flg = 0;
vector<int> G[N], pa;

void dfs(int x, int fa) {
    vs[x] = 1, f[x] = fa;
    for(int y : G[x]) if(y != fa) {
        if(flg) return ;
        if(vs[y]) {
            int nw = x;
            while(nw != y) {
                pa.push_back(nw);
                nw = f[nw];
            }
            pa.push_back(nw);
            flg = 1;
            return ;
        }
        dfs(y, x);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    pa.clear(); flg = 0;
    for(int i = 1; i <= n; ++i) {
        vs[i] = 0;
        G[i].clear();
    }
    for(int i = 1, x, y; i <= n; ++i) {
        cin >> x >> y;
        G[x].push_back(y), G[y].push_back(x);
        d[x]++, d[y]++;
    }
    // return ;
    dfs(1, 0);
    int cnt = 0, pd = 1;
    vector<int> mk(n + 1);
    for(int x : pa) mk[x] = 1;
    for(int i = 1; i <= n; ++i) if(!mk[i]) {
        if(d[i] <= 3) ++cnt;
        else if(d[i] > 4) pd = 0;
    }
    int len = pa.size();
    ll ans = 0;
    vector<int> nm(10);
    for(int x : pa) {
        if(d[x] > 5) pd = 0;
        nm[d[x]]++;
    }
    for(int I = 0; I < len; ++I) {
        int J = (I + 1) % len;
        int i = pa[I], j = pa[J];
        nm[d[i]]--, nm[d[j]]--;
        nm[d[i] - 1]++, nm[d[j] - 1]++;
        if(!nm[5]) ans += cnt + nm[1] + nm[2] + nm[3];
        nm[d[i]]++, nm[d[j]]++;
        nm[d[i] - 1]--, nm[d[j] - 1]--;
    }
    if(!pd) cout << "0\n";
    else {
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}