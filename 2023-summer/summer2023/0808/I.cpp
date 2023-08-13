#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int x, y;
        cin >> x >> y;
        cout << x - y + 1 << "\n";
    }
    return 0;
}