#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int n;
struct node {
    int x, y;
} a[N];
int pr[N];

bool check(int val) {
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        int pos = (a[i].x >= val), tmp = (a[i].y >= val);
        pr[i] = pr[i - 1] + (tmp - pos);
        sum += pos;
    }
    int mx = 0, res = -1e9;
    for(int i = n; i >= 1; --i) {
        res = max(res, pr[i]);
        mx = max(mx, res - pr[i - 1]);
    }
    return sum + mx >= (n + 1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y;
    int l = 1, r = 1e9, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << "\n";
    return 0;
}