#include<bits/stdc++.h>
using namespace std;
#define double long double
const int N = 1e6 + 10;
const double eps = 1e-4;
typedef long long ll;
double f[110];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, K, q;
    ll sum = 0;
    cin >> n >> K >> q;  
    vector<ll> a(n), b(n);
    vector<ll> qz(n + 5);
    for(ll &x : a) cin >> x;
    b = a;
    sort(b.begin(), b.end());
    for(int i = 1; i <= n; ++i) {
        qz[i] = qz[i - 1] + b[i - 1];
    }
    for(ll x : b) sum += x;
    
    f[0] = 0;
    for(int i = 1; i <= K + 1; ++i) {
        //f[i], f[i - 1];
        int l = 0;
        ll pos = 0, tot = 0;
        double p = 1.0 / (1ll * n * (n - 1));
        for(int j = n - 1; j >= 0; --j) {
            for(; l < n && b[j] + b[l] < f[i - 1]; ) l++;
            ll num = n - l;
            tot += qz[n] - qz[l];
            if(l <= j) {
                tot -= b[j];
                num--;
            }
            // cout << j << " " << num << "\n";
            pos += num;
            tot += 1ll * num * b[j];
        }
        double tmp = pos * p;
        f[i] = p * tot + (1.0 - tmp) * f[i - 1];
        // cout << tot << " "<< pos << " " << f[i] << "ii\n";
    }
    cout << fixed << setprecision(12) << f[K + 1] << "\n";
    for(int o = 1, x, y, c; o <= q; ++o) {
        cin >> x >> y >> c;
        if(c==0){
            
            cout << "accept\n";
            continue;
        }
        x--, y--;
        double ans = a[x] + a[y], tmp = f[c];
        if(ans - tmp > eps) {
            cout << "accept\n";
        } else if(ans - tmp < -eps) {
            cout << "reselect\n";
        } else {
            cout << "both\n";
        }
    }
    return 0;
}