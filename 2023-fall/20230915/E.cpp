#include<bits/stdc++.h>
using namespace std;

const int MN = 1e5+6;
const long long inf = 1e10;

int n, a[MN];
int t[MN<<2];
vector<int> G[MN], GG[MN];
int st[MN], top;
vector<int> layer[MN];
void build(int k, int l, int r) {
    if(l == r) t[k] = a[l];
    else {
        int mid = (l+r)>>1;
        build(k<<1,l,mid);build(k<<1|1,mid+1,r);
        t[k]=min(t[k<<1],t[k<<1|1]);
    }
}
int que(int k, int l, int r, int a, int b) {
    if(l == a && r == b) return t[k];
    else {
        int mid = (l + r) >>1;
        if(b <= mid) return que(k<<1,l,mid,a,b);
        if(a > mid) return que(k<<1|1,mid+1,r,a,b);
        return min(que(k<<1,l,mid,a,mid),que(k<<1|1,mid+1,r,mid+1,b));
    }
}
int fa[MN][20], dep[MN];
void dfs(int x, int f, int d) {
    fa[x][0] = f;
    for(int i = 1; i < 20; ++i) fa[x][i] = fa[fa[x][i-1]][i-1];
    dep[x] = d;
    layer[d].push_back(x);
    for(auto y : G[x]) if(y != f) dfs(y, x, d + 1);
}
int lca(int x, int y) {
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = 19; ~i; --i) if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    if(x == y) return x;
    for(int i = 19; ~i; --i) if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}
long long cal(int x, int d, int D) {
    long long r=0;
    if(GG[x].size() == 0) return (long long)que(1,0,n-1,D-dep[x],D-d-1);
    for(auto y : GG[x]) r+=cal(y,dep[x],D);
    r=min(r,(long long)que(1,0,n-1,D-dep[x],D-d-1));
    return r;
}
long long sol(int D) {
    GG[st[top=1]=1].clear();
    for(auto x : layer[D]) {
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
    return cal(1, 0, D);
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    build(1, 0, n - 1);
    for(int i = 0; i <= n; ++i) G[i].clear(),layer[i].clear();
    for(int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        G[x].push_back(y); G[y].push_back(x);
    }
    dfs(1, 0, 1);
    long long ans = a[0];
    for(int i = 2; i <= n; ++i) if(layer[i].size()) ans += sol(i);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}