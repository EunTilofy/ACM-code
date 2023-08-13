#include<bits/stdc++.h>
using namespace std;

long long suma, sumb, cnta, cntb, ida, idb, numa, numb;
int a[100005], b[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> num;
    for(int i = 1; i <= n; ++i) cin >> a[i], num.push_back({a[i], i*2+1});
    for(int j = 1; j <= m; ++j) cin >> b[j], num.push_back({b[j], j*2});

    // long long __ = 0;
    // for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) __ += abs(a[i] - b[j]) * (i - j);
    // cout << __ << endl;

    sort(num.begin(), num.end());
    long long ans = 0ll;

    for(auto &[x, id]: num) {
        int i = id/2;
        int _ = id%2;

        // cout << i << " "<< _ << endl;
        // cout << ans << endl;

        if(_) { // a
            ans += 1ll*i*a[i]*cntb;
            ans += sumb;
            ans -= 1ll*idb*a[i];
            ans -= 1ll * numb * i;

            suma += 1ll * i * a[i];
            cnta += 1;
            ida += i;
            numa += a[i];
        } else { // b
            ans -= 1ll*i*b[i]*cnta;
            ans -= suma;
            ans += 1ll*ida*b[i];
            ans += 1ll * numa * i;

            sumb += 1ll * i * b[i];
            cntb += 1;
            idb += i;
            numb += b[i];
        }
    }
    cout << ans << endl;
}