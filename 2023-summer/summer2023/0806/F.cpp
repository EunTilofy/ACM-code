#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int n, m;

int siz[MN], f[MN];
int getf(int x) {
    return f[x] == x ? x : f[x] = getf(f[x]);
}
int comb(int x, int y) {
    x = getf(x);
    y = getf(y);
    f[x] = y;
    siz[y] += siz[x];
}
const int P = 998244353;

int Add(int x, int y) {
    return (x + y) % P;
}
int Mul(int x, int y) {
    return 1ll * x * y % P;
}
int fpow(int x, int y) {
    int r = 1;
    for(;y;y>>=1,x=Mul(x,x))if(y&1)r=Mul(r,x);
    return r;
}
int Inv(int x) {
    return fpow(x, P-2);
}
int fac[MN], inv[MN];
int C(int x, int y) {
    if(y < 0 || y > x) return 0;
    return Mul(inv[x-y], Mul(inv[x], inv[y]));
}

void link(int u, int v) {
    comb(u, v);
    
}

void solve(int x) {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    cin >> n >> m;
    for(int i = 2; i <= n; ++i) {
        fac[i] = Mul(fac[i-1], i);
        inv[i] = Mul(inv[P%i], (P-P/i));
    }
    for(int i = 2; i <= n; ++i) inv[i] = Mul(inv[i-1], inv[i]);
    int lastans = 0;
    while(m--) {
        int opt;
        cin >> opt;
        if(opt == 1) {
            int u, v;
            cin >> u >> v;
            u ^= lastans;
            v ^= lastans;
            link(u, v);
        } else {
            int x, m, k;
            cin >> x >> m >> k;
            x ^= lastans;
            m ^= lastans;
            k ^= lastans;
            int mxdp = solve(x);
            int size = siz[getf(x)];
            int r = 1;
            if(mxdp >= m) r = max(r, m + 1);
            else {
                int xx = m - mxdp;
                r = max(r, min(size, xx/2 + m + 1));
            }

            cout << (lastans = Add(1, P - Mul(C(n-r, k), Inv(C(n, k))))) << "\n";
        }
    }
}