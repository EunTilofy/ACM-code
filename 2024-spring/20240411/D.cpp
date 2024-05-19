#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

namespace sh {
    const int N = 2e6 + 5;
    const ll p1 = 1e9 + 7, p2 = 998244353;
    struct pa {
        ll v1, v2;
        pa(ll v = 0) : v1(v), v2(v) {}
        pa(ll v1, ll v2) :v1(v1), v2(v2) {}
        pa operator * (const pa &o) const { return {v1 * o.v1 % p1, v2 * o.v2 % p2}; }
        pa operator + (const pa &o) const { return {(v1 + o.v1) % p1, (v2 + o.v2) % p2}; }
        bool operator == (const pa&o) const {
            return v1 == o.v1 && v2 == o.v2;
        }
    };
    pa fma(const pa &a, const pa &b, const pa &c) { return {(a.v1 * b.v1 + c.v1) % p1, (a.v2 * b.v2 + c.v2) % p2};}
    const pa b = {400000009, 400000043};
    pa m[N];
    void init() {
        m[0] = {p1 - 1, p2 - 1};
        for(int i = 1; i < N; ++i) m[i] = m[i - 1] * b;
    }
    int i = (init(), 0);
    struct str {
        int n;
        vector<pa> a;
        vector<ll> s;
        str(const vector<ll> &_): n(_.size()), a(n + 1), s(n) {
            a[0] = {0, 0};
            for(i = 0; i < n; ++i) a[i + 1] = fma(a[i], b, s[i] = _[i]);
        }      
        pa getv(int l, int r) {
            r++;
            return fma(a[l], m[r - l], a[r]);
        }
    };
};
using sh::pa;
using sh::str;

int zh(char ch) {
    if(ch >= '0' && ch <= '9') return ch - '0';
    if(ch >= 'a' && ch <= 'z') return 10 + ch - 'a';
    if(ch >= 'A' && ch <= 'Z') return 36 + ch - 'A';
    assert(0);
}

ll get() {
    string s; cin >> s;
    ll x = 0;
    for(auto ch : s) x = x * 62 + zh(ch);
    return x;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    sh::init();
    vector<ll> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) {
        a[i] = get();
        b[i] = a[i] * 2;
    }
    str S(a);
    str T(b);
    vector<int> qz(n + 5);
    // auto [x, y]  = (S.getv(1, 1) + S.getv(9, 9));
    // cout << x << " " << y << "!\n";
    for(int i = 1; i <= n / 2; ++i) {
        int l = 1, r = n - 2 * i, ans = -1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            // [1, mid] + [1 + 2 * i, mid + 2 * i]
            // [1 + i, mid + i] * 2
            if(S.getv(1, mid) + S.getv(1 + 2 * i, mid + 2 * i) == T.getv(1 + i, mid + i)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        if(ans != -1) {
            // cout << i << " " << ans << "\n";
            qz[1 + 2 * i]++, qz[ans + 2 * i + 1]--;
        }
    }
    for(int i = 1; i <= n; ++i) qz[i] += qz[i - 1];
    for(int i = 1; i <= n; ++i) cout << (qz[i] ? "1" : "0");
    cout << "\n";
    return 0;
}