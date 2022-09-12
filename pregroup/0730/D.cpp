#include<bits/stdc++.h>
using namespace std;
int read(void) {
    int ch = getchar(), res = 0, flg = 0;
    while (!isdigit(ch) && ch != '-')
        ch = getchar();
    if (ch == '-')
        flg = 1, ch = getchar();
    for (; isdigit(ch); ch = getchar())
        res = (res << 1) + (res << 3) + (ch - '0');
    return flg ? -res : res;
}
const int MN = 2e5 + 5;
int cnt, tr[MN][26], fail[MN], l[MN], r[MN], dind;
int n;
std::vector<int> G[MN];
void dfs(int x) {
    l[x] = ++dind;
    for(int i = 0; i < G[x].size(); ++i) dfs(G[x][i]);
    r[x] = dind;
}
int t[MN];
void C(int x, int y) {
    for(; x <= n; x += (x & -x)) t[x] += y;
}
int G_(int x) {
    int r = 0;
    for(; x; x -= (x & -x)) r += t[x];
    return r;
}
void add(int L, int R) {
    C(L, 1);
    C(R + 1, -1);
}
int que(int x) {
    return G_(l[x]);
}
void build() {
    queue<int> q;
    memset(fail, 0, sizeof fail);
    for(int i = 0; i < 26; ++i) if(tr[0][i]) q.push(tr[0][i]);
    while(!q.empty()) {
        int k = q.front();
        q.pop();
        for(int i = 0; i < 26; ++i) {
            if(tr[k][i])
                fail[tr[k][i]] = tr[fail[k]][i], q.push(tr[k][i]);
            else tr[k][i] = tr[fail[k]][i];
        }
    }
    for(int i = 0; i <= cnt; ++i) G[i].clear();
    for(int i = 1; i <= cnt; ++i) G[fail[i]].push_back(i);
    dind = 0; dfs(0);
}

std::pair<int, int> p[MN];

int main() {
    int T = read();
    while(T--) {
        n = read();
        cnt = n - 1;
        memset(t, 0, sizeof t);
        memset(tr, 0, sizeof tr);
        for(int i = 1; i < n; ++i) {
            int father = read() - 1;
            char c;
            scanf("%c", &c);
            tr[father][c - 'a'] = i;
        }
        build();
        int Q = read();
        while(Q--) {
            int opt = read();
            if(opt == 1) {
                int _ = read();
                for(int i = 1; i <= _; ++i) {
                    int x = read() - 1;
                    p[i] = make_pair(l[x], r[x]);
                }
                std::sort(p + 1, p + _ + 1);
                int nowl = p[1].first, nowr = p[1].second;
                for(int i = 2; i <= _; ++i) {
                    if(p[i].first > nowr) {
                        add(nowl, nowr);
                        nowl = p[i].first;
                        nowr = p[i].second;
                    }
                    else nowr = max(nowr, p[i].second);
                }
                add(nowl, nowr);
            }
            else {
                int x = read() - 1;
                printf("%d\n", que(x));
            }
        }
    }
    return 0;
}

/*
1
6
1 a
1 b
1 c
3 a
3 b
7
1 2 2 3
2 5
1 2 3 4
2 6
2 1
1 2 1 2
2 6
*/