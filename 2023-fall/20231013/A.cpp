#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a+1,a+n+1);
    double x = min((a[1]+a[n])/2.0, (n>1)?(double)a[2]:(double)a[n]);
    cout << fixed << setprecision(1) << x << "\n";
    return 0;
}