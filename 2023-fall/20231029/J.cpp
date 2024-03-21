#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    a = a*2ll;
    b = 360ll*b;
    long long ret = b/gcd(b, a) - 1;
    cout << ret << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) solve();
}