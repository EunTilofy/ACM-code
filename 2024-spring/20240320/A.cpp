#include<bits/stdc++.h>
using namespace std;

int b[66][66];

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> b[i][j];
        }
    }
    vector<int> a;
    for(int i = 1; i <= n; ++i) {
        if(i & 1) {
            for(int j = 1; j <= n; ++j) 
                a.push_back(b[i][j]);
        }
        else {
            for(int j = n; j; --j) a.push_back(b[i][j]);
        }
    }
    int num = 0;
    for(int i = 1; i < a.size(); ++i) num += a[i] > a[i-1];
    if(num*2 > a.size() - 1) reverse(a.begin(), a.end());
    for(int i = 0; i < a.size(); ++i) cout << a[i] << " \n"[i == a.size() - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}