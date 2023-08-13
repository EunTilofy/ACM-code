#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;

struct tree {
    int tr[N];
    void upd(int x, int k) {
        for(; x < N; x += (x & (-x))) tr[x] += k;
    }
    int get(int x) {
        int ans = 0;
        for(; x; x -= (x & (-x))) ans += tr[x];
        return ans;
    }
} T[2];
struct query {
    int sz;
    vector<int> a;
} b[N];

ll solve(vector<int> a) {
    ll ans = 0, now = 0;
    for(int x : a) {
        ans += now - T[0].get(x), ++now;
        T[0].upd(x, 1);
    }
    for(int x : a) T[0].upd(x, -1);
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int o : {0, 1}) memset(T[o].tr, 0, sizeof T[o].tr);
    int n, q;
    cin >> n >> q;
    vector<int> tot;
    vector<int> c(n);
    for(int &x : c) {
        cin >> x;
        tot.push_back(x);
    }
    for(int o = 1; o <= q; ++o) {
        cin >> b[o].sz;
        b[o].a.resize(b[o].sz);
        for(int &x : b[o].a) {
            cin >> x;
            tot.push_back(x);
        }
    }
    sort(all(tot));
    tot.erase(unique(all(tot)), tot.end());
    // for(int x : tot) cerr << x << "tot\n";
    for(int &x : c) x = lower_bound(all(tot), x) - tot.begin() + 1;
    // for(int x : c) cerr << x << "\n";
    ll pre = solve(c);
    // cerr << pre << "pre\n";
    for(int x : c) T[1].upd(x, 1);
    for(int o = 1; o <= q; ++o) {
        auto [sz, a] = b[o];
        for(int &x : a) x = lower_bound(all(tot), x) - tot.begin() + 1;
        ll ans = 1e18, pos = solve(a);
        // cerr << pos << "pos\n";
        vector<ll> pr(sz), sf(sz);
        for(int i = 0; i < sz; ++i) {
            int res = n - T[1].get(a[i]), cnt = T[1].get(a[i] - 1);
            pr[i] = res, sf[i] = cnt;
        }
        for(int i = 1; i < sz; ++i) sf[i] += sf[i - 1];
        for(int i = sz - 2; i >= 0; --i) pr[i] += pr[i + 1];
        // for(int i = 0; i < sz; ++i) {
        //     cerr << i << " " << pr[i] << " " << sf[i] << "\n";
        // }
        ans = min(ans, pos + pr[0]);
        ans = min(ans, pos + sf[sz - 1]);
        for(int i = 1; i < sz; ++i) {
            ans = min(ans, pos + pr[i] + sf[i - 1]);
        }
        cout << ans + pre << "\n";
    }
    return 0;
}