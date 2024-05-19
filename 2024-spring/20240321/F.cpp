#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int N = (1 << 18) + 10;
int a[N];
int tr[N];

void upd(int x, int k) {
    x++;
    for(; x < N; x += x & (-x)) tr[x] += k;
}
int get(int x) {
    x++;
    int ans = 0;
    for(; x; x -= x & (-x)) ans += tr[x];
    return ans;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, mx = 0;
    cin >> n;
    for(; (1 << mx) < n; ++mx); 
    for(int i = 1; i <= n; ++i) cin >> a[i];
    ll ans = 0;
    vector<ll> f(20);
    for(int i = 1; i <= n; ++i) {
        ans += i - 1 - get(a[i]);
        int bs = 0;
        for(int j = mx - 1; j >= 0; --j) {
            bs |= (1 << j);
            int pos = ((a[i] & bs) ^ (1 << j)), tmp = pos + (1 << j) - 1;
            // cerr << a[i] << " " << pos << " " << tmp << "\n";
            int res = get(pos, tmp);
            // cerr << res << "\n";
            if((a[i] >> j) & 1) f[j] += res;
            else f[j] -= res;
        }
        upd(a[i], 1);
    }
    ll sum = 0;
    for(ll x : f) if(x < 0) sum += x;
    if(sum + 1 < 0) ans += sum + 1;
    cout << ans << "\n";
    return 0;
}
