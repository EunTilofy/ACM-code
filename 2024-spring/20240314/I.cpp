#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<__int128> mp[65];

int find(__int128 A, __int128 B, __int128 C) {
    __int128 delta = B * B - 4 * A * C;
    if(delta < 0) return 0;
    __int128 tmp = max((__int128)0, (__int128)sqrt(1.0*delta) - 10);
    for(; tmp * tmp < delta; ++tmp);
    if(tmp * tmp != delta) return 0;
    __int128 pos = -B + tmp;
    int ans = 0;
    if(pos > 0 && pos % (2 * A) == 0) ans++;
    return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    int ans = 0;
    if(k == 3) {
        for(int i = 1; i <= 1000000; ++i) if(n % i == 0) {
            __int128 A = 3, B = 3 * i, C = 1ll * i * i - n / i;
            ans += find(A, B, C);
        }
    } else {
        int l = 0;
        for(int i = 0; i < mp[k].size(); ++i) if(n < mp[k][i]) {
            for(; mp[k][l] < mp[k][i] - n; ++l);
            if(mp[k][l] == mp[k][i] - n) ++ans;
        }
    }
    cout << ans << "\n";
}

void print(__int128 x) {
    if(!x) return ;
    print(x / 10);
    cerr << (int)(x % 10);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    __int128 lmt = 1e18;
    for(int i = 4; i <= 64; ++i) {
        for(int j = 1; ; ++j) { 
            __int128 ans = 1;
            int flg = 1;
            // cerr << j << "\n";
            for(int k = 1; k <= i; ++k) {
                ans *= j;
                if(k < i && ans > lmt) {
                    flg = 0;
                    break;
                }
            } 
            if(!flg) break;
            mp[i].push_back(ans);
            
        }
    }
    int T; cin >> T;
    for(int o = 1; o <= T; ++o)
        solve();
    return 0;
}