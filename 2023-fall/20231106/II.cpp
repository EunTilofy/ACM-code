#include<bits/stdc++.h>
using namespace std;
int f[55][55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    f[0][0] = 1;
    for(int i = 1; i <= 50; ++i) {
        for(int j = ; j >= 0; --j) {
            f[i][j] = f[i - 1][j];
            if(j >= i) f[i][j] += f[i - 1][j - i];
        }
    }
    for(int i = 0; i <= 50; ++i) {
        cout << f[50][i] << "\n";
    }
    return 0;
}