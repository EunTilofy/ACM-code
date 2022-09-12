#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 5e5 + 5;
bool vis[MN], lef[MN];
int deg[MN];
int l, r;
vector<int> G[MN];
int p[MN];
int main() {
    int n = read();
    for(int i = 1; i < n; ++i) {
        int x = read();
        int y = read(); 
        G[x].push_back(y);
        G[y].push_back(x);
        ++deg[x], ++deg[y];
    }
    for(int i = 1; i <= n; ++i) {
        if(deg[i] == 1) lef[i] = 1;
    }
    for(int i = 1; i <= n; ++i) if(lef[i]) --deg[G[i][0]];
    int i = 1, j;
    while(i <= n && (lef[i] == 1 || deg[i] > 1)) ++i;
    l = 1; r = n; int q = 1;
    while(i) {
        vis[i] = 1;
        if(!q) p[i] = r--;
        else p[i] = l++;
        q ^= 1;
        int nx = 0;
        for(j = 0; j < G[i].size(); ++j) {
            if(lef[G[i][j]]) {
                vis[G[i][j]] = 1;
                if(!q) p[G[i][j]] = r--;
                else p[G[i][j]] = l++;
            }
            else if(!vis[G[i][j]]) nx = G[i][j];
        }
        i = nx;
    }
    for(int i = 1; i <= n; ++i) printf("%d ", p[i]);
    return 0;
}