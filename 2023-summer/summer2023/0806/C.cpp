#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    ll sum1 = 0, sum2 = 0;
    for(int &x : a) {
        cin >> x;
        sum1 += x;
    }
    for(int &x : b) {
        cin >> x;
        sum2 += x;
    }
    cout << sum1 * sum2 << "\n";
    return 0;
}