#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long double g;
    cin >> n >> g;
    vector<long double> a(n);
    long double sum = 0;
    for(auto &x : a) {
        cin >> x, sum += x * x;
    }
    long double F = 0, C = 0;
    for(int i = 1; i <= n; ++i) {
        long double f, c;
        cin >> f >> c;
        F += f;
        C += c;
    }
    long double l = g * sqrt(sum);
    if(1 > C) cout << "0.00000000";
    else {
        long double X = C / (l - F);
        if(X < 0) X = 0;
        cout << fixed << setprecision(15) << X; 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
        if(T) cout << "\n";
    }
}