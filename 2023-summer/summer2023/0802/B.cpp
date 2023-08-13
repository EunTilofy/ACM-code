#include<bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
const int P = 235813;
int n;
int a[MN], fac[P + 5], inv[P + 5], _inv[P + 5], b[MN];

int Mul(int x, int y) {
    return (1ll * x * y % P + P) % P;
}
int Add(int x, int y) {
    return (x + y) % P;
}
int C(int n, int m) {
    return Mul(fac[n], Mul(inv[m], inv[n - m]));
}
int ton[MN * 2];
int tot = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n;++i) {
        cin >> a[i];
        ++ton[a[i] + 100000];
        if(ton[a[i] + 100000] == 2) ++tot;
    }
    for(int i = fac[1] = inv[1] = fac[0] = inv[0] = 1; i < P; ++i) {
        if(i == 1) continue;
        fac[i] = Mul(fac[i - 1], i);
        inv[i] = Mul(inv[P % i], (P - P/i));
    }
    _inv[1] = _inv[0] = 1;
    for(int i = 2; i < P; ++i) _inv[i] = inv[i], inv[i] = Mul(inv[i - 1], inv[i]);
    
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        if((i & 1) != (n & 1)) b[i] = P - C(n - 1, i - 1);
        else b[i] = C(n - 1, i - 1);
        sum = Add(sum, Mul(a[i], b[i]));
    }
    // cerr << "sum = " << sum << endl;

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int _ = Add(sum, P - Mul(a[i], b[i]));
        _ = P - _;
        // cerr << _ << endl;
        // a[i] * r = _ mod P
        // cerr << "b[i] = " << b[i] << endl;
        int r = Mul(_inv[b[i]], _);
        // cerr << "r = " << r << endl;
        // cerr << Add(Add(sum, P - Mul(a[i], b[i])), Mul(r, a[i])) << "~!~~" << endl;
        bool fl = 0;
        // cas1
        if(r >= -100000 && r <= 100000) {
            if(r != a[i]) {
                // int tmp = tot;
                // if(ton[a[i] + 100000] == 2) --tmp;
                // if(ton[r + 100000] == 1) ++tmp;
                // if(ton[r + 100000] == 0) {
                    fl = 1;
                    // cerr << i << " " << r << endl;
                // }
            }
        }
        // cas2
        if(!fl) {
            r -= P;
            if(r >= -100000 && r <= 100000) {
                if(r != a[i]) {
                    // int tmp = tot;
                    // if(ton[a[i] + 100000] == 2) --tmp;
                    // if(ton[r + 100000] == 1) ++tmp;
                    // if(ton[r + 100000] == 0) {
                        fl = 1;
                        // cerr << i << " " << r << endl;
                    // }
                }
            }
        }
        ans += fl;
    }
    cout << ans;
    return 0;
}