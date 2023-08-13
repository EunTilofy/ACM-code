#include<bits/stdc++.h>
using namespace std;

const int MN = 10005, MM = 105;
int n, w, h;

const int mod = 1000000007;
int Add(int x, int y){
    return (x+y)%mod;
}
int Mul(int x, int y){
    return 1ll * x * y % mod;
}
int f[MM][MN];

int main() {
    cin >> n >> w >> h;

    f[0][0] = 1;

    for(int i = 0; i < w; ++i)
    for(int j = 0; j <= n && j <= i * h; ++j) 
    if(f[i][j]) {
        for(int k = 0; k <= h && k + j <= n; ++k) {
            f[i+1][k+j]=Add(f[i+1][k+j], f[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; ++i) {
        ans = Add(ans, f[w][i]);
    }
    ans -= min(h+1, (n/w)+1);
    cout << ans << "\n";
    return 0;
}