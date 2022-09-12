#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
#define MN 200005
#define Mod 998244353
int n, m;
int fpow(int x, int y) {
    int r = 1;
    for(; y; y >>= 1, x = 1ll * x * x % Mod) if(y & 1) r = 1ll * r * x % Mod;
    return r;
}
std::vector<int> G[MN];
int Bl, dfn[MN], low[MN], st[MN], col[MN], top, dind, mn[MN], fa[MN];
bool in[MN];
int sum, sumx, a[MN];
void tarjan(int x) {
    low[x] = dfn[x] = ++dind;
    in[st[top++] = x] = true;
    register int i;
    for(i = 0; i < G[x].size(); ++i) {
        if(!dfn[G[x][i]]) tarjan(G[x][i]), low[x] = min(low[x], low[G[x][i]]);
        else if(in[G[x][i]]) low[x] = min(low[x], dfn[G[x][i]]);
    }
    if(dfn[x] == low[x]) {
        for(++Bl; st[top] ^ x; in[st[--top]] = false) col[st[top - 1]] = Bl;
    }
}

int main() {
    n = read();
    m = read();
    for(int i = 1; i <= n; ++i) a[i] = read(), sum = (sum + a[i]) % Mod; 
    for(int i = 1; i <= m; ++i) {
        int x, y;
        x = read(), y = read();
        G[x].push_back(y);
    }
    for(int i = 1; i <= n; ++i) if(!dfn[i]) tarjan(i);
    memset(mn, 0x3f, sizeof mn);
    for(int i = 1; i <= n; ++i) mn[col[i]] = min(mn[col[i]], a[i]);
    for(int i = 1; i <= n; ++i) for(int j = 0; j < G[i].size(); ++j) {
        int x = col[i], y = col[G[i][j]];
        if(x != y) fa[y] = x;
    }
    for(int i = 1; i <= Bl; ++i) if(!fa[i]) sumx = (sumx + mn[i]) % Mod;
    printf("%d\n", (1ll * sumx * fpow(sum, Mod - 2)) % Mod);
    return 0;
}

/*
4 5
2 1 2 1
1 2
2 3
3 1
2 4
4 1
*/