#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], pr[N], sf[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        cin >> a[i];
        if(i == 1) a[i] = 1;
        pr[i] = pr[i - 1];
        if(a[i] == 1) pr[i] = i;
    }
    sf[n] = 1e9;
    for(int i = n - 1; i >= 1; --i) {
        if(a[i] == 1) sf[i] = i;
        else sf[i] = sf[i + 1];
    }
    int ans = 0;
    // assert(a[1]);
    for(int i = 1; i < n; ++i) {
        int pos = min(i - pr[i] + 1, sf[i] - i + 1);
        if(sf[i] < n) pos = min(pos, 2);
        // cerr << i << " " << pos << "\n";
        ans = max(ans, pos);
    }
    cout << ans << "\n";
    return 0;
}