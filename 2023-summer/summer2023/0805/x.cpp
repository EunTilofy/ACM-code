#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
vector<int> g[N];
int n, m, k;
ll f[N];
int a[N], c[N];

bool check(int x) {
    ll ans = 0;
    for(int i = 1; i <= n / 2 + 1; ++i) if(a[i] > x) {
        ll pos = a[i] + 1;
        if(x) pos = (a[i] + x - 1) / x;
        // cerr << i << " " << a[i] << " " << pos << " " << f[pos] << "\n";
        ans += f[pos];
    }
    return ans <= k;
}

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 1; i <= m; ++i) {
        cin >> c[i];
    }
    for(int i = 1; i <= m; ++i) f[i] = k + 1;
    f[1] = 0;
    for(int i = 2; i <= m; ++i) for(int x : g[i]){
        f[i] = min(f[i], f[i / x] + c[x]);
    }
    // for(int i = 1; i <= m; ++i) {
    //     cerr << i  << " "<< f[i] << "\n";
    // }
    for(int i = m - 1; i >= 1; --i) f[i] = min(f[i], f[i + 1]);
    for(int i = 1; i < m; ++i) {
        int pos = (m + i - 1) / i;
        f[m] = min(f[m], f[i] + f[pos]);
    }
    for(int i = m - 1; i >= 1; --i) f[i] = min(f[i], f[i + 1]);
    sort(a + 1, a + 1 + n);
    int l = 0, r = 1e9, ans = -1;
    // cerr << check(0) << "\n";
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    // assert(ans != -1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < N; ++i) for(int j = i; j < N; j += i) {
        g[j].push_back(i);
    }
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}