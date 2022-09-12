#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >='0' && ch <='9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1e5+5;
int n, m, p;
typedef pair<int, int> pii;
std::vector<pii> G[MN << 1];
long long d[MN << 1], st[MN << 1];
#define se second
#define fi first
void dfs(int x, long long dis, int step, int fa) {
    d[x] = dis; st[x] = step;
    for(int i = 0; i < G[x].size(); ++i) if(G[x][i].se ^ fa) {
        dfs(G[x][i].se, dis + G[x][i].fi, step + 1, x);
    }
}
int main() {
    n = read(); m = read(); p = read();
    for(int i = 1; i < n; ++i) {
        int x = read();
        int y = read();
        int l = read();
        G[x].push_back(make_pair(l, y));
        G[y].push_back(make_pair(l, x));
    }
    for(int i = 1; i < m; ++i) {
        int x = read() + n;
        int y = read() + n;
        int l = read();
        G[x].push_back(make_pair(l, y));
        G[y].push_back(make_pair(l, x));
    }
    dfs(1, 0, 0, 0); dfs(n + 1, 0, 0, 0);
    int l1 = 1, l2 = 1 + n;
    for(int i = 1; i <= n; ++i) {
        if(st[i] > st[l1]) l1 = i;
        else if(st[i] == st[l1] && d[i] < d[l1]) l1 = i;
    }
    for(int i = n + 1; i <= n + m; ++i) {
        if(st[i] > st[l2]) l2 = i;
        else if(st[i] == st[l2] && d[i] < d[l2]) l2 = i;
    }
    dfs(l1, 0, 0, 0); dfs(l2, 0, 0, 0);
    int r1 = l1, r2 = l2;
    for(int i = 1; i <= n; ++i) {
        if(st[i] > st[r1]) r1 = i;
        else if(st[i] == st[r1] && d[i] < d[r1]) r1 = i;
    }
    for(int i = n + 1; i <= n + m; ++i) {
        if(st[i] > st[r2]) r2 = i;
        else if(st[i] == st[r2] && d[i] < d[r2]) r2 = i;
    }
    return 0 * printf("%lld\n", d[r1] + d[r2] + p);
}