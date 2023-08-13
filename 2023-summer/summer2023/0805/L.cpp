#include<bits/stdc++.h>
using namespace std;

//Grundy
//Sprague

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    if(n == 1) {
        cout << "Sprague\n";
    }
    else if(n % 3 == 0 && a[n-1] > 1 && a[n - 2] == 1) {
        cout << "Sprague\n";
    }
    else if(n % 3 == 1 && a[n-2] == 1) {
        cout << "Sprague\n";
    }
    // else if(n>2 && a[n-2] == 1 && a[n-1] > 1) {
    //     cout << "Sprague\n";
    // }
    else {
        cout << "Grundy\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}