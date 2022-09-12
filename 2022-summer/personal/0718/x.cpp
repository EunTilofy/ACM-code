#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 5e5 + 5;
vector<int> G[MN];
int a[MN];
bool f[MN], ans[MN];
void dfs1(int x, int fa) {
    for(int i = 0; i < G[x].size(); ++i) if(G[x][i] != fa) dfs1(G[x][i], x);
    f[x] = 0;
    for(int i = 0; i < G[x].size(); ++i) if(G[x][i] != fa) {
        f[x] |= (a[x] > a[G[x][i]] && f[G[x][i]] == 0);
    }
}
void dfs2(int x, int fa){
    ans[x] = f[x];
    for(int i = 0; i < G[x].size(); ++i) if(G[x][i] != fa) {
        int _1 = f[x], _2 = f[G[x][i]];
        f[G[x][i]] |= (a[G[x][i]] > a[x] && f[x] == 0);
        dfs2(G[x][i], x);
        f[G[x][i]] = _2;
    }
}
int main() {
    int n = read();
    for(int i = 1; i <= n; ++i) a[i] = read();
    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    return 0;
}