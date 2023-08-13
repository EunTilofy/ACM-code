#include<bits/stdc++.h>
using namespace std;

#define MN 100005
#define int long long

int n, siz;
int x[MN], y[MN];
int a, b, c, d;
int fa[MN];
int getf(int x) {
    return fa[x] == x ? x : fa[x] = getf(fa[x]);
}
int dis(int u, int v) {
    return abs(x[u]-x[v]) + abs(y[u]-y[v]);
}
void _union(int u, int v) {
    u = getf(u); v = getf(v);
    if(u != v) --siz, fa[u] = v;
}
int add(int u) {
    return x[u] + y[u];
}
int dec(int u) {
    return x[u] - y[u];
}

bool check(int D) {
    siz = n;
    for(int i = 1; i <= n; ++i) fa[i] = i;
    for(int i = 1; i <= n; ++i) {
        if(dis(i, a) >= D) _union(i, a);
        if(dis(i, b) >= D) _union(i, b);
        if(dis(i, c) >= D) _union(i, c);
        if(dis(i, d) >= D) _union(i, d);
    }
    return siz == 1;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a = b = c = d = 1;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        if(add(i) > add(a)) a = i;
        if(add(i) < add(b)) b = i;
        if(dec(i) > dec(c)) c = i;
        if(dec(i) < dec(d)) d = i;
    }
    // cerr << a << " " << b << " " << c << " " << d;
    int l = 1, r = 2e9+1, ans = 0;
    while(l <= r) {
        int mid = (l + r) >>1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}