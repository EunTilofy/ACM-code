#include<bits/stdc++.h>
using namespace std;

const int MN = 5e5+5;
int a[MN];
int las[MN], l[MN];
vector<pair<pair<int,int>, int>> q;
vector<int> t;
int n, m;
bool in[MN];
void C(int x, int v) {
    for(;x<=n;x+=(x&(-x))) t[x]+=v;
}
int G(int x) {
    int r=0;
    for(;x;x-=(x&(-x))) r+=t[x];
    return r;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i], in[a[i]]=1;
    q.clear(); int mex = 1;
    for(int i = 1; in[i]; ++i) ++mex;
    for(int i = 1; i <= n; ++i) in[a[i]] = 0;
    q.push_back({{-1, n}, mex});
    for(int i = 1; i <= n; ++i) las[a[i]] = 0;
    for(int i = 1; i <= n; ++i) {
        l[i] = las[a[i]];
        las[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i) if(l[i]+1!=i) q.push_back({{-l[i]-1, i-1}, a[i]});
    for(int i = 1; i < n; ++i) if(i==las[a[i]]) q.push_back({{-i-1, n}, a[i]});
    sort(q.begin(), q.end());
    int ans = -1;
    t.resize(n+1);
    for(int i = 0; i <= n; ++i) t[i]=0;
    for(int i = 1; i <= n; ++i) las[a[i]] = n+1;
    int now=n+1;
    for(auto [o, v] : q) {
        while(now>-o.first) {
           --now;
           if(las[a[now]]!=n+1) C(las[a[now]], -1);
           C(now, 1); 
           las[a[now]] = now;
        }
        // cerr << v << " " << G(o.second) << "\n";
        ans = max(ans, -v+G(o.second));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}