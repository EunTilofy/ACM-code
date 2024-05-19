#include <bits/stdc++.h>
#define int long long 
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

ll cal(ll l, ll r) {
    if(r < l) return 0;
    return (l + r) * (r - l + 1) / 2;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = "!" + s;
    vector<int> nm1(n + 5), nm0(n + 5);
    vector<int> nx1(n + 5, n + 1), nx0(n + 5, n + 1);
    vector<ll> qz1(n + 5), qz0(n + 5);
    for(int i = n - 1; i >= 0; --i) {
        if(s[i + 1] == '1') nx1[i] = i + 1;
        else nx1[i] = nx1[i + 1];
        if(s[i + 1] == '0') nx0[i] = i + 1;
        else nx0[i] = nx0[i + 1];
    }
    for(int i = 1; i <= n; ++i) {
        qz1[i] = qz1[i - 1] + i * (s[i] == '1');
        qz0[i] = qz0[i - 1] + i * (s[i] == '0');
        nm1[i] = nm1[i - 1] + (s[i] == '1');
        nm0[i] = nm0[i - 1] + (s[i] == '0');
    }
    if(nm0[n] <= m || k <= m) {
        // assert(0);
        for(int i = 1; i <= n; ++i) {
            int l = max(1ll, i - k / 2), r = l + k - 1;
            if(r > n) r = n, l = r - k + 1;
            ll ans = cal(0, i - l) + cal(0, r - i);
            cout << ans << " \n"[i == n];
        }
        return ;
    }
    // if(!m) assert(0);
    int nw = k - m;
    int L1 = nx1[0], R1 = L1;
    int L0 = nx0[0], R0 = L0;
    for(int i = L1; i <= n; ++i) {
        R1 = i;
        if(nm1[i] == nw) break;
    }
    for(int i = L0; i <= n; ++i) {
        R0 = i;
        if(nm0[i] == m) break;
    }
    for(int i = 1; i <= n; ++i) {
        int l = max(1ll, i - k / 2), r = l + k - 1;
        if(r > n) r = n, l = r - k + 1;
        int tot = nm1[r] - nm1[l - 1];
        int L = k - tot;
        ll ans = 1e18;
        if(L <= m) {
            // cerr << i << " " << l << " " << r << "!\n";
            ans = cal(0, i - l) + cal(0, r - i);
        }
        while(nx1[R1] != n + 1 && abs(L1 - i) > abs(nx1[R1] - i)) {
            L1 = nx1[L1];
            R1 = nx1[R1];
        }
        while(nx0[R0] != n + 1 && abs(L0 - i) > abs(nx0[R0] - i)) {
            L0 = nx0[L0];
            R0 = nx0[R0];
        }
        ll pos = 0;
        {
            if(L1 <= i) pos += 1ll * (nm1[min(R1, i)] - nm1[L1 - 1]) * i - (qz1[min(R1, i)] - qz1[L1 - 1]);
            if(m && L0 <= i) pos += 1ll * (nm0[min(R0, i)] - nm0[L0 - 1]) * i - (qz0[min(R0, i)] - qz0[L0 - 1]);
            if(R1 >= i) pos += -1ll * (nm1[R1] - nm1[i - 1]) * i + (qz1[R1] - qz1[i - 1]);
            if(m && R0 >= i) pos += -1ll * (nm0[R0] - nm0[i - 1]) * i + (qz0[R0] - qz0[i - 1]);
            // cerr << "pos = " << pos <<" " <<  L1 << " " << R1 << " " << L0 << " " << R0 << "\n";
        }
        ans = min(ans, pos);
        cout << ans << " \n"[i == n];
        // cerr << ans << " " << pos << "ans\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int o = 1; o <= T; ++o) solve();
    return 0;
}