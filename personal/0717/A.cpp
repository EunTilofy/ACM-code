#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
#define Mod 202207097
#define MN 400005
int fpow(int x, int y) {
    int r = 1;
    for(; y; y >>= 1, x = 1ll * x * x % Mod) if(y & 1) r = 1ll * r * x % Mod;
    return r;
}
int Add(int x, int y) {return (x + y) % Mod;}
int Mul(int x, int y) {return 1ll * x * y % Mod;}
int Div(int x, int y) {return Mul(x, fpow(y, Mod - 2));}
int n, fa[MN], Q, root, deg[MN];
std::vector<int> G[MN];
int p[MN], q[MN];

int siz[MN], mx[MN], top[MN], dep[MN];

void dfs1(int x) {
    int sum = 0;
    siz[x] = 1; dep[x] = dep[fa[x]] + 1;
    for(int i = 0; i < G[x].size(); ++i) {
        dfs1(G[x][i]), sum = Add(sum, p[G[x][i]]);
        siz[x] += siz[G[x][i]];
        if(siz[G[x][i]] > siz[mx[x]]) mx[x] = G[x][i];
    }
    if(x == root) p[x] = 0;
    else p[x] = Add(sum, deg[x]);
    // printf("p[%d] = %d\n", x, p[x]);
}
void dfs2(int x, int sum) {
    if(x == root) q[x] = 0;
    else q[x] = Add(Add(deg[fa[x]], q[fa[x]]), Add(sum, Mod - p[x]));
    // printf("q[%d] = %d\n", x, q[x]);
    int _ = 0;
    for(int i = 0; i < G[x].size(); ++i) _ = Add(_, p[G[x][i]]);
    for(int i = 0; i < G[x].size(); ++i) dfs2(G[x][i], _);
}
void dfs3(int x) {
    p[x] = Add(p[fa[x]], p[x]);
    q[x] = Add(q[fa[x]], q[x]);
    for(int i = 0; i < G[x].size(); ++i) dfs3(G[x][i]);
}
void dfs4(int x, int tp) {
    top[x] = tp;
    if(mx[x]) dfs4(mx[x], tp);
    for(int i = 0; i < G[x].size(); ++i) if(G[x][i] != mx[x]) dfs4(G[x][i], G[x][i]);
}
int LCA(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}
int sol(int x, int y) {
    int lca = LCA(x, y);
    // printf("LCA(%d, %d) = %d\n", x, y , lca);
    return Add(Add(p[x], Mod - p[lca]), Add(q[y], Mod - q[lca]));
}
int main() {
    n = read(); Q = read();
    for(int i = 1; i <= n; ++i) {
        fa[i] = read();
        if(fa[i] == i) root = i, fa[i] = 0;
        else {
            G[fa[i]].push_back(i);
            ++deg[i];
            ++deg[fa[i]];
        }
    }
    // printf("root = %d\n", root);
    dfs1(root); dfs2(root, p[root]);
    dfs3(root); dfs4(root, root);
    while(Q--) {
        int x = read();
        printf("%d\n", sol(x, read()));
    }
    return 0;
}
/*
3 2
1 1 2
1 2
1 3
*/