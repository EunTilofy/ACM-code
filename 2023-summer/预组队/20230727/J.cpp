#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int Mul(int x, int y) {
    return (1ll * x * y) % mod;
}
int Add(int x, int y) {
    return (x + y) % mod;
}
int inv[5];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 1;
    int n;
    cin >> n;
    for(int i = 1; i <= n-2; ++i) ans = Mul(ans, i);
    inv[0]=inv[1]=1;
    for(int i = 2; i <= 4; ++i) inv[i] = Mul(inv[mod%i], (mod-mod/i));
    inv[2]=Mul(inv[1], inv[2]); inv[3]=Mul(inv[2],inv[3]);
    int all = 0;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        all += x;
        ans = Mul(ans, inv[x-1]);
    }
    if(all != 2 * n - 2) ans = 0;
    cout << ans << "\n";
    return 0;
}
