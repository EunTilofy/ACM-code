#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), id(n), b(n);
    for(int i = 1; i <= n; ++i) cin >> a[i-1], id[i-1] = i - 1;
    sort(id.begin(), id.end(), [&](int x, int y) -> bool{return a[x] < a[y];});
    {
        // chk
        int va = a[id[0]] + a[id[n-1]];
        for(int i = 0; i < n; ++i) {
            if(va != a[id[i]] + a[id[n-1-i]]) {
                cout << -1 << "\n";
                exit(0);
            }
            b[id[i]] = id[n-1-i];
        }
    }
    for(int i = 0; i < n; ++i) cout << b[i] + 1 << " ";
}