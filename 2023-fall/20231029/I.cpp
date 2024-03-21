#include<bits/stdc++.h>
using namespace std;

int f[106];

long long cal(int x) {
    long long ans = 0;
    for(int i = 1; i <= x; ++i) for(int j = 1; j < i; ++j) {
        int g = gcd(i, j);
        ans += f[i/g] + f[j/g];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i <= 100; ++i) {
        f[i] = i;
        for(int j = 2; j < i; ++j) if(i%j==0) {
            f[i] = f[i/j] + j;
            break;
        }
    }

    for(int i=1; i<=100; ++i) {
        cout << cal(i) << " ";
    }
    return 0;
}