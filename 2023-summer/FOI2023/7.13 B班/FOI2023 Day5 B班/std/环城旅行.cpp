#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > G[100005];
#define MN 100005
int dfn[MN], bel[MN], low[MN], dind, top;
int st[MN];

int mx[MN], mi[MN], block;

void tar(int x, int f) {
    low[x] = dfn[x] = ++dind;
    st[++top] = x;
    for(auto [y, w] : G[x]) if(y != f) {
        if(dfn[y]) low[x] = min(low[x], dfn[y]);
        else {
            tar(y, x);
            low[x] = min(low[x], low[y]);
        }
    }
    if(dfn[x] == low[x]) {
        ++block;
        while(st[top + 1] != x) bel[st[top]] = block, --top;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        G[x].push_back({y, w});
        G[y].push_back({x, w});
    }

    for(int i = 1; i <= n; ++i) {
        mi[i] = 1000000005;
        mx[i] = -mi[i];
        if(!dfn[i]) tar(i, 0);
    }

    for(int x = 1; x <= n; ++x) for(auto [y, w] : G[x]) if(bel[x] == bel[y]) {
        mi[bel[x]] = min(mi[bel[x]], w);
        mx[bel[x]] = max(mx[bel[x]], w);
    }

    int ans = 0;
    for(int i = 1; i <= block; ++i) ans = max(ans, mx[i] - mi[i]);
    cout << ans;
    return 0;
}