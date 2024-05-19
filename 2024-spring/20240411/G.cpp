#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, m, k, a[N], qz[N];
int f[N][6];
int r[N], nx[N], v[N];

void Min(int &x, int y) {
    x = min(x, y);
}

bool check(int x) {
    for(int i = 1; i <= n; ++i) {
        int R = i + x - 1;
        if(R <= n) nx[i] = r[R], v[i] = qz[R] - qz[i - 1];
        else nx[i] = v[i] = -1;
        // cerr << i << " " << nx[i] << " " << v[i] << "\n";
    }
    for(int i = 0; i <= n + 1; ++i) for(int j = 1; j <= k; ++j) f[i][j] = 1e9;
    f[0][0] = 0;
    for(int i = 1; i <= n; ++i) for(int j = 0; j <= k; ++j) {
        if(a[i]) Min(f[r[i] + 1][j], f[i - 1][j]);
        else Min(f[i][j], f[i - 1][j]);
        if(nx[i] != -1 && j != k) {
            Min(f[nx[i] + 1][j + 1], f[i - 1][j] + v[i]);
        }
    }
    // for(int i = 1; i <= n + 1; ++i) for(int j = 0; j <= k; ++j) {
    //     cerr << i << " " << j << " " << f[i][j] << "\n";
    // }
    int ans = 1e9;
    for(int i = 1; i <= n + 1; ++i) ans = min(ans, f[i][k]);
    // cerr << "ans = " << ans << "\n";
    return ans <= m;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    string s; cin >> s;
    for(int i = 1; i <= n; ++i) a[i] = (s[i - 1] - '0');
    for(int i = 1; i <= n; ++i) {
        qz[i] = qz[i - 1] + (!a[i]);
    }
    for(int i = n; i >= 1; --i) {
        if(a[i + 1]) r[i] = r[i + 1];
        else r[i] = i;
    }
    // for(int i = 1; i <= n; ++i) {
    //     cerr << i << " " << r[i] << "\n";
    // }
    int l = 1, r = n / k, ans = -1;
    // check(3);
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}