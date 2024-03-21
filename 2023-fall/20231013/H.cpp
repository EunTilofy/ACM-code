#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, k, d;
        cin >> n >> k >> d;
        long double x = (long double)n / (2.0*sqrt(2.0)*(long double)(k-1)+2.0);
        x = (long double)d/x/x;
        cout << fixed << setprecision(6) << x << "\n";
    }
    return 0;
}