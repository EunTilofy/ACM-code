#include <iostream>
int G[2005][2005], GG[2005][2005], cnt_G[2005], cnt_GG[2005];
int dep[2005], fa[2005][20];
int top, st[2005];

void dfs(int x, int f, int d) {
    fa[x][0] = f;
    for(int i = 1; i < 20; ++i) fa[x][i] = fa[fa[x][i-1]][i-1];
    dep[x] = d;
    for(int _ = 0; _ < cnt_G[x]; _ = _ + 1) {
        int y = G[x][_];
        if(y != f) dfs(y, x, d + 1);
    }
}
int lca(int x, int y) {
    if(dep[x] < dep[y]) {
        x ^= (y ^= (x ^= y));
    }
    for(int i = 19; ~i; i = i - 1) if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    if(x == y) return x;
    for(int i = 19; ~i; i = i - 1) if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
int Fa[2005], Dep[2005], Cov[2005];
int id[2005][2005], cnt_id[2005];
int nodes[2005], cnt_nodes;

void Dfs(int x, int f) {
    nodes[cnt_nodes] = x; cnt_nodes = cnt_nodes + 1;
    Fa[x] = f; Dep[x] = Dep[f] + 1;
    for(int _ = 0;  cnt_GG[x] > _; _ = _ + 1) {
        int y = GG[x][_];
        if(y != f) {
            Dfs(y, x);
        }
    }
}
void Cover(int x, int y, int i) {
    while(Dep[x] != Dep[y]) {
        if(Dep[x] > Dep[y]) {
            Cov[x] = Cov[x] + 1;
            id[x][cnt_id[x]] = i; cnt_id[x] = cnt_id[x] + 1;
            x = Fa[x];
        }
        else {
            Cov[y] = Cov[y] + 1;
            id[y][cnt_id[y]] = i; cnt_id[y] = cnt_id[y] + 1;
            y = Fa[y];
        }
    }
    while(x != y) {
        Cov[x] ++; Cov[y] ++;
        id[x][cnt_id[x]] = i; cnt_id[x] = cnt_id[x] + 1;
        id[y][cnt_id[y]] = i; cnt_id[y] = cnt_id[y] + 1;
        x = Fa[x]; y = Fa[y];
    }
}

int max(int x, int y) {
    if(x > y) return x;
    return y;
}

int findmx(int x, int y) {
    int mx = 0;
    while(Dep[x] != Dep[y]) {
        if(Dep[x] > Dep[y]) { mx = max(Cov[x], mx), x = Fa[x]; }
        else { mx = max(Cov[y], mx), y = Fa[y]; }
    }
    while(x != y) {
        mx = max(Cov[x], mx);
        mx = max(Cov[y], mx),
        x = Fa[x]; y = Fa[y];
    }
    return mx;
}
int cnt[(1<<21)];

void solve(){
	int n; std::cin >> n;
    cnt_nodes = 0;
    for(int i = 1; i <= n; ++i) {
        cnt_G[i] = cnt_GG[i] = 0;
        dep[i] = 0;
        Fa[i] = 0;
        Dep[i] = 0;
        Cov[i] = 0;
        cnt_id[i] = 0;
        st[i] = 0;
        for(int j = 0; j < 20; ++j) fa[i][j] = 0;
    }
    for(int i = 1; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0, 1);
    set<int> val;
    int m;
    cin >> m;
    vector<pair<int,int>> I(m);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        I[i] = {x, y};
        val.insert(x); val.insert(y);
    }
    {
        GG[st[top=1]=(*val.begin())].clear();
        for(auto x : val) if(x != st[top]) { // leafs
            GG[x].clear();
            int y=lca(st[top], x);
            if(y == st[top]) {
                st[++top] = x;
                continue;
            }
            while(dep[st[top-1]]>dep[y]) {
                GG[st[top-1]].push_back(st[top]);
                top--;
            }
            if(y==st[top-1]) {
                GG[y].push_back(st[top]);
                top--;
            } else {
                GG[y].clear(); GG[y].push_back(st[top]);
                st[top]=y;
            }
            st[++top]=x;
        }
        while(top>1) GG[st[top-1]].push_back(st[top]),--top;
    }
    nodes.clear();
    Dfs(1, 0);
    for(int i = 0; i < m; ++i) Cover(I[i].first, I[i].second, i);
    vector<int> mx(m);
    int _ = 0;
    for(int i = 0; i < m; ++i) {
        mx[i] = findmx(I[i].first, I[i].second);
        if(mx[i] == 1) ++_;
    }
    vector<int> nm;
    for(auto x : nodes) if(Cov[x] > 1) {
        bool fl = 0;
        for(auto i : id[x]) {
            if(mx[i] > 1) if(Cov[x] == mx[i]) fl = 1;
        }
        if(fl) nm.push_back(x);
    }
    int all = nm.size(), S = (1ll<<all);
    int ans = all;
    for(int i = 0; i < S; ++i) {
        if(cnt[i] > ans) continue;
        set<int> has;
        for(int j = 0; j < all; ++j) if((i >> j)&1) for(auto y : id[j]) if(mx[y] > 1) has.insert(y);
        if(has.size() == m - _) ans = min(ans, cnt[i]);
    }
    std::cout << ans + _ << "\n";
}

int main(){
  for(int i = 1; i < (1<<21); ++i) {
      cnt[i] = cnt[i - (i&-i)] + 1;
  }
	int T = 1; std::cin >> T;
	while(T--) solve();
}