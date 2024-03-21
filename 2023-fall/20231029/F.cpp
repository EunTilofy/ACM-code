#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MN = 1e6+5;

int a[MN], b[MN], c[MN], d[MN];

int get(int x) {
    if(x == 0) return 0;
    return 32-__builtin_clz(x);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    long long ans = 0;
    for(int i = 1; i <= 32; ++i) {
        long long len = (1ll<<i);
        int mi = 1000000000, fl = 0, no = 1;
        for(int j = 1; j <= n; ++j) {
            b[j] = get(a[j]%len);
            if(b[j] != 0) {
                fl = 1;
                if(a[j]>=len/2) {
                    c[j] = get((a[j]-len/2)%len);
                    if(c[j] != 0) no = 0;
                    else {
                        d[j] = 1 + (long long)(a[j]-len/2)/(len);
                        mi = min (d[j], mi);
                    }
                }
                else no = 0;
            }
        }
        ans += no*mi*fl;
        ans %= 998244353;
    }
    ans %= 998244353;
    cout << ans << "\n";
    return 0;
}