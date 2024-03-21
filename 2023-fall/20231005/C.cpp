#include<bits/stdc++.h>
using namespace std;

long long n;
double eps = 1e-11;
int main() {
    cin >> n;
    n = (n + 4) / 4;
    long double l = 0, r =  70000;
    // long double l = 4.95, r = 5.05;
    while(r - l >= eps) {
        long double mid = (l + r) / 2.0;
        long long num = 0;
        for(int i = 1; i <= 70000; ++i) {
            long long _ = (long long)(mid*mid)-(long long)(i*i);
            if(_ <= 0) break;
            long long ans = (long long)sqrt(_);
            // cerr << "_= " << _ << " " << ans << "\n";
            num += ans;
            if(ans == 0) break;
        }
        // cerr << mid << " " << num << "\n";
        if(num >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(10) << (r+l)/2;
    return 0;
}