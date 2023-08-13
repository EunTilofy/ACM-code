#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,m,x,y,t;
    cin >> n >> t >> m >> x >> y;
    long long tt = (m * y + (n - m) * x - 60ll * x * y * t + 60ll * x * y - 1) / (60ll * x * y);
    tt = max(tt, 0ll);
    cout << tt;
    return 0;
}