#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), qz(n + 10);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        qz[i] = qz[i - 1] + a[i];
        qz[i] %= 10;
    }
    vector<int> ans(n + 1, -1);
    vector<int> cnt(10, -1);
    for(int i = n; i >= 1; --i) {
        cnt[qz[i]] = i;     
        if(cnt[qz[i - 1]] != -1) ans[i] = cnt[qz[i - 1]] - i + 1;  
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}