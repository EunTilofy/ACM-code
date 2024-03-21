#include<bits/stdc++.h>
#define ll long long
using namespace std;

void check(int n, int tot) {
    vector<int> a;
    a.push_back(n);
    int now = 0;
    for(int i = 0; now < tot; ++i) {
        int pos = min(tot - now, a[i] - 1);
        a[i] -= pos;
        now += pos;
        a.push_back(pos);
    }
    cout << n << " " << n - 1 << "\n";
    vector<int> f(n + 1, 0);
    int last = 0, cnt = 0;
    for(int x : a) {
        for(int i = 1; i <= x; ++i) {
            ++cnt;
            if(last) {
                f[cnt] = f[last] + 1;
                cout << last << " " << cnt << "\n";
            }
        }
        last = cnt;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) ans += f[i];
    assert(ans == tot);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int a = 0, b = 0, flg = 1;
    for(auto ch : s) {
        if(ch >= '0' && ch <= '9') {
            if(flg) a = a * 10 + (ch - '0');
            else b = b * 10 + (ch - '0');
        }
        else flg ^= 1;
    }
    for (int n = b, len = a; n <= 1000000; n += b, len += a) {
        ll L = n - 1, R = 1ll * n * (n - 1) / 2;
        if(L <= len && len <= R) {
            check(n, len);
            return 0;
        }
    }
    cout << "impossible\n";
    return 0;
}