#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

map<ll, int> find(vector<ll> a) {
    map<ll, int> mp;
    int n = a.size();
    for(int i = 0; i < (1 << n); ++i) {
        ll pos = 0;
        for(int j = 0; j < n; ++j) if((i >> j) & 1) {
            pos |= a[j];
        }
        mp[pos] = 1;
    }
    return mp;
}

const int MN = 1 << 20;
int len = MN;

void FWT_or(ll *a, int m) {
    for(int k = 1; k < len; k <<= 1) {
        for(int i = 0; i < len; i += k << 1) {
            for(int j = 0; j < k; ++j) 
                a[i + j + k] = ~m ? a[i + j + k] + a[i + j] : a[i + j + k] - a[i + j];
        }
    }
}

ll A[MN], B[MN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll inf = (1ll << 40) - 1;
    vector<ll> a(40, 0);
    for(int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        for(int j = 40; j >= 0; --j) if((x >> j) & 1) {
            if(a[j]) a[j] &= x;
            else a[j] = x;
        }
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    // for(ll x : a) cerr << x << "a\n";
    vector<ll> b, c;
    int sz = a.size();
    for(int i = 0; i < sz / 2; ++i) b.push_back(a[i]);
    for(int i = sz / 2; i < sz; ++i) c.push_back(a[i]);
    ll pos = (1ll << 20) - 1;
    map<ll, int> mp1 = find(b), mp2 = find(c);
    for(auto [x, y] : mp1) {
        // cerr << x << " " << y << "\n";
        B[x & pos] += y;
    }
    for(auto [x, y] : mp2) {
        // cerr << x << " " << y << "\n";
        A[x & pos] += y;
    } 
    ll ans = 0;
    FWT_or(A, 1);
    FWT_or(B, 1);
    for(int i = 0; i < MN; ++i) A[i] *= B[i];
    FWT_or(A, -1);
    for(int i = 0; i < MN; ++i) ans += (A[i] >= 1);
    cout << ans << "\n";
    return 0;
}