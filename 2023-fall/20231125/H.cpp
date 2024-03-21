#include<bits/stdc++.h>
using namespace std;

const int MN = 305;
pair<int,int> p[MN];
const int mod = 998244353;
int f[MN][2][MN][MN], tmp[2][MN][MN];
int Add(int x, int y) {return (x + y) % mod;}
int Mul(int x, int y) {return 1ll * x * y % mod;}
// #define Max(x, y) ((x)>(y)?(x):(y))
int n, m, fa[MN];
vector<int> G[MN], H[MN];
int dep[MN], inv[MN], siz[MN];
void dfs(int x) {
    // merge from son
    f[x][0][0][0] = siz[x] = 1;
    for(auto y : G[x]) {
        dfs(y);
        memset(tmp, 0, sizeof tmp);
        for(int k1 = 0; k1 < 2; ++k1) for(int s1 = 0; s1 <= siz[y]; ++s1) for(int h1 = 0; h1 < dep[y]; ++h1) if(f[y][k1][s1][h1])
        for(int k2 = 0; k2 < 2; ++k2) for(int s2 = 0; s2 < siz[x]; ++s2) for(int h2 = 0; h2 <= dep[x]; ++h2) if(f[x][k2][s2][h2]) {
            tmp[k1^k2][s1+s2][max(h1, h2)] = Add(tmp[k1^k2][s1+s2][max(h1, h2)], Mul(f[y][k1][s1][h1], f[x][k2][s2][h2]));
        }
        memcpy(f[x], tmp, sizeof tmp);
        siz[x] += siz[y];
    }
    // add b[i] = x
    for(auto hh : H[x]) {
        memset(tmp, 0, sizeof tmp);
        for(int k = 0; k < 2; ++k) for(int s = 0; s < siz[x]; ++s) for(int h = 0; h <= dep[x]; ++ h) {
            tmp[k^1][s][max(h, hh+1)] = Add(tmp[k^1][s][max(h, hh+1)], f[x][k][s][h]);
        }
        for(int k = 0; k < 2; ++k) for(int s = 0; s < siz[x]; ++s) for(int h = 0; h <= dep[x]; ++ h)
            f[x][k][s][h] = Add(f[x][k][s][h], tmp[k][s][h]);
    }
    // pushdown
    memset(tmp, 0, sizeof tmp);
    for(int k = 0; k < 2; ++k) for(int s = 0; s < siz[x]; ++s) for(int h = 0; h <= dep[x]; ++h) {
        if(h) tmp[k][s+1][h-1] = Add(tmp[k][s+1][h-1], f[x][k][s][h]);
        else tmp[k][s][0] = Add(tmp[k][s][0], f[x][k][s][0]);
    }
    memcpy(f[x], tmp, sizeof tmp);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dep[1] = 1;
    for(int i = 2; i <= n; ++i) cin >> fa[i], G[fa[i]].push_back(i), dep[i] = dep[fa[i]] + 1;
    for(int i = 1; i <= m; ++i) cin >> p[i].first >> p[i].second, H[p[i].second].push_back(dep[p[i].second] - dep[p[i].first]);
    dfs(1);
    int ans = 0;
    for(int i = (inv[0] = inv[1] = 1) + 1; i <= n; ++i) inv[i] = Mul(inv[mod%i], (mod-mod/i));
    for(int i = 1; i <= n; ++i) for(int k = 0; k < 2; ++k) {
        // cerr << i << " " << k << " " << f[1][k][i][0] << "\n";
        ans = Add(ans, Mul((k ? 1 : mod - 1), Mul(f[1][k][i][0], inv[i])));
    }
    ans = Mul(ans, n);
    cout << ans << "\n";
    return 0;
}

/*
3 3
1 1
1 2
3 3
1 1
*/