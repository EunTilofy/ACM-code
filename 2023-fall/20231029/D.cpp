#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod1 = 998244353, mod2 = 1e9 + 7, p = 37;
int hs1[N], hs2[N], pw1[N], pw2[N];

int get1(int l, int r) {
    return 1ll * ((hs1[r] - hs1[l - 1]) %mod1 + mod1) % mod1 * pw1[l - 1] % mod1;
}

int get2(int l, int r) {
    return 1ll * ((hs2[r] - hs2[l - 1]) %mod2 + mod2) % mod2 * pw2[l - 1] % mod2;
}

bool check(int l1, int r1, int l2, int r2) {
    return get1(l1, r1) == get1(l2, r2) && get2(l1, r1) == get2(l2, r2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i <= n; ++i) {
        pw1[i] = 1ll * pw1[i - 1] * p % mod1;
        pw2[i] = 1ll * pw2[i - 1] * p % mod2;
    }
    for(int i = 1; i <= n; ++i) {
        hs1[i] = (hs1[i - 1] + 1ll * (s[i - 1] - 'a') * pw1[n - i] % mod1) % mod1;
        hs2[i] = (hs2[i - 1] + 1ll * (s[i - 1] - 'a') * pw2[n - i] % mod2) % mod2;
    }
    vector<int> qz(n + 5);
    for(int i = 1; i <= n; ++i) {
        int flg = 1;
        for(int j = i + 1; j <= n; j += i) {
            int len = min(i, n - j + 1);
            if(!check(1, len, j, j + len - 1)) {flg = 0; break;}
        }
        // cout << i << " " << flg << "\n";
        qz[i] = qz[i - 1] + flg;
    }
    int q; cin >> q;
    for(int o = 1, x; o <= q; ++o) {
        cin >> x;
        int l = max(x, n - x + 1);
        // cout << l << "l\n";
        if(l >= n) cout << "0\n";
        else cout << qz[n - 1] - qz[l - 1] << "\n";
    }
    return 0;
}