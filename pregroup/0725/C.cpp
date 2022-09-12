#include<bits/stdc++.h>
using namespace std;
inline long long read() {
    long long x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1000005; 
int n, m, deg[MN], X, S, sum[MN];
bool lef[MN];
std::queue<int> q;
std::vector<int> G[MN];
int main() {
    n = read(), m = read(), X = read(), S = read();
    q.push(S); lef[S] = true;
    for(int i = 1; i <= m; ++i) {
        int x, y;
        x = read(), y = read();
        G[x].push_back(y);
        G[y].push_back(x);
        if(x != y) ++deg[x], ++deg[y];
    }
    while(!q.empty()) {
        int x = q.front(); q.pop();
        
        for(int i = 0; i < G[x].size(); ++i) {
            int y = G[x][i];
            ++sum[y];
            if(sum[y] * 2ll >= deg[y] && !lef[y]) {
                lef[y] = true;
                q.push(y);
            } 
        }
    }
    return 0 * puts(lef[X]?"leave":"stay");
}