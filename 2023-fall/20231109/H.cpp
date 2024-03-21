#include <bits/stdc++.h>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
struct node {
    int d, k, c;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, sum = 0;
    ll r;
    cin >> n >> m >> r;
    vector<node> a(n);
    for(auto &[d, k, c] : a) cin >> d >> k >> c;
    vector<pair<int, int>> q(m);
    vector<int> qz(m + 5);
    for(auto &[x, y] : q) {
        cin >> x >> y;
    }  
    sort(all(q));
    vector<int> ys; ys.push_back(0);
    for(int o = 0; o < m; ++o) {
        auto[x, y] = q[o];
        qz[o + 1] = qz[o] + y;
        for(int i = 1; i <= y; ++i) {
            ++sum;
            ys.push_back(x);
        }
    }
    vector<ll> f(sum + 5, 1e18);
    f[0] = 0;
    for(int i = 0; i < sum; ++i) {
        f[i + 1] = min(f[i + 1], f[i] + r);
        int nw = ys[i + 1];
        for(auto [d, k, c] : a) {
            int pos = nw + d - 1, r = min(i + k, sum);
            if(ys[r] > pos) {
                int x = lower_bound(all(q), make_pair(pos, 0)) - q.begin();
                while(q[x].first > pos) --x;
                r = qz[x + 1];
            }
            f[r] = min(f[r], f[i] + c);
        }
    }
    cout << f[sum] << "\n";
    return 0;
}