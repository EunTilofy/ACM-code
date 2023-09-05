#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int M = 64, N = 1e5 + 10;
int vs[N];
vector<pair<int, ll> > G[N];
struct node {
    ll w;
    int id[N];
} a[M];

int col = 0;
void dfs(int x, int o) {
    if(vs[x] == o) return ;
    vs[x] = o, a[o].id[x] = col;
    // cerr << x << " " << o << "\n";
    for(auto[y, w] : G[x]) if((w & a[o].w) == a[o].w) {
        dfs(y, o);
    }
}

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m, q;
    ll V;
    cin >> n >> m >> q >> V;
    for(int i = 1; i <= m; ++i) {
        int x, y; ll v;
        cin >> x >> y >> v;
        G[x].push_back({y, v});
        G[y].push_back({x, v});
    }
    int res = 0;
    if(V) {
        vector<int> p;
        for(int i = 59; i >= 0; --i) {
            if((V >> i) & 1) p.push_back(i);
        }
        for(int i = p[0] + 1; i <= 59; ++i) a[++res].w = (1ll << i);
        ll nw = (1ll << p[0]);
        // for(int x : p) cerr << x << " "; cerr << "\n";
        for(int i = 1; i < p.size(); ++i) {
            for(int j = p[i] + 1; j < p[i - 1]; ++j) a[++res].w = nw | (1ll << j);
            nw |= (1ll << p[i]);   
        }
        a[++res].w = nw;
    } else {
        a[++res].w = 0;
    }
    for(int o = 1; o <= res; ++o) {
        // cerr << a[o].w << "\n";
        col = 0;
        for(int i = 1; i <= n; ++i) if(vs[i] != o) ++col, dfs(i, o);
        // for(int i = 1; i <= n; ++i) cerr << a[o].id[i] << " "; cerr << "\n";
    }
    for(int o = 1, x, y; o <= q; ++o) {
        cin >> x >> y;
        int flg = 0;
        for(int i = 1; i <= res; ++i) {
            if(a[i].id[x] == a[i].id[y]) {flg = 1;break;}
        }
        if(flg) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}