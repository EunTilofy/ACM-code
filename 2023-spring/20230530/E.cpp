#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;


unsigned long long check(unsigned long long n, unsigned long long m, unsigned long long k) {
    if(n % m == 0) return 0ull;
    unsigned long long nw = k, ret = 1ull;

    while(1) {
        __int128 l = n, r = n + 1;
        l *= nw; r *= nw; r -=1 ;
        if((r/m)*m<l) ++ret, nw *= k;
        else break;
    }
    // cerr << n << " " << m << " " << k << " " << ret << endl;
    return ret;
}

void solve() {
    unsigned long long n, k, m, a, b;
    cin >> n >> k >> m >> a >> b;
    if(k == 1) {
        if(n % m != 0) cout << -1 << endl;
        else cout << 0 << endl;
        return ;
    }
    unsigned long long ans = -1, now = 0; 
    while(n) {
        ans = min(ans, now + 1ull * a * check(n, m, k));
        n /= k;
        now += b;
    }
    cout << min(ans, now) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    cin >> n;
    while(n--) solve();
}