#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if(a > (b + c)) {
        cout << "YES\n" << (2 * (b + c) + 1) * (b>0||c>0||a!=1) << "\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}