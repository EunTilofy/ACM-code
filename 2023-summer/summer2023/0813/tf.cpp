#include<bits/stdc++.h>
using namespace std;

const int Mod = 998244353;

// const int _ = 100;
// int t[999244353/_];

int fpow(int x, int y) {
    int r = 1;
    for(; y; y>>=1, x=1ll*x*x%Mod) if(y&1) r = 1ll*r*x%Mod;
    return r;
}
// int Inv(int x) {
//     return fpow(x, Mod - 2);
// }
const int N = 101;
int g[101], r[101], e[101], t[101];
int R[N], E[N], T[N], G2[N], E2[N];
void solve(int n) {
    cout << g[n] << "\n";
//     // (2n)! / n! / (n+1)!
//     if(n * 2 >= 998244353) cout << "0\n";
//     else {
//         int o = n/_;
//         int facn = t[o];
//         for(int i = o * _ + 1; i <= n; ++i) facn = 1ll * facn * i % Mod;
//         int facn_ = 1ll * facn * (n + 1) % Mod;

//         facn = Inv(facn); facn_ = Inv(facn_);

//         int ans = 1ll * facn * facn_ % Mod;
        
//         int O = (2*n)/_;
//         int Facn = t[O];
//         for(int i = O * _ + 1; i <= n*2; ++i) Facn = 1ll * Facn * i % Mod;
//         ans = 1ll * ans * Facn % Mod;
//         cout << ans << "\n";
//     }
}

int main() {
    // freopen("figure.in", "r", stdin);
    // freopen("figure.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    g[0] = 1, G2[0] = 1;
    for(int i = 1; i <= 100; ++i) {
        g[i] = 1 + R[i - 1] + E[i - 1];
        r[i] = G2[i - 1] + 2 * E2[i - 1];
        e[i] = T[i - 1];
        t[i] = R[i - 1] + 2 * E[i - 1];
        G2[i] = G2[i - 1] * 2 + g[i];
        R[i] = R[i - 1] + r[i];
        E[i] = E[i - 1] + e[i];
        T[i] = T[i - 1] + t[i];
        E2[i] = E2[i - 1] * 2 + e[i];
        // g[i] = 1;
        // for(int j = 0; j <= i - 1; ++j) {
        //     g[i] = (g[i] + r[i-j-1] + e[i-j-1]) % Mod;
        // }
        // for(int j = 0; j <= i - 1; ++j) {
        //     r[i] += (1ll * fpow(2, j) * g[i-1-j] % Mod + 1ll * fpow(2, j+1) * e[i-1-j] % Mod) % Mod;
        //     e[i] += t[i-j-1];
        //     t[i] += (r[i-1-j] + 2 * e[i-1-j]) % Mod;
        //     r[i] %= Mod;
        //     e[i] %= Mod;
        //     t[i] %= Mod;
        // }
    }

    // int now = 0, nex = _, nn = 1;
    // t[0] = 1;
    // for(int i = 1; i <= 10000000; ++i) {
    //     nn = 1ll * nn * i % Mod;
    //     if(i == nex) {
    //         t[++now] = nn;
    //     }
    // }

    while(1) {
        int n;
        cin >> n;
        if(n) solve(n);
        else break;
    }
}