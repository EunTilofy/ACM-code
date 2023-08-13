#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll p;

ll add(ll x, ll y) {
    return (x + y) % p;
}
void Add(ll &x, ll y) {
    x = add(x, y);
}
ll mul(ll x, ll y) {
    return x * y % p;
}
void Mul(ll &x, ll y) {
    x = mul(x, y);
}
ll q_pow(ll x, ll y) {
    ll ans = 1;
    for(; y; y >>= 1) {
        if(y & 1) ans = ans * x % p;
        x = x * x % p;
    }
    return ans;
}

struct node {
    ll a[2][2];
} ;

node jz(node A, node B) {
    node res;
    for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) res.a[i][j] = 0;
    for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) for(int k = 0; k < 2; ++k) {
        Add(res.a[i][k], mul(A.a[i][j], B.a[j][k]));
    }
    return res;
}

node q_jz(node A, ll y) {
    node res;
    for(int i = 0; i < 2; ++i) for(int j = 0; j < 2; ++j) res.a[i][j] = (i == j);
    for(; y; y >>= 1) {
        if(y & 1) res = jz(res, A);
        A = jz(A, A);
    }
    return res;
}

int main() {
    freopen("zeroes.in", "r", stdin);
    freopen("zeroes.out", "w", stdout);
    ll k;
    cin >> k >> p;
    if(k <= 2) {
        if(k == 1) cout << 1 % p << "\n";
        else cout << 11 % p << "\n";
    } else {
        k--;
        ll ans = (k - 1) % p * q_pow(10, k) % p;
        // cerr << ans << "\n";
        node B, A;
        B.a[0][0] = 1, B.a[0][1] = 10;
        B.a[1][0] = 0, B.a[1][1] = 0;
        A.a[0][0] = 1, A.a[0][1] = 0;
        A.a[1][0] = 1, A.a[1][1] = 10;
        A = q_jz(A, k - 1);
        // cerr << A.a[0][0] << "!!\n";
        B = jz(B, A);
        ll pos = B.a[0][0];
        // cerr << pos << "\n";
        Add(ans, mul(8, ((pos - 11) % p + p) % p));
        ans = (ans + 90 + k) % p;
        cout << ans << "\n";
    }
    return 0;
}