#include <bits/stdc++.h>
using namespace std;

void Min(int &x, int y) {
    x = min(x, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    int sum = 0, tot = 0;
    for(int &x : a) {
        cin >> x;
        tot += x;
    }
    for(int &x : b) {
        cin >> x;
        sum += x;
    }
    vector<int> f(sum + 1, 1e9), q(sum + 1, 1e9);
    f[b[0]] = 0;
    for(int i = 1; i < n; ++i) {
        // cerr << i << "\n";
        vector<int> g(sum + 1, 1e9);
        for(int j = 0; j <= sum; ++j) {
            if(f[j] != 1e9) {
                // cerr << j << "jj\n";
                int pos = f[j] + b[i] - a[i - 1];
                // cerr << j << " , pos = " << pos << "\n";
                if(pos > 0) Min(g[j + pos], 0);
                else Min(g[j], pos);
            } 
            if(q[j] != 1e9 && i > 1) {
                // cerr << i << "qq\n";
                int pos = q[j] + b[i] - a[i - 1] - a[i - 2];
                if(pos > 0) Min(g[j + pos], 0);
                else Min(g[j], pos);
            }
        }
        // for(int j = 0; j <= sum; ++j) if(g[j] != 1e9) {
        //     cerr << j << " " << g[j] << "\n";
        // }
        q = f, f = g;
    }
    int ans = 1e9;
    for(int i = 0; i <=sum; ++i) {
        ans = min(ans, i + max(0, f[i]));
    }
    cout << ans + tot << "\n";
    return 0;
}
