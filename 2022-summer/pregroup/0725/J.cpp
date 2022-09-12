#include<bits/stdc++.h>
using namespace std;
inline long long read() {
    long long x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 205;
int n, p[MN][2], dis[MN][MN];

#define S 0
#define T 205
#define inf 200000000

struct edge{int to,w,nex;}e[MN * MN * 2];
int hr[T + 5], cnt = 1, d[T + 5];
int q[T + 5], top;

void ins(int f, int t, int w){
    e[++cnt] = edge{t, w, hr[f]}; hr[f] = cnt;
    e[++cnt] = edge{f, 0, hr[t]}; hr[t] = cnt;
}
bool bfs(){
    memset(d, 0, sizeof d);
    register int i, j;
    for(d[q[top=i=1]=S]=1;i<=top;++i)
        for(j=hr[q[i]];j;j=e[j].nex)
        if(e[j].w&&!d[e[j].to])
            d[q[++top]=e[j].to]=d[q[i]]+1;
    return d[T];
}
int dfs(int x,int f){
    if(x==T) return f;
    register int i,used=0;
    for(i=hr[x];i;i=e[i].nex)
        if(e[i].w&&d[e[i].to]==d[x]+1){
            int w=dfs(e[i].to,min(f-used,e[i].w));
            used+=w;e[i].w-=w;e[i^1].w+=w;
            if(f==used) return f;
        }
    return d[x]=-1,used;
}
                                                                                                                                                                                  
bool chk(int x) {
    memset(hr, 0, sizeof hr); cnt = 1;
    for(int i = 1; i <= n; ++i) ins(S, i, 1);
    for(int i = 1; i <= n; ++i) ins(n + i, T, 1);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) if(dis[i][j] <= x) ins(i, n + j , 1);
    int ans = 0;
    while(bfs()) ans+=dfs(S, inf);
    //printf("%d\n", ans);
    return ans == n;
}
int main() {
    n = read();
    for(int i = 1; i <= n * 2; ++i) {
        p[i][0] = read(); p[i][1] = read();
    }
    int L = 0, R = 400000000;
    int ans = R;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) 
        dis[i][j] = abs(p[i][0] - p[j + n][0]) + abs(p[i][1] - p[j + n][1]);
    while(L <= R) {
        int mid = (L + R) >> 1;
        if(chk(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    return 0 * printf("%d\n", ans);
}
/*
2 
0 0
0 5
-1 4
8 3
*/