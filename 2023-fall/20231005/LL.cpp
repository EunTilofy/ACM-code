#include<bits/stdc++.h>
using namespace std;

const int MN = 505;
int g, l;
string s[MN], t[MN];
int ans[MN], L[30], R[30];
bool no[MN][30];

#define S 530
#define SS 531
#define T 532
#define TT 533
// 1 - 26
// 27 - N + 26
const int inf = 0x3f3f3f3f;
struct edge{int to, nex, w;} e[MN*MN];
int en = 1, hr[MN+50], cur[MN+50];
int d[MN+50], q[MN+50], top;
void ins(int x, int y, int w) {
    e[++en]=(edge){y, hr[x], w}; hr[x] = en;
    e[++en]=(edge){x, hr[y], 0}; hr[y] = en;
}
bool bfs() {
    memset(d, 0, sizeof d);
    int i,j;
    for(d[q[i=top=1]=SS]=1;i<=top;++i)
        for(j=hr[q[i]];j;j=e[j].nex)
            if(e[j].w&&!d[e[j].to])
                d[q[++top]=e[j].to]=d[q[i]]+1;
    return d[TT];
}
int dfs(int x, int f) {
    if(x==TT) return f;
    int used=0;
    for(int &i=cur[x];i;i=e[i].nex)
        if(d[e[i].to]==d[x]+1&&e[i].w) {
            int tmp = dfs(e[i].to, min(f-used, e[i].w));
            e[i].w -= tmp; e[i^1].w+=tmp; used+=tmp;
            if(used==f) return used;
        }
    return d[x]=-1, used;
}
int dinic() {
    int mf=0;
    while(bfs()) {
        memcpy(cur, hr, sizeof cur);
        mf += dfs(SS, inf);
    }
    return mf;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> g >> l; --g;
    for(int i = 1; i <= g; ++i) {
        cin >> s[i] >> t[i];
        for(int j = 0; j < l; ++j) {
            if(t[i][j] == 'G') {
                ans[j] = s[i][j] - 'a' + 1;
                for(int k = 1; k <= 26; ++k) {
                    if(k != s[i][j] - 'a' +1) {
                        no[j][k] = 1;
                    }
                }
            } else {
                no[j][s[i][j]-'a'+1] = 1;
            }
        }
    }
    for(int c = 1; c <= 26; ++c) {
        int les = 0;
        R[c] = l;
        for(int i = 1; i <= g; ++i) {
            int _ = 0;
            bool black = 0;
            for(int j = 0; j < l; ++j) {
                if(s[i][j] == c+'a'-1 && t[i][j] != 'B') ++_;
                if(s[i][j] == c+'a'-1 && t[i][j] == 'B') black = 1;
            }
            les = max(les, _);
            if(black) R[c] = les;
        }
        L[c] = les;
        // cerr << (char)(c+'a'-1) << " " << L[c] << " " << R[c] << "\n";
    }
    int sm = l;
    for(int i = 1; i <= 26; ++i) {
        if(L[i]>0) {
            ins(SS, i, L[i]);
            sm -= L[i];
        }
        if(L[i] < R[i]) {
            ins(S, i, R[i]-L[i]);
        }
        for(int j = 1; j <= l; ++j) {
            if(!no[j-1][i]) {
                ins(i, j+26, 1);
            }
        }
    }
    for(int i = 1; i <= l; ++i) {
        ins(i+26, TT, 1);
    }
    assert(sm >= 0);
    if(sm > 0) ins(SS, S, sm);

    int mf = dinic();
    assert(mf == l);
    // cerr << mf << "\n";

    for(int i = 1; i <= 26; ++i) {
        for(int j = hr[i]; j; j = e[j].nex) {
            if(e[j].w == 0 && e[j].to > 26 && e[j].to <= l + 26) {
                ans[e[j].to - 27] = i;
            }
        }
    } 
    for(int i= 0; i < l; ++i) cout << (char)('a'-1+ans[i]);
    cout << "\n";
    return 0;
}