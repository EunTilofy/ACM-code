#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MN = 5005;
int n, p[MN];
int pos, val;
vector<int> G[MN];

bool in[MN];
int siz[MN], g[MN];

int fac[MN<<1], inv[MN<<1];
const int mod = 1e9+7;
int Add(int x, int y) {return (x+y)%mod;}
int Mul(int x, int y) {return 1ll*x*y%mod;}
int C(int x, int y) {
    if(x<0||y<0||y>x) return 0;
    return Mul(fac[x], Mul(inv[y], inv[x-y]));
}
void init() {
    inv[0] = fac[0] = inv[1] = fac[1] = 1;
    for(int i = 2; i < MN*2; ++i) fac[i] = Mul(fac[i-1], i);
    for(int i = 2; i < MN*2; ++i) inv[i] = Mul(inv[mod%i], (mod-mod/i));
    for(int i = 2; i < MN*2; ++i) inv[i] = Mul(inv[i-1], inv[i]);
}

void dfs(int x, int f) {
    g[x] = 1; siz[x] = in[x] = 0;
    for(auto y : G[x]) {
        dfs(y, x);
        if(in[y]) in[x]=1;
        else {
            g[x]=Mul(g[x], Mul(g[y], C(siz[x]+siz[y], siz[x])));
            siz[x] += siz[y];
        }
    }
    if(x == val) in[x] = 1;
    ++siz[x];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> n;
    for(int i = 2; i <= n; ++i) cin >> p[i], G[p[i]].push_back(i);
    cin >> val >> pos;

    dfs(1, 0);
    vector<int> a;
    for(int i = val; i; i = p[i]) a.push_back(i);
    reverse(a.begin(), a.end());
    vector<int> f(n+1), ff(n+1);
    f[1] = g[1];
    for(int j = 1; j <= n; ++j) ff[j] = Add(ff[j-1], f[j]);
    int Siz = siz[1];
    for(int i = 1; i < a.size(); ++i) {
        int x = a[i]; Siz += siz[x];
        for(int j = 1; j <= n; ++j) {
            f[j]=Mul(ff[j-1], Mul(g[x], C(Siz-j, siz[x]-1)));
        }
        for(int j = 1; j <= n; ++j) ff[j] = Add(ff[j-1], f[j]);
    }

    cout << f[pos] << "\n";
    return 0;
}