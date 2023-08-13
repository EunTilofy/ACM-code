#include<bits/stdc++.h>
#define ll long long
// #define lll __int128
#define lll long long
using namespace std;
const int mod = 1e9 + 7;

lll get(lll x) {
    lll pos = 1, sum = 0;
    for(int i = 1; pos <= x; pos *= 2, ++i) {
        lll tmp = x / pos;
        sum += (tmp + 1) / 2 * i;
    }
    return sum;
}

ll add(ll x, ll y) {
    return (x + y) % mod;
}
ll mul(ll x, ll y) {
    x %= mod, y %= mod;
    return x * y % mod;
}
ll cal(ll x) {
    ll pos = 1, sum = 0;
    for(int i = 1; pos <= x; pos *= 2, ++i) {
        ll tmp = x / pos;
        tmp = (tmp + 1) / 2;
        ll l = pos, r = (tmp * 2 - 1) * pos;
        sum = add(sum, mul(i, mul((l + r) / 2, tmp)));
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // ll ans = 0;
    // for(int i = 1; i <= 10000000; ++i) {
    //     ans = max(ans, abs(i * 2 - get(i)));
    // }
    // cout << ans << "\n";
    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        n--;
        ll l = max(1ll, n / 2 - 200), r = n / 2 + 200, ans = -1, tot = 0;
        // cerr << "???\n";
        while(l <= r) {
            ll mid = (l + r) >> 1;
            lll pos = get(mid);
            if(pos <= n) ans = mid, tot = pos, l = mid + 1;
            else r = mid - 1;
        }
        // cerr << ans << " " << tot << "\n";
        ll sum = add(cal(ans), mul((n - tot), ans + 1));
        cout << add(sum, 1) << "\n";
    }
}
