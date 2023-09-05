#include<bits/stdc++.h>
using namespace std;
#define int long long
int cal(int l, int r, int p) {
    int ans = 0;
    if(r < l) return 0;
    // if(r < l * p + 1) return (r - l + 1);
    vector<pair<int, int>> a;
    int _ = p;
    for(int x = l*p + 1; x <= r; x = (x+1)*p + 1) {
        a.push_back({x, _});
        _ *= p;
    }
    std::reverse(a.begin(), a.end());
    int now = 0;
    for(auto [x, step] : a) {
        if((r - x) % step == 0) {
            return (r - x) / step - now;
        }
        else {
            now = (r - x) / step + 1;
        }
    }
    return (r - l + 1 - now);
        // else {
            // if(r == l * p + 1) ans ^= 0;
            // else if(r < l * p + 1) ans ^= (r - l + 1);
            // else {
            //     if((r - (l * p + 1)) % p == 0) {
            //         ans ^= (r - (l * p + 1)) / p;
            //     }
            //     else {
            //         ans ^= (r - l) - (r - (l * p + 1)) / p;
            //     }
            // }
        // }
    return ans;
}
void solve() {
    int n, p;
    cin >> n >> p;
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        int l, r;
        cin >> l >> r;
        ans ^= cal(l, r, p);
    }
    if(ans) cout << "First" << endl;
    else cout << "Second" << endl;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    // freopen("tb2.txt", "w" ,stdout);
    // for(int i = 1; i <= 3; ++i) for(int j = i; j <= 1000; ++j) {
    //     // cerr << i << " " << j << endl;
    //     cout << "sg[" << i << "][" << j << "] = " << cal(i, j, 3) << endl;
    // }
    int T;
    cin >> T;
    while(T--) solve();
	return 0;
}