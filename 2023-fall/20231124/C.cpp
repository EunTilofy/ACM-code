#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> G[505];
int fa[505], son[505], siz[505];
int ans[505][505];

const int mod = 998244353;
int Add(int x, int y) {return (x + y) % mod;}
int Mul(int x, int y) {return 1ll * x * y % mod;}
int inv[505], fac[505], val[505], finv[505];

void dfs1(int x, int f) {
    fa[x] = f; siz[x] = 1;
    for(auto y : G[x]) if(y != fa[x]) {
        ++son[x];
        dfs1(y, x);
        siz[x] += siz[y];
    }
}
int tmp[505][505], tmpp[505][505], pos[505];

void dfs2(int x) {
    for(int i = 0; i <= son[x]; ++i) {
        for(int j = 0; j <= siz[x]; ++j) tmp[i][j] = 0;
    }
    tmp[0][0] = 1;
    for(auto y : G[x]) if(y != fa[x]) {
        for(int i = son[x]-1; ~i; --i) {
            for(int j = 0; j <= siz[x]-siz[y]; ++j) {
                tmp[i+1][j+siz[y]] = Add(tmp[i+1][j+siz[y]], tmp[i][j]);
            }
        }
    }
    for(auto y : G[x]) if(y != fa[x]) {
        for(int i = 0; i <= son[x]; ++i) 
            for(int j = 0; j <= siz[x]; ++j) {
                if(j < siz[y]) tmpp[i][j] =tmp[i][j];
                else {
                    tmpp[i][j] = Add(tmp[i][j], mod - (i?tmpp[i-1][j-siz[y]]:0));
                }
            }
        for(int i = 1; i <= n; ++i) pos[i] = 0;
        for(int i = 0; i < son[x]; ++i)
            for(int j = 0; j < siz[x]; ++j) 
                pos[j + 1] = Add(pos[j + 1], Mul(Mul(fac[i], fac[son[x]-1-i]), tmpp[i][j]));
        for(int i = 1; i <= n; ++i) if(ans[x][i]) {
            for(int j = 1; j <= n; ++j) if(i + j <= n) ans[y][i+j] = Add(ans[y][i+j], Mul(ans[x][i], pos[j]));
        }
    }
    for(auto y : G[x]) if(y != fa[x]) {
        val[y] = Mul(val[x], finv[son[x]]);
        dfs2(y);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs1(1, 0);
    int all = 1;
    for(int i = fac[0] = inv[0] = inv[1] = finv[0] = finv[1] = 1; i <= n; ++i) {
        fac[i] = Mul(fac[i-1], i);
        if(i > 1) {
            inv[i] = Mul(inv[mod % i], (mod - mod / i));
            finv[i] = Mul(finv[i-1], inv[i]);
        }
    }
    for(int i = 1; i <= n; ++i) all = Mul(all, fac[son[i]]);
    val[1] = all;
    ans[1][1] = 1;
    dfs2(1);

    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        cout << Mul(ans[i][j], val[i]) << " ";
        if(j == n) cout << "\n";
    }

    return 0;
}

/*
5
1 2
1 3
3 4
3 5
*/