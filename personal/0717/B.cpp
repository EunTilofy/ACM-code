#include<bits/stdc++.h>
using namespace std;
int n;
const int MN = 3e5 + 5;
int en, hr[MN];
struct edge{int to, nex, w;}e[MN<<2];
void ins(int x, int y, int w) {
    e[++en] = (edge){y, hr[x], w}; hr[x] = en;
    e[++en] = (edge){x, hr[y], w}; hr[y] = en;
}
bool in[MN];
int root, fa[MN], len[MN], mx[MN], siz[MN], all;
void dfs(int x, int f, int Len) {
    len[x] = Len;
    fa[x] = f;
    mx[x] = 0;
    ++all;
    siz[x] = 1;
    for(int i = hr[x]; i; i = e[i].nex) if(e[i].to != f && !in[e[i].to]) {
        dfs(e[i].to, x, e[i].w);
        if(len[mx[x]] > len[mx[e[i].to]]) mx[x] = mx[e[i].to];
        if(len[mx[x]] > e[i].w) mx[x] = e[i].to;
        siz[x] += siz[e[i].to];
    } 
}
void del(int x, int f) {
    in[x] = 1;
    for(int i = hr[x]; i; i = e[i].nex) if(e[i].to != f && e[i].to && !in[e[i].to]) 
        del(e[i].to, x);
}
void del2(int x,int exp) {
    in[x] = 1;
    for(int i = hr[x]; i; i = e[i].nex)
        if(e[i].to != fa[x] && !in[e[i].to] && e[i].to != exp)
            del2(e[i].to, exp);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        ins(x, y, w);
    }
    long long ans = 0;
    for(int _ = 1; _ <= 50; ++_) {
        root = 1;
        while(in[root] && root <= n) ++root;
        if(root > n) break;
        all = 0; len[0] = 0x7fffffff;
        dfs(root, 0, 0);
        int x = mx[root];
        if(all == 1) break;
        if(siz[x] * 2 >= all) {
            ans += 1ll * siz[x] *len[x];
            del(x, fa[x]);
        }
        else {
            ans += 1ll * (all - siz[x]) * len[x];
            del2(root, x);
        }
    }
    return 0 * printf("%lld\n", ans);
}