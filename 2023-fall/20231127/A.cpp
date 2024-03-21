#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), b, c;
    long long sum1 = 0, sum2 = 0;
    int id = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] < a[id]) id = i;
    }
    for(int i = id + 1; i < n; ++i) sum2 += a[i], b.push_back(sum2);
    for(int i = id - 1; ~i; --i) sum1 += a[i], b.push_back(sum1);
    double ans = (double)(sum1 + sum2 + a[id])/n;
    int l = id, r = n - id - 1;
    ans = max(ans, (double)(sum1 + a[id] + a[id + 1]) / (l + 1 + 1));
    ans = max(ans, (double)(sum2 + a[id] + a[id - 1]) / (r + 1 + 1));
    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}