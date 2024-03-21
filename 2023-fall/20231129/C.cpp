#include<bits/stdc++.h>
using namespace std;

long long solve() {
    unsigned long long p, M, ans = 0;
    cin >> p >> M;
    __int128_t l = 0, r, m = M, P = p;
    for(int i = 0; i <= 10; ++i) {
        if(((i*P+1)^(P-1)) <= m) ++ans, l = i;
    }
    if(ans) {
        __int128_t a = l, zero = l; ++l; r = (m/P)+10;
        while(l <= r) {
            __int128_t mid = (l + r) / 2;
            if(((mid*P+1)^(P-1))<=m) a = mid, l = mid + 1;
            else r = mid - 1;
        }
        ans += (a - zero);
        for(int k = -10; k <= 10; ++k) if(a + k > zero) {
            if(k <= 0 && (((a + k)*P+1)^(P-1)) > m) --ans;
            if(k > 0 && (((a + k)*P+1)^(P-1)) <=m) ++ans;
        }
        return ans;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) cout << solve() << "\n";
    return 0;
}
/*
3
2 0
7 11
1145141 998244353
*/