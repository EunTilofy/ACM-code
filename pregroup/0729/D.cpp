#include<bits/stdc++.h>
using namespace std;
const int MN = 6e5 + 5;
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
int n, q;
struct edge{int to, nex;}e[MN << 1];
int hr[MN], en;
char s[MN];
void ins(int x, int y) {
    e[++en] = (edge){y, hr[x]}; hr[x] = en;
    e[++en] = (edge){x, hr[y]}; hr[y] = en;
}
int dind, pos[MN], siz[MN], mx[MN], top[MN], id[MN], fa[MN];
void dfs1(int x, int f) {
    siz[x] = 1; fa[x] = f;
    for(int i = hr[x]; i; i = e[i].nex) if(e[i].to ^ f) {
        dfs1(e[i].to, x);
        siz[x] += siz[e[i].to];
        if(siz[e[i].to] > siz[mx[x]]) mx[x] = e[i].to;
    }
}
void dfs2(int x, int f, int Top) {
    top[x] = Top; pos[x] = ++dind; id[pos[x]] = x;
    if(mx[x]) dfs2(mx[x], x, Top);
    for(int i = hr[x]; i; i = e[i].nex) if(e[i].to != f && e[i].to != mx[x]) {
        dfs2(e[i].to, x, e[i].to);
    }
}

std::vector<int> be_asked[MN];
int pre[MN];
int _[MN], o[MN], lenq[MN];

class AC {
    private:
        int tr[MN][26], cnt, fail[MN], l[MN], r[MN], ddind;
        std::vector<int> G[MN];
        void Dfs(int x) {
            l[x] = ++ddind;
            for(int i = 0; i < G[x].size(); ++i) Dfs(G[x][i]);
            r[x] =ddind;
        }
        int t[MN];
        void C(int x, int y) {
            for(;x <= cnt; x += (x & -x)) t[x] += y;
        }
        int G_(int x) {
            int r = 0;
            for(; x; x-= (x & -x)) r += t[x];
            return r;
        }
        void add(int x) {
            C(l[x], 1);
        }
        int que(int x) {
            return G_(r[x]) - G_(l[x] - 1);
        }
    public:
        int insert(char *s) {
            int p = 0;
            for(int i = 0; s[i]; i++) {
                int k = s[i] - 'a';
                if(!tr[p][k]) tr[p][k] = ++cnt;
                p = tr[p][k];
            }
            return p;
        }
        void build() {
            queue<int> q;
            memset(fail, 0, sizeof fail);
            for(int i = 0; i < 26; ++i) if(tr[0][i]) q.push(tr[0][i]);
            while(!q.empty()) {
                int k = q.front();
                q.pop();
                for(int i = 0; i < 26; ++i)
                    if(tr[k][i]) 
                        fail[tr[k][i]] = tr[fail[k]][i], q.push(tr[k][i]);
                    else tr[k][i] = tr[fail[k]][i];
            }
            for(int i = 1; i <= cnt; ++i) G[fail[i]].push_back(i);
            ddind = 0; Dfs(0);
        }
        void solve(int *ss, int len) {
            memset(t, 0, sizeof t);
            int p = 0, res = 0;
            for(int i = 0; i < len; ++i) {
                p = tr[p][s[ss[i]] - 'a'];
                add(p);
                for(int j = 0; j < be_asked[ss[i]].size(); ++j) {
                    pre[be_asked[ss[i]][j]] += que(_[be_asked[ss[i]][j]]);
                }
            }
        }
}ac;

int nex[MN];
void KMP(char *s, int len) {
    int i, k = 0;
    for(nex[1] = 0, i = 2; i <= len; ++i) {
        while(k && s[k + 1] != s[i]) k = nex[k];
        if(s[k + 1] == s[i]) nex[i] = ++k;
        else nex[i] = 0;
    }
}
int Match(char *s, int lens, char* t, int lent) {
    int i, k = 0, tot = 0;
    for(i = 1; i <= lent; ++i) {
        while(k && s[k + 1] != t[i]) k = nex[k];
        if(s[k + 1] == t[i]) ++k;
        if(k == lens) ++tot, k = nex[k];
    }
    return tot;
}

char t[MN];
int tmp[MN], fr[MN];
char _tmp[MN];

int main() {
    n = read();
    scanf("%s", s + 1);
    for(int i = 1; i < n; ++i) {
        int x, y;
        x = read(), y = read();
        ins(x, y);
    }
    dfs1(1, 0); dfs2(1, 0, 1);
    q = read();
    fr[1] = 1;
    for(int i = 1; i <= q; ++i) {
        o[i] = read();

        int x = o[i];
        while(x) {
            be_asked[x].push_back(i);
            x = fa[top[x]];
        }

        scanf("%s", t + fr[i]);
        lenq[i] = strlen(t + fr[i]);
        _[i] = ac.insert(t + fr[i]);
        fr[i + 1] = fr[i] + lenq[i];
    }
    ac.build();
    for(int i = 1; i <= n; ++i) {
        if(top[i] == i) {
            int len = 0;
            tmp[len ++] = i;
            for(int j = pos[i] + 1; j <= n; ++j) {
                if(top[id[j]] == id[j]) break;
                tmp[len ++] = id[j];
            }
            ac.solve(tmp, len);
        }
    }
    for(int i = 1; i <= q; ++i) {
        int ans = pre[i];
        int x = o[i];
        KMP(t + fr[i] - 1, lenq[i]);
        if(lenq[i] > 1) {
        while(x) {
            if(top[x] == 1) break; 
            int l2, r2;
            r2 = pos[x];
            l2 = pos[top[x]];

            if(r2 - l2 + 1 >= lenq[i]) r2 = l2 + lenq[i] - 2;
            int len = 0;
            for(int j = r2; j >= l2; --j) _tmp[++len] = s[id[j]];
            int xx = fa[top[x]];
            for(int j = 1; j < lenq[i]; ++j) {
                if(xx) _tmp[++len] = s[xx], xx = fa[xx];
                else break;
            } 
            for(int j = 1; j + j <= len; ++j) swap(_tmp[j], _tmp[len - j + 1]);
            ans += Match(t + fr[i] - 1, lenq[i], _tmp, len);

            x = fa[top[x]];
        }
        }
        for(int i = 1; i <= lenq[i]; ++i) nex[i] = 0;
        printf("%d\n", ans);
    }
    return 0;
}