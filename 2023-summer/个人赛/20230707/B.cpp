#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
// map<pair<int, int>, int> mp;
int mp[15][32778];
bool vis[15][32778];
#define MN 29000000
int fac[MN], inv[MN];
int mul(int x, int y) {
    return (1ll * x * y) % mod;
}
int add(int x, int y) {
    return (x + y) % mod;
}
int C(int n, int m) {
    return mul(fac[n], mul(inv[n - m], inv[m]));
}
int fpow(int x, int y) {
    int r = 1;
    for(;y;y>>=1, x = mul(x, x))if(y & 1) r = mul(r, x);
    return r;
}


int dfs(int V, int I, int U, int it = 0) {
    // cerr << V << " "  << I << " " << U << endl;
    if(I == 0) return 0;
    if(2 * V >= I + U) return 1;
    // pair<int, int> que = {it, I};
    // if(mp.count(que)) {
        // return mp[que];
    // }
    if(vis[it][I]) return mp[it][I];
    int ans = 0;
    int num = min(I, U);
    I += num;
    U -= num;
    int all = C(U + I, 2 * V); all = fpow(all, mod - 2);
    for(int i = max(0, 2 * V - U); i <= min(2 * V, I); ++i) {
        ans = add(ans, mul(dfs(V * 3, I - i, U - (V * 2 - i), it + 1), mul(mul(C(I, i), C(U, V * 2 - i)), all)));
    }
    vis[it][I - num] = 1;
    // assert(I<=32768);
    return mp[it][I - num] = ans + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[1] = fac[0] = inv[1] = inv[0] = 1;
    for(int i = 1; i < MN; ++i) fac[i] = mul(fac[i - 1], i);    
    for(int i = 2; i < MN; ++i) inv[i] = mul(inv[mod % i], (mod - mod/i));
    for(int i = 2; i < MN; ++i) inv[i] = mul(inv[i - 1], inv[i]);

    int n;
    cin >> n;
    cout << dfs(1, 1, n - 2);
}