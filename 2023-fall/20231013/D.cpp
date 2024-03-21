#include<bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
const int mod = 998244353;
int fpow(int x, int y) {
    int r = 1;
    for(;y;x=1ll*x*x%mod, y>>=1)if(y&1)r=1ll*r*x%mod;
    return r;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    vector<int> nm;
    for(auto &[l,r] : a) cin >> l >> r, nm.push_back(l), nm.push_back(r);
    sort(nm.begin(), nm.end());
    nm.erase(unique(nm.begin(), nm.end()), nm.end());
    for(auto &[l,r] : a)
        l=lower_bound(nm.begin(), nm.end(), l)-nm.begin()+1,
        r=lower_bound(nm.begin(), nm.end(), r)-nm.begin()+1;
    // for(auto &[l,r] : a) cout << l << " " << r << "\n";return 0;
    vector<int> b(2*n+1), c(2*n+1);
    for(auto [l,r] : a) ++b[l], ++c[r];
    for(int i = 1; i <= 2*n; ++i) c[i] = (c[i-1] + c[i]) % mod;
    for(int i = 2*n-1; i; --i) b[i] = (b[i+1] + b[i]) % mod;
    int ans = 0; int all = fpow(2, n);
    for(int i = 1; i <= n*2; ++i) {
        if(i==nm.size()) break;
        int len = nm[i] - nm[i-1];
        int _ = b[i + 1]+c[i];
        // cerr << i << " " << _ << " " << nm[i-1] << " " << nm[i] << "\n";
        ans = (ans + (1ll * len * (all + mod - fpow(2, _))) % mod) % mod;
    }
    cout << ans << "\n";
    return 0;
}