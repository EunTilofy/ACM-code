#include<bits/stdc++.h>
using namespace std;
const int MN = 3e5+5;
int n, m;
string s[MN];
struct node {
    int dfn;
    int id;
    int time;
    int v;
}a[MN*5]; int tot;

int now_dfn[MN];

struct trie {
    int c[MN][26], l[MN], r[MN];
    int nn = 0;
    vector<int> lab[MN];
    void add(string s, int id) {
        int len = s.size(); 
        int q = 0;
        for(int i = 0; i < len; ++i) {
            if(c[q][s[i]-'a'] == 0) c[q][s[i]-'a'] = ++nn;
            q = c[q][s[i]-'a']; 
        }
        lab[q].push_back(id);
    }
    int dind, dfn[MN];
    void dfs(int x) {
        dfn[x] = ++dind;
        l[x] = dind;
        for(auto id : lab[x]) {
            a[id].dfn = dfn[x];
            now_dfn[id] = dfn[x];
        }
        for(int i = 0; i < 26; ++i) if(c[x][i]) {
            dfs(c[x][i]);
        }
        r[x] = dind;
    }
    void init() {
        dind = 0; dfs(0);
    }
    pair<int,int> que(string s) {
        int q = 0;
        for(int i = 0; i < s.size(); ++i) {
            q = c[q][s[i]-'a'];
            if(!q) return {1,0};
        }
        return {l[q], r[q]};
    }
} T;

int Ans[MN], nq;

int t[MN];
void C(int x, int v) {for(;x<=n;x+=(x&-x)) t[x]+=v;}
int G(int x) {int r = 0; for(;x;x-=(x&-x)) r+=t[x]; return r;}

void cdq(int l, int r) {
    if(l == r) {
        return ;
    }
    int mid = (l + r) >> 1;
    cdq(l, mid); cdq(mid+1, r);
    vector<pair<node, bool>> tmp;
    for(int i = l; i <= r; ++i) tmp.push_back({a[i], i>mid});
    sort(tmp.begin(), tmp.end(), [&](auto x, auto y)->bool{
        return (x.first.dfn == y.first.dfn) ? (x.second < y.second): (x.first.dfn < y.first.dfn);
    });
    for(auto &[x, y] : tmp) {
        if(y && abs(x.v) > 100) {
            if(x.v<0) {
                Ans[-x.v-100]-=G(x.id);
            }
            else {
                Ans[x.v-100]+=G(x.id);
            }
        } else if(!y && abs(x.v) == 1) {
            C(x.id, x.v);
        }
    }
    for(auto &[x, y] : tmp) {
        if(!y && abs(x.v) == 1) {
            C(x.id, -x.v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> s[i]; T.add(s[i], i);
        a[i].id = i;
        a[i].time = 1;
        a[i].v = 1;
    }
    T.init();
    int cur = 1; tot = n;
    // for(int i = 1; i <= n; ++i) cerr << now_dfn[i] << " ";cerr << "\n";
    for(int i = 1; i <= m; ++i) {
        int opt; cin >> opt;
        ++cur;
        if(opt == 1) {
            int x, y;
            cin >> x >> y;
            a[++tot] = (node) {now_dfn[x], x, cur, -1};
            a[++tot] = (node) {now_dfn[y], y, cur, -1};
            swap(now_dfn[x], now_dfn[y]);
            a[++tot] = (node) {now_dfn[x], x, cur, 1};
            a[++tot] = (node) {now_dfn[y], y, cur, 1};
        } else {
            string t;
            int k, l, r;
            cin >> t;
            cin >> k >> l >> r;
            t = t.substr(0, k);
            auto [L, R] = T.que(t);
            ++nq;
            if(L > R) Ans[nq] = 0;
            else {
                a[++tot] = (node){R, r, cur, nq + 100};
                if(l>1) a[++tot] = (node){R, l-1, cur, -(nq+100)};
                if(L>1) a[++tot] = (node){L-1, r, cur, -(nq+100)};
                if(L>1&&l>1) a[++tot] = (node){L-1, l-1, cur, nq+100};
            }
        }
    }

    // for(int i = 1; i <= tot; ++i) {
        // cerr << a[i].dfn << " " << a[i].id << " " << a[i].time << " " << a[i].v << "\n";
    // }

    cdq(1, tot);
    for(int i = 1; i <= nq; ++i) cout << Ans[i] << "\n";
    return 0;
}

/*
3 4
aaa
bbb
aac
2 aasdd 2 1 3
2 aab 1 1 2
1 2 3
2 aat 2 1 2

4 6
aaa
aas
abb
aba
2 aa 2 1 2
1 1 3
2 aa 2 1 2
2 a 1 1 4
2 aa 2 3 4
2 aa 2 1 3

*/