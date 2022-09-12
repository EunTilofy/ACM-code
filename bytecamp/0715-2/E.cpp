#include<bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch <='9' && ch >='0') {x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}
const int MN = 1e6 + 5;
int hr[MN];
struct edge{int to, id, nex;}e[MN];
int en;
int n, m, b;
namespace dir
{
    std::vector<int> uu,vv,idd;
    int ind[MN], outd[MN], st[MN], top = 0;
    bool mark[MN];
    inline void Ins(int u, int v, int id) {
        e[++en] = (edge){v, id, hr[u]};
        hr[u] = en;
    }
    inline void ins(int u, int v, int id) {
        uu.push_back(u); 
        vv.push_back(v);
        idd.push_back(id);
        ++ind[v]; ++outd[u];
    }
    void dfs(int u)
    {
        for(int &i = hr[u]; i; i = e[i].nex)if(!mark[i])
        {
            mark[i] = 1; int j = i;
            dfs(e[i].to); st[++top] = j;
        }
    }
    int solve() {
        int S = -1, T = -1;
        for(int i = 0; i < m; ++i) {
            if(ind[i] != outd[i]) {
                if(ind[i] - 1 == outd[i]) {
                    if(T != -1) return 0;
                    T = i;
                }
                else if(ind[i] + 1 == outd[i]) {
                    if(S != -1) return 0;
                    if(i != b - 1) return 0;
                    S = i;
                }
                else return 0;
            }
        }
        int all = n;
        if((S == -1) + (T == -1) == 1) return 0;
        if(S != -1 && T != -1) Ins(T, S, -1), ++all;
        for(int i = uu.size() - 1; ~i; --i) Ins(uu[i], vv[i], idd[i]);
        if(!hr[b - 1]) return 0;
        dfs(b - 1);
        if(top != all) return 0;
        for(int i = top; i; --i) {
            if(e[st[i]].id > 0) printf("%d ", e[st[i]].id);
        }
        return 1;
    }
};
char s[MN];
int main() {
    n = read(), m = read(), b = read();
    for(int i = 1; i <= n; ++i) {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int pre = 0;
        int suf = 0;
        while(pre + 1 <= len && s[pre + 1] == '0') ++pre;
        while(len - suf >= 1 && s[len - suf] == '0') ++suf;
        bool flag = 1;
        if((len - suf - pre - 1) % m != 0) return 0 * puts("-1");
        for(int j = pre + 1; j < len - suf; j += m) {
            flag &= s[j] == '1';
            for(int k = j + 1; k < j + m; ++k) flag &= s[k] == '0';
        }
        if(!flag) return 0 * puts("-1");
        if(pre >= m || suf >= m) return 0 * puts("-1");
        dir::ins(pre, m - 1 - suf, i);
    }
    if(dir::solve() == 0) puts("-1");
    return 0;
}
/*
5 4 3
0100010
00100
001000100
0010
0100010
*/