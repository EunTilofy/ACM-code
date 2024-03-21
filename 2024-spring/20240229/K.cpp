#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


const int MN = 5e5+5;
ll a[MN], b[MN], r[MN];
bool ua[MN], ub[MN];
int getr(int i) {
    if(r[i] == i) return i;
    return r[i] = getr(r[i]);
}

void solve() {
    int m;
    cin >> m;
    long long _1 = 0, _2 = 0;
    for(int i = 0; i < m; ++i) cin >> a[i], ua[i] = 0, _1 += a[i];
    for(int i = 0; i < m; ++i) cin >> b[i], ub[i] = 0, _2 += b[i];
    // cal num9
    long long num9 = 0, num10 = 0;
    int cal = 0;
    if(_1 < _2) a[0] += _2 - _1;
    if(_2 < _1) b[0] += _1 - _2;

    for(int i = 0; i < m; ++i) {
        ll cc = min(a[i], b[m-1-i]);
        num9 += cc;
        a[i] -= cc;
        b[m-1-i] -= cc;
        if(cc) ua[i] = ub[m-1-i] = 1, ++cal;
    }

    for(int i = 0; i < m; ++i) r[i] = i;
    for(int i = m-1; i; --i) {
        int j = m-i; j = getr(j);
        while(j < m) {
            // cout << i << " " << j << " " << num10 << "\n";
            ll cc = min(a[i], b[j]);
            num10 += cc;
            a[i] -= cc;
            b[j] -= cc;
            if(b[j] > 0) break;
            if(j == m-1) break;
            r[j] = getr(j+1);
            j = r[j];
        }
    }

    // cout << num9 << " " << num10 << " ";
    if(num10 == 0) {
        bool fl = 0, aa = 0, bb = 0;
        for(int i = 0; i < m; ++i) {
            if(aa && a[i]) {fl = 1; break;}
            if(bb && b[i]) {fl = 1; break;}
            aa |= ua[i];
            bb |= ub[i];
        }
        if(fl) cout << num9 << "\n";
        else cout << max(0ll, (cal < 2 ? 0 : num9 - 1)) << "\n";
    } else {
        cout << num9 + num10 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}


/*
5
2
1 2
3 4
3
1 0 1
0 1 0
4
1 0 0 1
1 1 1 1
5
123456 114514 1919810 233333 234567
20050815 998244353 0 0 0
10
5 3 5 3 2 4 2 4 1 5
9 9 8 2 4 4 3 5 3 0
*/

/*
5
1
2
467900
29
*/