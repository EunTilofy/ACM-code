#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], p[N], qz[N];

void fail() {
    cout << "No\n";
    exit(0);
}

void solve(int l, int r, int now) {
    if(l > r) return ;
    int flg = 1, last = l;
    for(int i = l; i <= r; ++i) {
        if(a[i] == now) {
            flg = 0;
            solve(last, i - 1, now);
            last = i + 1;
        }
    }
    if(flg) {
        if(a[l] != now + 2 || a[r] != now + 2) fail();
        swap(p[l], p[r + 1]);
        solve(l + 1, r - 1, now + 2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) p[i] = i;
    solve(1, n - 1, 0);
    for(int i = 1; i <= n; ++i) {
        int l = i, r = p[i];
        if(l > r) swap(l, r);
        qz[l]++, qz[r]--;
    }
    for(int i = 1; i < n; ++i) {
        qz[i] += qz[i - 1];
        assert(qz[i] == a[i]);
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; ++i) cout << p[i] << " "; cout << "\n";
    return 0;
}