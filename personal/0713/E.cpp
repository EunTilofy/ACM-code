#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1e5 + 5;
struct edge{int fr, to, nex, w;}e[MN << 1];
int en = 1, hr[MN];
int n, m;
inline void ins(int x, int y, int w) {
    e[++en] = (edge){x, y, hr[x], w}; hr[x] = en;
    e[++en] = (edge){y, x, hr[y], w}; hr[y] = en;
}
int dind, dfn[MN], low[MN], st[MN], tp;
long long ans;
#define INF 2e9 + 2
void tarjan(int x, int from) {
    dfn[x] = low[x] = ++dind;
    st[tp++] = from;
    for(int i = hr[x]; i; i = e[i].nex) if(i ^ from ^ 1) {
        if(!dfn[e[i].to]) {
            tarjan(e[i].to, i);
            low[x] = min(low[x], low[e[i].to]);
            if(low[e[i].to] > dfn[x]) {
                long long mx = -INF, mn = INF;
                while(st[tp - 1] != i) {
                    long long val = e[st[--tp]].w;
                    mn = min(mn, val);
                    mx = max(mx, val);
                }
                --tp;
                ans = max(ans, mx - mn);
            }
        }
        else {
            low[x] = min(low[x], dfn[e[i].to]);
            if(dfn[e[i].to] < dfn[x]) st[tp++] = i;
        }
    }
}
signed main() {
    n = read(); m = read();
    ins(n + 1, 1, 0);
    for(int i = 1; i <= m; ++i) {
        int x = read();
        int y = read();
        ins(x, y , read());
    }
    ans = -INF;
    tarjan(n + 1, 0);
    printf("%lld\n", ans);
    return 0;
}
/*
5 7
1 2 1
1 3 -2
2 3 1
3 4 3
4 5 1
1 5 -1
2 5 2
*/