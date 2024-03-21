#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    set<pair<ll, int> > q;
    for(int i = 0; i < n; ++i) q.insert({a[i], i});
    ll sum = 0;
    int flg = 0;
    int cnt = 0;
    while(cnt <= n * 3) {
        ++cnt;
        auto[x, id] = *q.rbegin(); q.erase({x, id});
        ll y = x + sum;
        if(y < n - 1) {
            flg = 1; break;
        }
        ll tmp = y / (n - 1);
        sum += tmp;
        a[id] -= tmp * n;
        q.insert({a[id], id});
    }
    if(!flg) cout << "Recurrent\n";
    else {
        for(int i = 0; i < n; ++i) cout << a[i] + sum << " \n"[i == n - 1];
    }
    return 0;
}