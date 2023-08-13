#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int f[N][N];

void solve() {
    int a;
    cin >> a;
    for(int j = 1; j <= a; ++j) f[1][j] = 1;
    for(int i = 2; i <= 10; ++i) {
        for(int j = 1; j <= a; ++j) {
            f[i][j] = 0;
            if(j + 1 <= a) f[i][j] += f[i - 1][j + 1];
            if(j > 1) f[i][j] += f[i][j - 1];
        }
    }
    for(int i = 1; i <= 10; ++i) {
        for(int j = 1; j <= a; ++j) {
            cout << f[i][j] << " ";
        }
        cout << "!" << f[i][a] - f[i - 1][a];
        cout << "\n";
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
}